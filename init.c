/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:58 by eestela           #+#    #+#             */
/*   Updated: 2022/01/12 20:46:41 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	i;
	int	sign;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == -1)
			nbr = nbr * 10 - (str[i] - 48);
		if (sign == 1)
			nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr);
}

int	check_is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	if (ft_atoi(str))
		;
	else if ((!ft_atoi(str) && ((str[0] != '0' && !str[1])))
		|| (str[0] != '-' && str[1] != '0' && !str[2]) || i > 10)
		return (0);
	return (1);
}

int	ft_order(t_tabs *tab, int size)
{
	t_norm1	norm;

	norm.i = 0;
	norm.tmp = tab->a;
	norm.order = malloc(sizeof(int) * size + 1);
	if (!norm.order)
		return (0);
	norm = ft_order_norm(tab, size, norm);
	if (norm.i == -1)
	{
		free(norm.order);
		return (0);
	}
	norm.i = 0;
	norm.tmp = tab->a;
	while (norm.tmp)
	{
		norm.tmp->i = norm.order[norm.i++];
		norm.tmp = norm.tmp->next;
	}
	free(norm.order);
	return (1);
}

int	norm_init(t_norm norm, t_tabs *tab, int ac, char *av[])
{
	while (norm.i < ac && check_is_num(av[norm.i]))
	{
		norm.tmp = malloc(sizeof(t_tab));
		if (!norm.tmp)
		{
			ft_free_tab(&tab);
			return (-1);
		}
		norm.mem->next = norm.tmp;
		norm.tmp->prev = norm.mem;
		norm.tmp->i = ft_atoi(av[norm.i++]);
		norm.mem = norm.tmp;
		norm.tmp = NULL;
	}
	norm.mem->next = NULL;
	return (norm.i);
}

t_tabs	*ft_init(t_tabs *tab, int ac, char *av[])
{
	t_norm	norm;

	tab->a = malloc(sizeof(t_tab));
	tab->a->next = NULL;
	if (tab->a && check_is_num(av[1]))
		tab->a->i = ft_atoi(av[1]);
	else
	{
		ft_free_tab(&tab);
		return (NULL);
	}
	norm.i = 2;
	norm.mem = tab->a;
	norm.i = norm_init(norm, tab, ac, av);
	if (norm.i == -1)
		return (NULL);
	tab->b = NULL;
	if ((tab && !ft_order(tab, size_list(tab->a))) || norm.i < ac)
		ft_free_tab(&tab);
	return (tab);
}
