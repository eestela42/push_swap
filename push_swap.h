/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eestela <eestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:40:25 by eestela           #+#    #+#             */
/*   Updated: 2022/01/12 20:46:08 by eestela          ###   ########.fr       */
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

typedef struct s_send
{
	t_tab	*last_a;
	t_tab	*tmp;
	t_tab	*tmp1;
	int		mv1;
	int		mv2;
}				t_send;

typedef struct s_senda
{
	int		i;
	int		mv;
	int		size_l;
	void	(*action)(t_tabs *tab);
	t_tab	*tmp;
}				t_senda;

typedef struct s_norm
{
	int		i;
	t_tab	*tmp;
	t_tab	*mem;
}				t_norm;

typedef struct s_norm1
{
	int		*order;
	int		i;
	int		place;
	t_tab	*tmp;
	t_tab	*tmpo;
}				t_norm1;

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

int			place(int a, int b, int C);
void		fct1(t_tab *b, t_tab *c, t_tabs *tab);
t_norm1		ft_order_norm(t_tabs *tab, int size, t_norm1 norm);

#endif