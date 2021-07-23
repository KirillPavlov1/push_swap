/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:17:29 by kirill            #+#    #+#             */
/*   Updated: 2020/11/17 21:13:31 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_b	*ft_bnew(void *content)
{
	t_b *new;

	if (!(new = malloc(sizeof(t_b))))
		return (NULL);
	new->past = new;
	new->next = new;
	new->up_a = 0;
	new->down_a = 0;
	new->up = 0;
	new->down = 0;
	new->n = ft_atoi(content);
	return (new);
}

t_a	*ft_anew(void *content)
{
	t_a *new;

	if (!(new = malloc(sizeof(t_a))))
		return (NULL);
	new->past = new;
	new->next = new;
	new->up = 0;
	new->down = 0;
	new->n = ft_atoi(content);
	return (new);
}

t_a	*ft_anew_n(int n)
{
	t_a *new;

	if (!(new = malloc(sizeof(t_a))))
		return (NULL);
	new->past = new;
	new->next = new;
	new->n = n;
	return (new);
}

void	ft_adda_back(t_a **lst, t_a *new)
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
}

int	b_size(t_b *b)
{
	int count;
	t_b	*b1;

	b1 = b;
	if (b == NULL)
		return (0);
	count = 1;
	if (b->next == b && b->past == b)
		return (-1);
	while (b->next != b1)
	{
		count++;
		b = b->next;
	}
	return (count);
}

