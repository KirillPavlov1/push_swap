#include "push.h"

int	count_sum(t_b **b)
{
	int	a;
	int	a2;

	a = 0;
	a2 = 0;
	if ((*b)->down_a > (*b)->up_a)
		a = (*b)->up_a;
	else
		a = (*b)->down_a;
	if ((*b)->down > (*b)->up)
		a2 = (*b)->up;
	else
		a2 = (*b)->down;
	(*b)->sum = a + a2;
	return (a + a2);
}

void	move_stacks2(t_a **a, t_b **b, int min)
{
	int	i;

	i = 0;
	while ((*b)->sum != min)
		(*b) = (*b)->next;
	if ((*b)->down_a > (*b)->up_a)
	{
		i = (*b)->up_a;
		while (i--)
			ra(a);
	}
	else
	{
		i = (*b)->down_a;
		while (i--)
			rra(a);
	}
}

void	move_stacks(t_a **a, t_b **b)
{
	t_b	*begin_b;
	int	min;
	int	c;

	begin_b = *b;
	min = 2147483647;
	while ((*b)->next != begin_b)
	{
		c = count_sum(b);
		if (c < min)
			min = c;
		(*b) = (*b)->next;
	}
	c = count_sum(b);
	if (c < min)
		min = c;
	(*b) = begin_b;
	move_stacks2(a, b, min);
}

void	counter_b(t_b **b)
{
	t_b	*b1;
	int	i;

	b1 = *b;
	i = 0;
	while ((*b)->next != b1)
	{
		(*b)->up = i;
		i++;
		*b = (*b)->next;
	}
	(*b)->up = i;
	*b = b1;
	i++;
	while ((*b)->next != b1)
	{
		(*b)->down = i;
		i--;
		*b = (*b)->next;
	}
	(*b)->down = i;
	*b = b1;
}

void	counter_a2(t_a **b)
{
	t_a	*b1;
	int	i;

	b1 = *b;
	i = 0;
	while ((*b)->next != b1)
	{
		(*b)->up = i;
		i++;
		*b = (*b)->next;
	}
	(*b)->up = i;
	*b = b1;
	i++;
	while ((*b)->next != b1)
	{
		(*b)->down = i;
		i--;
		*b = (*b)->next;
	}
	(*b)->down = i;
	*b = b1;
}
