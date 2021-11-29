#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int nbr;
	int i;
	int sign;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
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

int		ft_place(char *str, int ac, char *av[])
{
	int i;
	int	place;
	int	nbr;

	nbr = ft_atoi(str);
	place = 1;
	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i++]) < nbr)
			place++;
	}
	return(place);
}

t_tab	*init(t_tab *A, int ac, char *av[])
{
	int		y;
	t_tab	*tmp;
	t_tab	*mem;
	t_tab	*prev;

	if (ac < 2)
		return(NULL);
	A = malloc(sizeof(t_tab));
	A->i = ft_place(av[1], ac, av);
	tmp = NULL;
	prev = NULL;
	mem = A;
	y = 2;
	while (y < ac)
	{
		tmp = malloc(sizeof(t_tab));
		tmp->i = ft_place(av[y++], ac, av);
		mem->next = tmp;
		mem->prev = prev;
		prev = mem;
		mem = tmp;
		tmp = NULL;
	}
	mem->prev = prev;
	mem->next = NULL;
	return(A);
}