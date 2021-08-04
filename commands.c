#include "push.h"

void	rrb(t_b **b)
{
	t_b	*begin;

	if (*b == NULL)
		return ;
	begin = *b;
	while ((*b)->next != begin)
		(*b) = (*b)->next;
}

void	rra(t_a **a)
{
	t_a	*begin;

	if (*a == NULL)
		return ;
	begin = *a;
	while ((*a)->next != begin)
		(*a) = (*a)->next;
}

void	rrr(t_a **a, t_b **b)
{
	t_a	*begin_a;
	t_b	*begin_b;

	begin_a = *a;
	begin_b = *b;
	if (*a)
	{
		while ((*a)->next != begin_a)
			(*a) = (*a)->next;
	}
	if (*b)
	{
		while ((*b)->next != begin_b)
			(*b) = (*b)->next;
	}
}
