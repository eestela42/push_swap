/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:29 by eestela           #+#    #+#             */
/*   Updated: 2021/11/29 17:45:22 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_tabs *tab)
{
	t_tab	*first;
	t_tab	*last;
	t_tab	*mem;

	first = tab->A;
	last = tab->A;
	mem = first->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	tab->A = mem;
	printf("ra\n");
}

void	rb(t_tabs *tab)
{
	t_tab	*first;
	t_tab	*last;
	t_tab	*mem;

	first = tab->B;
	last = tab->B;
	mem = first->next;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	tab->B = mem;
	printf("rb\n");
}

void	rr(t_tabs *tab)
{
	ra(tab);
	ra(tab);
}

void	rra(t_tabs *tab)
{
	t_tab	*first;
	t_tab	*last;
	t_tab	*bef;

	first = tab->A;
	last = tab->A;
	if (!last || !last->next)
		return ;
	while (last->next)
	{
		bef = last;
		last = last->next;
	}
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	bef->next = NULL;
	tab->A = last;
	printf("rra\n");
}

void	rrb(t_tabs *tab)
{
	t_tab	*first;
	t_tab	*last;
	t_tab	*bef;

	first = tab->B;
	last = tab->B;
	while (last->next)
	{
		bef = last;
		last = last->next;
	}
	last->next = first;
	first->prev = last;
	last->prev = NULL;
	bef->next = NULL;
	tab->B = last;
	printf("rrb\n");
}
