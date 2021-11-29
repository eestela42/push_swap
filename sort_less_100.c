#include "push_swap.h"

int		sending_top(t_tabs *tab, int mv, int s_size, int s_comp)
{
	void	(*action)(t_tab **add);
	int		i;

	i = 0;
	
	while (mv--)
	{tab->i++;
		ra(tab);
	}
	tab->i++;
	pb(tab);
	if (s_size * s_comp <= size_list(tab->B))
		return(s_comp + 1);
	return(s_comp);
}

int		sending_bot(t_tabs *tab, int mv, int s_size, int s_comp)
{
	void	(*action)(t_tab **add);
	int		i;

	i = 0;
	while (mv--)
	{
		rra(tab);
		tab->i++;
	}
	pb(tab);
	tab->i++;
	if (s_size * s_comp <= size_list(tab->B))
		return(s_comp + 1);
	return(s_comp);
}

int		send_to_B(t_tabs *tab, int s_size, int s_comp, int size)
{
	t_tab	*last_A;
	t_tab	*tmp;
	t_tab	*tmp1;
	int		mv1;
	int		mv2;
	
	while (tab->A)
	{
		last_A = tab->A;
		while(last_A->next)
			last_A = last_A->next;
		mv1 = 0;
		tmp = tab->A;
		while(++mv1 && tmp->next && (tmp->i >s_comp * s_size))
			tmp = tmp->next;
		--mv1;
		mv2 = 0;
		tmp1 = last_A;
		while(++mv2 && tmp1->prev && (tmp1->i >s_comp * s_size))
			tmp1 = tmp1->prev;
		--mv2;
		if (mv1 < mv2 + 1 || (mv1 == mv2 + 1 && tmp->i < tmp1->i))
			s_comp = sending_top(tab, mv1, s_size, s_comp);
		else
			s_comp = sending_bot(tab, mv2 + 1, s_size, s_comp);
		if (tab->B->next && tab->B->i < tab->B->next->i)
			sb(tab);
	}	
	return(0);
}

void	send_to_A(t_tabs *tab, int size)
{
	int	i;
	int	mv;
	int size_l;
	void	(*action)(t_tabs *tab);
	t_tab	*tmp;

	i = 0;
	while (tab->B)
	{
		size_l = size_list(tab->B);
		mv = 0;
		tmp = tab->B;
		while (tmp->next && tmp->i != size - i && ++mv)
			tmp = tmp->next;
		action = rb;
		if (mv > size_l / 2)
		{
			action = rrb;
			mv = (size_l - mv);
		}
		while (mv--)
		{
			tab->i++;
			action(tab);
		}
		tab->i++;
		pa(tab);
		i++;
	}
	
}

void	sort_hund(int	stack, t_tabs *tab)
{
	int	s_size;
	int	size;
	int	s_comp;

	size = size_list(tab->A);
	s_size = size / stack;
	while (s_size * stack < size)
		s_size++;
	s_comp = 1;
	s_comp = send_to_B(tab, s_size, s_comp, size);
	send_to_A(tab, size);
}