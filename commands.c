#include "push.h"

void rrb(t_b **b)
{
    t_b *begin;

    begin = *b;
    while((*b)->next != begin)
        (*b) = (*b)->next;
}

void rra(t_a **a)
{
    t_a *begin;

    begin = *a;
    while((*a)->next != begin)
        (*a) = (*a)->next;
}

void rrr(t_a **a, t_b **b)
{
    t_a *begin_a;
    t_b *begin_b;

	begin_a = *a;
	begin_b = *b;
    while((*a)->next != begin_a)
        (*a) = (*a)->next;
    while((*b)->next != begin_b)
        (*b) = (*b)->next;
}

void rb(t_b **b)
{
    (*b) = (*b)->next;
}

void ra(t_a **a)
{
    (*a) = (*a)->next;
}

void rr(t_a **a, t_b **b)
{
    (*a) = (*a)->next;
    (*b) = (*b)->next;
}

void sa(t_a **a)
{
    int first;
    int second;

	if (a_size(*a) < 2)
		return ;
    first = (*a)->n;
    second = (*a)->next->n;
    (*a)->n = second;
    (*a)->next->n = first;
}

void sb(t_b **b)
{
    int first;
    int second;

	if (b_size(*b) < 2)
		return ;
    first = (*b)->n;
    second = (*b)->next->n;
    (*b)->n = second;
    (*b)->next->n = first;
}

void ss(t_a **a, t_b **b)
{
    sa(a);
    sb(b);
}

void	pb(t_b **lst, t_b *new)
{
	t_b *p;
	t_b *begin;

	if (lst == NULL)
		return ;
	p = *lst;
	begin = *lst;
	if (p == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != begin)
	{
		p = p->next;
	}
	p->next = new;
	new->past = p;
	new->next = begin;
	begin->past = new;
	*lst = new;
}

void	pa(t_a **lst, t_a *new)
{
	t_a *p;
	t_a *begin;

	if (lst == NULL)
		return ;
	p = *lst;
	begin = *lst;
	if (p == NULL)
	{
		*lst = new;
		return ;
	}
	while (p->next != begin)
	{
		p = p->next;
	}
	p->next = new;
	new->past = p;
	new->next = begin;
	begin->past = new;
	*lst = new;
}

int count_sum(t_b **b)
{
	int a;
	int a2;

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

void move_stacks2(t_a **a, t_b **b, int min)
{
	int i;

	i = 0;
	while((*b)->sum != min)
		(*b) = (*b)->next;
	if((*b)->down_a > (*b)->up_a)
	{
		i = (*b)->up_a;
		while(i--)
			ra(a);
	}
	else
	{
		i = (*b)->down_a;
		while(i--)
			rra(a);
	}
}

void move_stacks(t_a **a, t_b **b)
{
	t_b *begin_b;
	int min;
	int c;

	begin_b = *b;
	min = 2147483647;
	while((*b)->next != begin_b)
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