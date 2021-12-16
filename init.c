/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:20:58 by eestela           #+#    #+#             */
/*   Updated: 2021/12/16 18:42:26 by eestela          ###   ########.fr       */
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
	int		order[size];
	int		i;
	int		place;
	t_tab	*tmp;
	t_tab	*tmpo;

	i = 0;
	tmp = tab->a;
	while (i < size)
	{
		place = 1;
		tmpo = tab->a;
		while (tmpo)
		{
			if (tmp->i == tmpo->i && tmp != tmpo)
				return (0);
			else if (tmp->i > tmpo->i)
				place++;
			tmpo = tmpo->next;
		}
		order[i++] = place;
		tmp = tmp->next;
	}
	i = 0;
	tmp = tab->a;
	while (tmp)
	{
		tmp->i = order[i++];
		tmp = tmp->next;
	}
	return (1);
}

t_tabs	*ft_init(t_tabs *tab, int ac, char *av[])
{
	int		i;
	t_tab	*tmp;
	t_tab	*mem;

	tab->a = malloc(sizeof(t_tab));
	tab->a->next = NULL;
	if (tab->a && check_is_num(av[1]))
		tab->a->i = ft_atoi(av[1]);
	else
	{
		ft_free_tab(&tab);
		return (NULL);
	}
	i = 2;
	mem = tab->a;
	while (i < ac && check_is_num(av[i]))
	{
		tmp = malloc(sizeof(t_tab));
		if (!tmp)
		{
			ft_free_tab(&tab);
			return (NULL);
		}
		mem->next = tmp;
		tmp->prev = mem;
		tmp->i = ft_atoi(av[i++]);
		mem = tmp;
		tmp = NULL;
	}
	mem->next = NULL;
	tab->b = NULL;
	if ((tab && !ft_order(tab, size_list(tab->a))) || i < ac)
		ft_free_tab(&tab);
	return (tab);
}
