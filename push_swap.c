/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:35 by eestela           #+#    #+#             */
/*   Updated: 2021/12/16 18:41:52 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//REGELR PRINTF en WRITE
int	main(int ac, char *av[])
{
	t_tabs	*tab;
	int		size;

	if (ac == 1)
		return (0);
	tab = malloc(sizeof(t_tabs));
	if (!tab)
	{
		printf("error\n");
		return (-1);
	}
	tab = ft_init(tab, ac, av);
	if (!tab)
	{
		printf("ERROR");
		return (-1);
	}
	tab->i = 0;
	size = size_list(tab->a);
	if (size > 1 && size == 2)
		sort_two(tab);
	else if (size > 1 && size <= 5)
		sort_five(tab);
	else if (size > 1 && size <= 100)
		sort_hund(10, tab);
	else if (size > 1)
		sort_hund(13, tab);
	printf("%i MOOVES\n", tab->i);
	if (tab)
		ft_free_tab(&tab);
	return (1);
}
