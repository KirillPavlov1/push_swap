/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvirgin <cvirgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:17:29 by kirill            #+#    #+#             */
/*   Updated: 2021/08/04 16:58:08 by cvirgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_b	*ft_bnew(void *content)
{
	t_b	*new;

	new = malloc(sizeof(t_b));
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
	t_a	*new;

	new = malloc(sizeof(t_a));
	new->past = new;
	new->next = new;
	new->up = 0;
	new->down = 0;
	new->n = ft_atoi(content);
	return (new);
}

t_a	*ft_anew_n(int n)
{
	t_a	*new;

	new = malloc(sizeof(t_a));
	new->past = new;
	new->next = new;
	new->n = n;
	return (new);
}

t_b	*ft_bnew_n(int n)
{
	t_b	*new;

	new = malloc(sizeof(t_b));
	new->past = new;
	new->next = new;
	new->up_a = 0;
	new->down_a = 0;
	new->up = 0;
	new->down = 0;
	new->n = n;
	return (new);
}

void	ft_adda_back(t_a **lst, t_a *new)
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
}
