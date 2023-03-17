# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 00:43:06 by idias-al          #+#    #+#              #
#    Updated: 2023/03/17 17:13:34 by idias-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = mandatory/main.o mandatory/list/push.o mandatory/list/rotate.o mandatory/list/swap.o mandatory/list/add_lst_front.o mandatory/list/delete_lst_front.o\
	   mandatory/list/ft_tdsizelist.o mandatory/list/lst_createnode.o mandatory/list/free_list.o mandatory/list/print_list.o \
	   mandatory/init_listtest.o mandatory/utils.o mandatory/create_stacka.o mandatory/sort3numbers.o \
	   mandatory/sort500numbers.o
NAME = push_swap
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
