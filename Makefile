# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 00:43:06 by idias-al          #+#    #+#              #
#    Updated: 2023/03/11 20:30:48 by idias-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = mandatory/main.o mandatory/movements/push.o mandatory/movements/movements.o mandatory/stacka_part2.o \
		mandatory/utils.o mandatory/create_stacka.o mandatory/sort3numbers.o mandatory/max_min.o mandatory/orderlessthan100.o \
		mandatory/radix_sort.o
NAME = push-swap
LIBFT = libft.a
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) -C libft
		cp libft/$(LIBFT) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJS) $(BONUS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME) $(LIBFT)

re: fclean all
