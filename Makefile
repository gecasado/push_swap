# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gecasado <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 18:37:09 by gecasado          #+#    #+#              #
#    Updated: 2022/04/04 18:37:14 by gecasado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS = main.c \
		libft1.c \
		libft2.c \
		libft3.c \
		libft4.c \
		order.c \
		stacks1.c \
		pushrotate.c \
		swaprotate.c \
		parseo.c \
		sort.c \
		chunk.c 

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(NAME)

test: all
	@ARG=$$(seq 0 1000 | sort -R | tail -n 500 | tr '\n' ' ') ; ./push_swap $$ARG | ./checker_Mac $$ARG; ./push_swap $$ARG | wc -l

testlog: all
	@ARG=$$(seq 0 1000 | sort -R | tail -n 500 | tr '\n' ' ') ; ./push_swap $$ARG

testcomp: all
	@ARG=$$(seq 0 1000 | sort -R | tail -n 500 | tr '\n' ' ') ; ./push_swap $$ARG | wc -l; ./push_swap1 $$ARG | wc -l;
	
.PHONY: check_libft project all clean fclean re test
