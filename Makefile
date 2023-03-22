# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/18 00:43:06 by idias-al          #+#    #+#              #
#    Updated: 2023/03/22 09:52:02 by idias-al         ###   ########.fr        #
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
GREEN		:=	\033[0;32m
RED			:=	\033[1;31m
WHITE		:=	\033[1;37m
BOLD		:=	\033[1;1ms
CYAN		:=	\033[0;36m

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS) $(OBJ_MAIN)
		@$(MAKE) --no-print-directory -C libft
		@cp libft/$(LIBFT) $(LIBFT)
		@echo "$(GREEN) [Success] libft compilation."
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_MAIN) $(OBJS) $(LIBFT)
		@echo "$(GREEN) [Success] push_swap compilation."

$(BONUS): $(OBJS_BONUS) $(NAME)
		@$(CC) $(CFLAGS) -o $(BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT)
		@echo "$(GREEN) [Success] push_swap bonus compilation."

clean:
	@$(MAKE) clean --no-print-directory -C libft
	@echo "$(CYAN) [cleaned] libft objects."
	@rm -rf $(OBJS) $(OBJS_BONUS) $(OBJ_MAIN)
	@echo "$(CYAN) [cleaned] push_swap objects."

fclean: clean
	@$(MAKE) fclean --no-print-directory -C libft
	@echo "$(CYAN) [cleaned] libft library."
	@rm -rf $(NAME) $(BONUS) $(LIBFT)
	@echo "$(CYAN) [cleaned] executables.$(WHITE)"

re: fclean all

rebonus: fclean bonus
