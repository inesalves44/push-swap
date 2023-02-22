# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 00:43:06 by idias-al          #+#    #+#              #
#    Updated: 2023/02/22 11:15:39 by idias-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = mandatory/main.o mandatory/movements/push.o mandatory/movements/rotate.o mandatory/movements/swap.o  mandatory/movements/insert_delete.o \
		mandatory/utils.o mandatory/create_stacka.o mandatory/sort3numbers.o
NAME = push-swap
LIBFTPRINTF = libftprintf.a
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C ft_printf
		cp ft_printf/$(LIBFTPRINTF) $(LIBFTPRINTF)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFTPRINTF)

clean:
	$(MAKE) clean -C ft_printf
	rm -rf $(OBJS) $(BONUS)

fclean: clean
	$(MAKE) fclean -C ft_printf
	rm -rf $(NAME) $(LIBFTPRINTF)

re: fclean all