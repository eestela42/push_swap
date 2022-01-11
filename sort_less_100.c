/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:50 by eestela           #+#    #+#             */
/*   Updated: 2022/01/10 19:39:38 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	send_to_b(t_tabs *tab, int s_size, int s_comp)
{
	t_send	send;

	while (tab->a)
	{
		send.last_a = tab->a;
		while (send.last_a->next)
			send.last_a = send.last_a->next;
		send.mv1 = 0;
		send.tmp = tab->a;
		while (++send.mv1 && send.tmp->next && (send.tmp->i > s_comp * s_size))
			send.tmp = send.tmp->next;
		--send.mv1;
		send.mv2 = 0;
		send.tmp1 = send.last_a;
		while (++send.mv2 && send.tmp1->prev && (send.tmp1->i > s_comp * s_size))
			send.tmp1 = send.tmp1->prev;
		--send.mv2;
		if (send.mv1 < send.mv2 + 1 || (send.mv1 == send.mv2 + 1 && send.tmp->i < send.tmp1->i))
			s_comp = sending_top(tab, send.mv1, s_size, s_comp);
		else
			s_comp = sending_bot(tab, send.mv2 + 1, s_size, s_comp);
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
	int	s_size;
	int	size;
	int	s_comp;
	t_senda	senda;

	size = size_list(tab->a);
	s_size = size / stack;
	while (s_size * stack < size)
		s_size++;
	s_comp = 1;
	s_comp = send_to_b(tab, s_size, s_comp);
	send_to_a(tab, size, senda);
}
