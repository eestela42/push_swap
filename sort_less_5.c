/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:47 by eestela           #+#    #+#             */
/*   Updated: 2022/01/10 18:35:17 by eestela          ###   ########.fr       */
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

void	sort_three(t_tabs *tab)
{
	t_tab	*c;
	t_tab	*b;

	b = tab->a->next;
	c = b->next;
	if (place(tab->a->i, b->i, c->i) == 1 && !is_sorted(tab->a))
	{
		sa(tab);
		ra(tab);
	}
	if (place(tab->a->i, b->i, c->i) == 2)
		fct1(b, c, tab);
	if (place(tab->a->i, b->i, c->i) == 3)
	{
		if (place(b->i, tab->a->i, c->i) == 1)
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
