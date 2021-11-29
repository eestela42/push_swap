#include "push_swap.h"

void	sort_two(t_tabs *tab)
{
	t_tab *tmp;

	tmp = tab->A->next;
	if (tab->A->i > tmp->i)
		sa(tab);
}

int		place(int A, int B, int C)
{
	int	i;

	i = 1;
	if (A > B)
		i++;
	if (A> C)
		i++;
	return(i);
	 
}
void	sort_three(t_tabs *tab)
{
	t_tab *C;
	t_tab *B;

	B = tab->A->next;
	C = B->next;
	if (place(tab->A->i, B->i, C->i) == 1 && !is_sorted(tab->A))
	{
		sa(tab);
		ra(tab);
	}
	if (place(tab->A->i, B->i, C->i) == 2)
	{
		if (place(B->i, tab->A->i, C->i) == 1)
			sa(tab);
		else
			ra(tab);
	}
	if (place(tab->A->i, B->i, C->i) == 3)
	{
		if (place(B->i, tab->A->i, C->i) == 1)
			ra(tab);
		else
		{
			sa(tab);
			rra(tab);
		}
	}
}

void	sort_five(t_tabs *tab)
{
	while (size_list(tab->A) > 3)
		pb(tab);
	sort_three(tab);
	while (size_list(tab->B))
		insert(tab);
	while (tab->A->i != 1)
		ra(tab);
}