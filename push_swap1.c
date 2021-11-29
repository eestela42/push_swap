#include "push_swap.h"

int		ft_free_tab(t_tabs **add_tab)
{
	t_tabs	*tab;

	tab = *add_tab;
	while (tab->A)
	{
		tab->B = tab->A->next;
		free(tab->A);
		tab->A = tab->B;
	}
	if (tab)
		free(tab);
	return(0);
}

int		main(int ac, char *av[])
{
	t_tabs	*tab;
	int		size;

	tab = malloc(sizeof(t_tabs));
	tab->i = 0;
	tab->B = NULL;
	init(tab, ac, av);
	if (!tab)
	{
		printf("YAPADELISTEPTN\n");
		return(0);
	}
	size = size_list(tab->A);
	//size = check_lst(tab->A, size);
	printf("size = %i\n", size);
	if (size && size <= 2)
		sort_two(tab);
	else if (size && size <= 5)
		sort_five(tab);
	else if (size && size <= 100)
		sort_hund(10, tab);
	else if (size)
		sort_hund(13, tab);
	printf("size = %i  mooves = %i\n", size, tab->i);
	afficher(tab);
	if (tab)
		ft_free_tab(&tab);
	return(1);
}