#include "push.h"

void	counter_aa(t_a **a, t_b **b, t_a *a1, int *num)
{
	while ((*a)->next != a1)
	{
		if ((*num > (*a)->n && (*a)->n > (*b)->n)
			|| is_biggest(a, (*b)->n, (*a)->n))
			*num = (*a)->n;
		(*a) = (*a)->next;
	}
	if ((*num > (*a)->n && (*a)->n > (*b)->n)
		|| is_biggest(a, (*b)->n, (*a)->n))
		*num = (*a)->n;
	(*a) = a1;
	while ((*a)->n != *num)
	{
		ra(a);
		(*b)->up_a++;
	}
}

void	counter_aaa(t_a **a, t_b **b, t_a *a1, int *num)
{
	if ((*b)->n > *num)
	{
		ra(a);
		(*b)->up_a++;
	}
	(*a) = a1;
	while ((*a)->n != *num)
	{
		rra(a);
		(*b)->down_a++;
	}
	if ((*b)->n > *num)
	{	
		ra(a);
		(*b)->down_a--;
	}
	if ((*b)->down_a == -1)
		(*b)->down_a = (*b)->up_a + 1;
	(*a) = a1;
	(*b) = (*b)->next;
	*num = 2147483647;
}

void	counter_aaaa(t_a **a, t_b **b, t_a *a1, int *num)
{
	while ((*a)->next != a1)
	{
		if ((*num > (*a)->n && (*a)->n > (*b)->n)
			|| is_biggest(a, (*b)->n, (*a)->n))
			*num = (*a)->n;
		(*a) = (*a)->next;
	}
	if ((*num > (*a)->n && (*a)->n > (*b)->n)
		|| is_biggest(a, (*b)->n, (*a)->n))
		*num = (*a)->n;
	(*a) = a1;
	while ((*a)->n != *num)
	{
		ra(a);
		(*b)->up_a++;
	}
	if ((*b)->n > *num)
	{
		ra(a);
		(*b)->up_a++;
	}
}

void	counter_aaaaa(t_a **a, t_b **b, t_a *a1, int *num)
{
	(*a) = a1;
	(*a) = a1;
	while ((*a)->n != *num)
	{
		rra(a);
		(*b)->down_a++;
	}
	if ((*b)->n > *num)
	{
		ra(a);
		(*b)->down_a--;
	}
	if ((*b)->down_a == -1)
		(*b)->down_a = (*b)->up_a + 1;
	(*a) = a1;
	(*b) = (*b)->next;
	*num = 2147483647;
}

void	counter_a(t_a **a, t_b **b)
{
	int	num;
	t_b	*b1;
	t_a	*a1;

	b1 = *b;
	a1 = *a;
	num = 2147483647;
	while ((*b)->next != b1)
	{
		counter_aa(a, b, a1, &num);
		counter_aaa(a, b, a1, &num);
	}
	counter_aaaa(a, b, a1, &num);
	counter_aaaaa(a, b, a1, &num);
	(*b) = b1;
}
