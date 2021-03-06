/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:33 by eestela           #+#    #+#             */
/*   Updated: 2022/01/12 20:25:25 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_tabs *tab)
{
	rra(tab);
	rra(tab);
}

void	fct1(t_tab *b, t_tab *c, t_tabs *tab)
{
	if (place(b->i, tab->a->i, c->i) == 1)
		sa(tab);
	else
		ra(tab);
}
