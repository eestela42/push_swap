/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:19 by eestela           #+#    #+#             */
/*   Updated: 2021/11/29 17:45:51 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_tabs *tab)
{
	t_tab	*second;
	t_tab	*first;

	first = tab->A;
	second = first->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	tab->A = second;
	printf("sa\n");
}

void	sb(t_tabs *tab)
{
	t_tab	*second;
	t_tab	*first;

	first = tab->B;
	second = first->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	tab->B = second;
	printf("sb\n");
}

void	ss(t_tabs *tab)
{
	sa(tab);
	sa(tab);
}

void	pa(t_tabs *tab)
{
	t_tab	*A;
	t_tab	*B;
	t_tab	*mem;

	A = tab->A;
	B = tab->B;
	mem = B->next;
	B->next = A;
	if (A)
		A->prev = B;
	tab->A = B;
	if (mem)
		mem->prev = NULL;
	tab->B = mem;
	printf("pa\n");
}

void	pb(t_tabs *tab)
{
	t_tab	*B;
	t_tab	*A;
	t_tab	*mem;

	B = tab->B;
	A = tab->A;
	mem = A->next;
	A->next = B;
	if (B)
		B->prev = A;
	tab->B = A;
	if (mem)
		mem->prev = NULL;
	tab->A = mem;
	printf("pb\n");
}
