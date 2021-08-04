#include "push.h"

void	sa(t_a **a)
{
	int	first;
	int	second;

	if (a_size(*a) < 2)
		return ;
	first = (*a)->n;
	second = (*a)->next->n;
	(*a)->n = second;
	(*a)->next->n = first;
}

void	sb(t_b **b)
{
	int	first;
	int	second;

	if (b_size(*b) < 2)
		return ;
	first = (*b)->n;
	second = (*b)->next->n;
	(*b)->n = second;
	(*b)->next->n = first;
}

void	ss(t_a **a, t_b **b)
{
	sa(a);
	sb(b);
}

void	pb(t_b **lst, t_b *new)
{
	t_b	*p;
	t_b	*begin;

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
	t_a	*p;
	t_a	*begin;

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
