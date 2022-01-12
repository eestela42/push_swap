/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:26:43 by eestela           #+#    #+#             */
/*   Updated: 2022/01/12 20:46:32 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sending_top(t_tabs *tab, int mv, int s_size, int s_comp)
{
	while (mv--)
	{
		tab->i++;
		ra(tab);
	}
	tab->i++;
	pb(tab);
	if (s_size * s_comp <= size_list(tab->b))
		return (s_comp + 1);
	return (s_comp);
}

int	sending_bot(t_tabs *tab, int mv, int s_size, int s_comp)
{
	while (mv--)
	{
		rra(tab);
		tab->i++;
	}
	pb(tab);
	tab->i++;
	if (s_size * s_comp <= size_list(tab->b))
		return (s_comp + 1);
	return (s_comp);
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

t_norm1	ft_order_norm(t_tabs *tab, int size, t_norm1 norm)
{
	while (norm.i < size)
	{
		norm.place = 1;
		norm.tmpo = tab->a;
		while (norm.tmpo)
		{
			if (norm.tmp->i == norm.tmpo->i && norm.tmp != norm.tmpo)
			{
				norm.i = -1;
				return (norm);
			}
			else if (norm.tmp->i > norm.tmpo->i)
				norm.place++;
			norm.tmpo = norm.tmpo->next;
		}
		norm.order[norm.i++] = norm.place;
		norm.tmp = norm.tmp->next;
	}
	return (norm);
}
