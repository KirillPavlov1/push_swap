#include "push.h"

void	rb(t_b **b)
{
	if (*b)
		(*b) = (*b)->next;
}

void	ra(t_a **a)
{
	if (*a)
		(*a) = (*a)->next;
}

void	rr(t_a **a, t_b **b)
{
	if (*a)
		(*a) = (*a)->next;
	if (*b)
		(*b) = (*b)->next;
}
