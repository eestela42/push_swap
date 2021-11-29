# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maskedduck <maskedduck@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 13:18:56 by user42            #+#    #+#              #
#    Updated: 2021/09/16 15:53:20 by maskedduck       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
INC = push_swap.h
FLAGS =  -fsanitize=address

SRCS =	push_swap.c		\
		operations1.c	\
		operations2.c	\
		operations3.c	\
		tools.c			\
		init.c			\
		sort_less_5.c	\
		sort_less_100.c	\
	
OBJS = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(FLAGS)

$(OBJS):	$(SRCS) $(INC)
		$(CC) $(FLAGS) -c $(SRCS)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all bonus clean fclean re