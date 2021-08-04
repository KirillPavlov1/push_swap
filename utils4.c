#include "push.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i] != '\0' && str2[i] != '\0')
		i++;
	return (str1[i] - str2[i]);
}

void	sort_mina(t_a **a)
{
	t_a	*a1;
	int	min;

	a1 = *a;
	min = 2147483647;
	while ((*a)->next != a1)
	{
		if (min > (*a)->n)
			min = (*a)->n;
		(*a) = (*a)->next;
	}
	if (min > (*a)->n)
		min = (*a)->n;
	*a = a1;
	while ((*a)->n != min)
		(*a) = (*a)->next;
	sort_mina2(a);
}

void	remove_a(t_a **a)
{
	t_a	*begin;

	begin = *a;
	while ((*a)->next != begin)
	{
		(*a) = (*a)->next;
	}
	if ((*a)->next == *a && (*a)->past == *a)
	{
		free(*a);
		*a = NULL;
	}
	else
	{
		(*a)->next = begin->next;
		begin->next->past = (*a)->next;
		(*a) = begin->next;
		free(begin);
	}
}

int	first_last(char *argv[], int argc)
{
	int	i;

	i = 0;
	while (++i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
	}
	return (1);
}

void	sort_mina2(t_a **a)
{
	int	i;

	if ((*a)->up > (*a)->down)
		i = (*a)->down;
	else
		i = (*a)->up;
	if ((*a)->up > (*a)->down)
	{
		while (i--)
		{
			rra(a);
			write(1, "rra\n", 4);
		}
	}
	else
	{
		while (i--)
		{
			ra(a);
			write(1, "ra\n", 3);
		}
	}
}
