# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 00:43:06 by idias-al          #+#    #+#              #
#    Updated: 2023/03/21 12:38:00 by idias-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJ_MAIN = mandatory/main.o
OBJS = mandatory/double_linked_list/push.o mandatory/double_linked_list/rotate.o mandatory/double_linked_list/swap.o mandatory/double_linked_list/add_lst_front.o mandatory/double_linked_list/delete_lst_front.o\
	   mandatory/double_linked_list/ft_tdsizelist.o mandatory/double_linked_list/lst_createnode.o mandatory/double_linked_list/free_list.o mandatory/double_linked_list/print_list.o \
	   mandatory/init_listtest.o mandatory/utils.o mandatory/create_stacka.o mandatory/sort3numbers.o \
	   mandatory/big_algorithm.o mandatory/algo_utils.o mandatory/algo_utils2.o
OBJS_BONUS = bonus/checker_main_bonus.o bonus/starting_list_bonus.o bonus/movements_bonus.o
NAME = push_swap
BONUS = checker
LIBFT = libft.a
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -g

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(OBJ_MAIN)
		$(MAKE) -C libft
		cp libft/$(LIBFT) $(LIBFT)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ_MAIN) $(OBJS) $(LIBFT)

$(BONUS): $(OBJS_BONUS) $(NAME)
		$(MAKE) -C libft
		cp libft/$(LIBFT) $(LIBFT)
		$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT)

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJS) $(OBJS_BONUS) $(OBJ_MAIN)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME) $(BONUS) $(LIBFT)

re: fclean all

rebonus: fclean bonus
