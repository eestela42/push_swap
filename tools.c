/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:52 by eestela           #+#    #+#             */
/*   Updated: 2021/11/29 17:32:22 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	afficher(t_tabs *tab)
{
	t_tab	*tmp;
	t_tab	*tmp1;

	tmp = tab->A;
	tmp1 = tab->B;
	printf("\nA:     B:\n");
	while (tmp || tmp1)
	{
		if (tmp)
		{
			printf("%-7i", tmp->i);
			tmp = tmp->next;
		}
		else
			printf("       ");
		if (tmp1)
		{
			printf("%i\n", tmp1->i);
			tmp1 = tmp1->next;
		}
		else
			printf("\n");
	}
	printf("\n\n");
}

int	ft_free_tab(t_tabs **add_tab)
{
	t_tabs	*tab;

	if (add_tab)
		tab = *add_tab;
	else
		tab = NULL;
	while (tab && tab->A && tab->A->next)
	{
		tab->B = tab->A->next;
		free(tab->A);
		tab->A = tab->B;
	}
	if (tab->A)
		free(tab->A);
	if (tab)
		free(tab);
	tab = NULL;
	*add_tab = tab;
	return (0);
}

int	size_list(t_tab *A)
{
	int		i;

	i = 0;
	while (A)
	{
		i++;
		A = A->next;
	}
	return (i);
}

int	is_sorted(t_tab *A)
{
	t_tab	*tmp;
	t_tab	*mem;

	tmp = A->next;
	while (tmp && A->i < tmp->i)
	{
		mem = tmp->next;
		A = tmp;
		tmp = mem;
	}
	if (tmp)
		return (0);
	return (1);
}

int	next_num(t_tab *A, t_tab *B)
{
	int		num;
	int		next;
	int		min;
	int		size;

	num = B->i;
	size = size_list(A) + size_list(B) + 1;
	next = size;
	min = A->i;
	while (A)
	{
		if (A->i > num && A->i < next)
			next = A->i;
		if (A->i < min)
			min = A->i;
		A = A->next;
	}
	if (next == size)
		return (min);
	return (next);
}

void	insert(t_tabs *tab)
{
	t_tab	*A;
	t_tab	*B;
	int		next;
	int		far;
	void	(*action)(t_tabs *tab);

	A = tab->A;
	B = tab->B;
	next = next_num(A, B);
	far = 0;
	while (A->i != next && ++far)
		A = A->next;
	if (far < size_list(tab->A) / 2)
		action = ra;
	else
	{
		action = rra;
		far = size_list(tab->A) - far;
	}
	while (far--)
		action(tab);
	pa(tab);
}
