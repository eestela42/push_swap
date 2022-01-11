/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:35 by eestela           #+#    #+#             */
/*   Updated: 2022/01/10 19:51:10 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	launcher(t_tabs *tab, int size)
{
	if (size > 1 && size == 2)
		sort_two(tab);
	else if (size > 1 && size <= 5)
		sort_five(tab);
	else if (size > 1 && size <= 100)
		sort_hund(10, tab);
	else if (size > 1)
		sort_hund(13, tab);
	return (1);
}

int	main(int ac, char *av[])
{
	t_tabs	*tab;

	if (ac == 1)
		return (0);
	tab = malloc(sizeof(t_tabs));
	if (tab)
		tab = ft_init(tab, ac, av);
	if (!tab)
	{
		printf("Error\n");
		return (-1);
	}
	tab->i = 0;
	launcher(tab, size_list(tab->a));
	if (tab)
		ft_free_tab(&tab);
	return (1);
}
