#include "push.h"

int	is_biggest(t_a **a, int n, int m)
{
	t_a	*a1;
	int	max;

	max = -2147483648;
	a1 = *a;
	while ((*a)->next != a1)
	{
		if ((*a)->n > max)
			max = (*a)->n;
		(*a) = (*a)->next;
	}
	if ((*a)->n > max)
		max = (*a)->n;
	(*a) = a1;
	if (n > max && m == max)
		return (1);
	return (0);
}

void	sort_a(t_a **a)
{
	int	k;

	k = 0;
	if ((*a)->n < (*a)->next->n && (*a)->next->n > (*a)->next->next->n
		&& (*a)->n < (*a)->next->next->n)
		k = 1;
	if ((*a)->n > (*a)->next->n && (*a)->next->n < (*a)->next->next->n
		&& (*a)->n < (*a)->next->next->n)
		k = 2;
	if ((*a)->n > (*a)->next->n && (*a)->next->n > (*a)->next->next->n)
		k = 3;
	if (k == 1 || k == 2 || k == 3)
	{
		sa(a);
		write(1, "sa\n", 3);
	}
}

void	remove_b(t_b **b)
{
	t_b	*begin;

	begin = *b;
	while ((*b)->next != begin)
	{
		(*b) = (*b)->next;
	}
	if ((*b)->next == *b && (*b)->past == *b)
	{
		free(*b);
		*b = NULL;
	}
	else
	{
		(*b)->next = begin->next;
		begin->next->past = (*b)->next;
		(*b) = begin->next;
		free(begin);
	}
}

void	cleaner(t_b **b)
{
	t_b	*b1;

	b1 = *b;
	while ((*b)->next != b1)
	{
		(*b)->up = 0;
		(*b)->down = 0;
		(*b)->down_a = 0;
		(*b)->up_a = 0;
		(*b)->sum = 0;
		(*b) = (*b)->next;
	}
	(*b)->up = 0;
	(*b)->down = 0;
	(*b)->down_a = 0;
	(*b)->up_a = 0;
	(*b)->sum = 0;
	(*b) = b1;
}
