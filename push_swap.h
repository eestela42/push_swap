/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:40:25 by eestela           #+#    #+#             */
/*   Updated: 2022/01/10 19:29:38 by eestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_tab
{
	int					i;
	struct s_tab		*next;
	struct s_tab		*prev;
}						t_tab;

typedef struct s_tabs
{
	t_tab				*a;
	t_tab				*b;
	int					i;
}				t_tabs;

void		sa(t_tabs *tab);
void		sb(t_tabs *tab);
void		ss(t_tabs *tab);
void		pa(t_tabs *tab);
void		pb(t_tabs *tab);
void		ra(t_tabs *tab);
void		rb(t_tabs *tab);
void		rra(t_tabs *tab);
void		rrb(t_tabs *tab);
void		rrr(t_tabs *tab);

void		afficher(t_tabs *tab);

int			size_list(t_tab *a);
int			is_sorted(t_tab *a);
void		insert(t_tabs *tab);
int			check_lst(t_tab	*a, int size);
int			ft_free_tab(t_tabs **tab);
//void		init(t_tabs *tab, int ac, char *av[]);
t_tabs		*ft_init(t_tabs *tab, int ac, char *av[]);

void		sort_two(t_tabs *tab);
void		sort_three(t_tabs *tab);
void		sort_five(t_tabs *tab);
void		sort_hund(int stack, t_tabs *tab);

int			sending_top(t_tabs *tab, int mv, int s_size, int s_comp);
int			sending_bot(t_tabs *tab, int mv, int s_size, int s_comp);

#endif