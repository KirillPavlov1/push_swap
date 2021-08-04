#include "push.h"
#include "get_next_line/get_next_line.h"

static int	execute_c2(t_set *com, t_a **a, t_b **b)
{
	if (!ft_strcmp(com->c, "pa"))
	{
		if (b_size(*b) > 0)
		{
			pa(a, ft_anew_n((*b)->n));
			remove_b(b);
		}
	}
	else if (!ft_strcmp(com->c, "pb"))
	{
		if (a_size(*a) > 0)
		{
			pb(b, ft_bnew_n((*a)->n));
			remove_a(a);
		}
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	execute_c(t_set *com, t_a **a, t_b **b)
{
	while (com)
	{
		if (!ft_strcmp(com->c, "rrr"))
			rrr(a, b);
		else if (!ft_strcmp(com->c, "rra"))
			rra(a);
		else if (!ft_strcmp(com->c, "rrb"))
			rrb(b);
		else if (!ft_strcmp(com->c, "rr"))
			rr(a, b);
		else if (!ft_strcmp(com->c, "ra"))
			ra(a);
		else if (!ft_strcmp(com->c, "rb"))
			rb(b);
		else if (!ft_strcmp(com->c, "sa"))
			sa(a);
		else if (!ft_strcmp(com->c, "sb"))
			sb(b);
		else if (!ft_strcmp(com->c, "ss"))
			ss(a, b);
		else if (!execute_c2(com, a, b))
			return (0);
		com = com->next;
	}
	return (1);
}

int	first_lasta(t_a *a, t_b *b)
{
	int	i;
	t_a	*begin;

	i = 0;
	begin = a;
	while (a->next != begin)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	if (b)
		return (0);
	return (1);
}

static void	main2(int argc, char **argv, t_a **a, t_set **c)
{
	int		i;
	char	*line;

	i = 0;
	while (++i < argc)
		ft_adda_back(a, ft_anew(argv[i]));
	while (get_next_line(1, &line))
	{
		ft_setadd_back(c, ft_setnew(line));
		free(line);
	}
	if (ft_strcmp(line, ""))
		ft_setadd_back(c, ft_setnew(line));
	free(line);
}

int	main(int argc, char **argv)
{
	t_b		*b;
	t_a		*a;
	t_set	*c;

	if (argc < 3)
		return (0);
	if (!(check_argv(argc, argv)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	main2(argc, argv, &a, &c);
	if (!(execute_c(c, &a, &b)))
		return (0);
	if (first_lasta(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
