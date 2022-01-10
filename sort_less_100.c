/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:50 by eestela           #+#    #+#             */
/*   Updated: 2022/01/10 18:36:28 by eestela          ###   ########.fr       */
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

int	send_to_b(t_tabs *tab, int s_size, int s_comp)
{
	t_tab	*last_a;
	t_tab	*tmp;
	t_tab	*tmp1;
	int		mv1;
	int		mv2;

	while (tab->a)
	{
		last_a = tab->a;
		while (last_a->next)
			last_a = last_a->next;
		mv1 = 0;
		tmp = tab->a;
		while (++mv1 && tmp->next && (tmp->i > s_comp * s_size))
			tmp = tmp->next;
		--mv1;
		mv2 = 0;
		tmp1 = last_a;
		while (++mv2 && tmp1->prev && (tmp1->i > s_comp * s_size))
			tmp1 = tmp1->prev;
		--mv2;
		if (mv1 < mv2 + 1 || (mv1 == mv2 + 1 && tmp->i < tmp1->i))
			s_comp = sending_top(tab, mv1, s_size, s_comp);
		else
			s_comp = sending_bot(tab, mv2 + 1, s_size, s_comp);
		if (tab->b->next && tab->b->i < tab->b->next->i)
			sb(tab);
	}	
	return (0);
}

void	send_to_a(t_tabs *tab, int size)
{
	int		i;
	int		mv;
	int		size_l;
	void	(*action)(t_tabs *tab);
	t_tab	*tmp;

	i = 0;
	while (tab->b)
	{
		size_l = size_list(tab->b);
		mv = 0;
		tmp = tab->b;
		while (tmp->next && tmp->i != size - i && ++mv)
			tmp = tmp->next;
		action = rb;
		if (mv > size_l / 2)
		{
			action = rrb;
			mv = (size_l - mv);
		}
		while (mv--)
		{
			tab->i++;
			action(tab);
		}
		tab->i++;
		pa(tab);
		i++;
	}
}

void	sort_hund(int stack, t_tabs *tab)
{
	int	s_size;
	int	size;
	int	s_comp;

	size = size_list(tab->a);
	s_size = size / stack;
	while (s_size * stack < size)
		s_size++;
	s_comp = 1;
	s_comp = send_to_b(tab, s_size, s_comp);
	send_to_a(tab, size);
}
