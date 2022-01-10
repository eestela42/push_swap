/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:26:43 by eestela           #+#    #+#             */
/*   Updated: 2022/01/10 19:26:53 by eestela          ###   ########.fr       */
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