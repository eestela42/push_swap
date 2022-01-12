/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:50 by eestela           #+#    #+#             */
/*   Updated: 2022/01/12 20:30:14 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	send_to_b(t_tabs *tab, int s_size, int s_comp)
{
	t_send	b;

	while (tab->a)
	{
		b.last_a = tab->a;
		while (b.last_a->next)
			b.last_a = b.last_a->next;
		b.mv1 = 0;
		b.tmp = tab->a;
		while (++b.mv1 && b.tmp->next && (b.tmp->i > s_comp * s_size))
			b.tmp = b.tmp->next;
		--b.mv1;
		b.mv2 = 0;
		b.tmp1 = b.last_a;
		while (++b.mv2 && b.tmp1->prev && (b.tmp1->i > s_comp * s_size))
			b.tmp1 = b.tmp1->prev;
		--b.mv2;
		if (b.mv1 < b.mv2 + 1 || (b.mv1 == b.mv2 + 1 && b.tmp->i < b.tmp1->i))
			s_comp = sending_top(tab, b.mv1, s_size, s_comp);
		else
			s_comp = sending_bot(tab, b.mv2 + 1, s_size, s_comp);
		if (tab->b->next && tab->b->i < tab->b->next->i)
			sb(tab);
	}	
	return (0);
}

void	send_to_a(t_tabs *tab, int size, t_senda senda)
{
	senda.i = 0;
	while (tab->b)
	{
		senda.size_l = size_list(tab->b);
		senda.mv = 0;
		senda.tmp = tab->b;
		while (senda.tmp->next && senda.tmp->i != size - senda.i && ++senda.mv)
			senda.tmp = senda.tmp->next;
		senda.action = rb;
		if (senda.mv > senda.size_l / 2)
		{
			senda.action = rrb;
			senda.mv = (senda.size_l - senda.mv);
		}
		while (senda.mv--)
		{
			tab->i++;
			senda.action(tab);
		}
		tab->i++;
		pa(tab);
		senda.i++;
	}
}

void	sort_hund(int stack, t_tabs *tab)
{
	int		s_size;
	int		size;
	int		s_comp;
	t_senda	senda;

	size = size_list(tab->a);
	s_size = size / stack;
	while (s_size * stack < size)
		s_size++;
	s_comp = 1;
	s_comp = send_to_b(tab, s_size, s_comp);
	send_to_a(tab, size, senda);
}
