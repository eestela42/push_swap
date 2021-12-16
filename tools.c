/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:52 by eestela           #+#    #+#             */
/*   Updated: 2021/12/16 18:44:03 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	afficher(t_tabs *tab)
{
	t_tab	*tmp;
	t_tab	*tmp1;

	tmp = tab->a;
	tmp1 = tab->b;
	printf("\nA:     b:\n");
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
	while (tab && tab->a && tab->a->next)
	{
		tab->b = tab->a->next;
		free(tab->a);
		tab->a = tab->b;
	}
	if (tab->a)
		free(tab->a);
	if (tab)
		free(tab);
	tab = NULL;
	*add_tab = tab;
	return (0);
}

int	size_list(t_tab *a)
{
	int		i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	is_sorted(t_tab *a)
{
	t_tab	*tmp;
	t_tab	*mem;

	tmp = a->next;
	while (tmp && a->i < tmp->i)
	{
		mem = tmp->next;
		a = tmp;
		tmp = mem;
	}
	if (tmp)
		return (0);
	return (1);
}

int	next_num(t_tab *a, t_tab *b)
{
	int		num;
	int		next;
	int		min;
	int		size;

	num = b->i;
	size = size_list(a) + size_list(b) + 1;
	next = size;
	min = a->i;
	while (a)
	{
		if (a->i > num && a->i < next)
			next = a->i;
		if (a->i < min)
			min = a->i;
		a = a->next;
	}
	if (next == size)
		return (min);
	return (next);
}

void	insert(t_tabs *tab)
{
	t_tab	*a;
	t_tab	*b;
	int		next;
	int		far;
	void	(*action)(t_tabs *tab);

	a = tab->a;
	b = tab->b;
	next = next_num(a, b);
	far = 0;
	while (a->i != next && ++far)
		a = a->next;
	if (far < size_list(tab->a) / 2)
		action = ra;
	else
	{
		action = rra;
		far = size_list(tab->a) - far;
	}
	while (far--)
		action(tab);
	pa(tab);
}
