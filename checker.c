#include "push.h"
#include "get_next_line/get_next_line.h"

t_set	*ft_setnew(char *line)
{
	t_set *new;

	if (!(new = malloc(sizeof(t_set))))
		return (NULL);
	new->c = ft_strdup(line);
	new->next = NULL;
	return (new);
}

void	ft_setadd_back(t_set **lst, t_set *new)
{
	t_set *p;

	if (lst == NULL)
		return ;
	p = *lst;
	if (p == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}

void execute_c(t_set *com, t_a **a, t_b **b)
{
	while (com)
	{
		if (!ft_strcmp(com->c, "rrr"))
			rrr(a, b);
		if (!ft_strcmp(com->c, "rra"))
			rra(a);
		if (!ft_strcmp(com->c, "rrb"))
			rrb(b);
		if (!ft_strcmp(com->c, "rr"))
			rr(a, b);
		if (!ft_strcmp(com->c, "ra"))
			ra(a);
		if (!ft_strcmp(com->c, "rb"))
			rb(b);
		if (!ft_strcmp(com->c, "sa"))
			sa(a);
		if (!ft_strcmp(com->c, "sb"))
			sb(b);
		if (!ft_strcmp(com->c, "ss"))
			ss(a, b);
		if (!ft_strcmp(com->c, "pa"))	
			pa(a, ft_anew_n((*b)->n));
		if (!ft_strcmp(com->c, "pb"))	
			pb(b, ft_bnew_n((*a)->n));
		com = com->next;
	}
}

int first_lasta(t_a *a)
{
	int i;
	t_a *begin;

	i = 0;
	begin = a;
	while(a->next != begin)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	int		i;
	t_b		*b;
    t_a		*a;
	t_set	*c;
	char	*line;

	i = -1;
	if (argc < 3)	
		return (0);
    if (!(check_argv(argc, argv)))
    {
        write(1, "Error\n", 6);
        return (0);
    }
	while(++i < argc)
        ft_adda_back(&a, ft_anew(argv[i]));
	while(get_next_line(1, &line))
	{
		ft_setadd_back(&c, ft_setnew(line));
		free(line);
	}
	execute_c(c, &a, &b);
	if (first_lasta(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}