/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:19 by eestela           #+#    #+#             */
/*   Updated: 2021/12/16 18:42:34 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_tabs *tab)
{
	t_tab	*second;
	t_tab	*first;

	first = tab->a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	tab->a = second;
	printf("sa\n");
}

void	sb(t_tabs *tab)
{
	t_tab	*second;
	t_tab	*first;

	first = tab->b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	tab->b = second;
	printf("sb\n");
}

void	ss(t_tabs *tab)
{
	sa(tab);
	sa(tab);
}

void	pa(t_tabs *tab)
{
	t_tab	*a;
	t_tab	*b;
	t_tab	*mem;

	a = tab->a;
	b = tab->b;
	mem = b->next;
	b->next = a;
	if (a)
		a->prev = b;
	tab->a = b;
	if (mem)
		mem->prev = NULL;
	tab->b = mem;
	printf("pa\n");
}

void	pb(t_tabs *tab)
{
	t_tab	*b;
	t_tab	*a;
	t_tab	*mem;

	b = tab->b;
	a = tab->a;
	mem = a->next;
	a->next = b;
	if (b)
		b->prev = a;
	tab->b = a;
	if (mem)
		mem->prev = NULL;
	tab->a = mem;
	printf("pb\n");
}
