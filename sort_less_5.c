/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:47 by eestela           #+#    #+#             */
/*   Updated: 2021/12/16 18:43:48 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_tabs *tab)
{
	t_tab	*tmp;

	tmp = tab->a->next;
	if (tab->a->i > tmp->i)
		sa(tab);
}

int	place(int a, int b, int C)
{
	int	i;

	i = 1;
	if (a > b)
		i++;
	if (a > C)
		i++;
	return (i);
}

void	sort_three(t_tabs *tab)
{
	t_tab	*C;
	t_tab	*b;

	b = tab->a->next;
	C = b->next;
	if (place(tab->a->i, b->i, C->i) == 1 && !is_sorted(tab->a))
	{
		sa(tab);
		ra(tab);
	}
	if (place(tab->a->i, b->i, C->i) == 2)
	{
		if (place(b->i, tab->a->i, C->i) == 1)
			sa(tab);
		else
			ra(tab);
	}
	if (place(tab->a->i, b->i, C->i) == 3)
	{
		if (place(b->i, tab->a->i, C->i) == 1)
			ra(tab);
		else
		{
			sa(tab);
			rra(tab);
		}
	}
}

void	sort_five(t_tabs *tab)
{
	while (size_list(tab->a) > 3)
		pb(tab);
	sort_three(tab);
	while (size_list(tab->b))
		insert(tab);
	while (tab->a->i != 1)
		ra(tab);
}
