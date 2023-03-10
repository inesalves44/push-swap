# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 00:43:06 by idias-al          #+#    #+#              #
#    Updated: 2023/03/09 16:25:33 by idias-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = mandatory/main.o mandatory/movements/push.o mandatory/movements/movements.o mandatory/stacka_part2.o \
		mandatory/utils.o mandatory/create_stacka.o mandatory/sort3numbers.o mandatory/max_min.o mandatory/orderlessthan100.o \
		mandatory/sort500numbers.o
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