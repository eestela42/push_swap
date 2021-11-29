#include "push_swap.h"

int			main(int ac, char *av[])
{
	t_tabs	*tab;
	int		size;

	if (ac == 1)
		return(0);
	tab = malloc(sizeof(t_tabs));
	if (!tab)
	{
		printf("error\n");
		return(-1);
	}
	tab = ft_init(tab, ac, av);
	if (!tab)
	{
		printf("ERROR");
		return(-1);
	}
	tab->i = 0;
	//afficher(tab);
	size = size_list(tab->A);
	//printf("size = %i\n", size);

	if (size && size <= 2)
		sort_two(tab);
	else if (size && size <= 5)
		sort_five(tab);
	else if (size && size <= 100)
		sort_hund(10, tab);
	else if (size)
		sort_hund(13, tab);

	t_tab *tmp;
	t_tab 	*tab1;
	tab1 = tab->A;
	tmp = tab1;
	tab1 = tab1->next;
	while(tab1->next)
	{
		if(tmp->i > tab1->i)
			printf("not_sorted\n");
		tmp = tab1;
		tab1 = tmp->next;
	}
	printf("sizeito = %i  mooves = %i\n", size, tab->i);

	if (tab)
		ft_free_tab(&tab);
	return(1);
}