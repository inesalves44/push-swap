/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:18:17 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/19 13:36:31 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/incs/ft_printf.h"
# include "../libft/incs/get_next_line.h"
# include "../libft/incs/get_next_line_bonus.h"

typedef struct s_dlist
{
	int				data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct s_utils
{
	int		size;
	int		min;
	int		movements_a;
	int		movements_b;
	int		movements_t;
	int		movements_t_final;
	int		value_a;
	int		value_b;
	int		value_b_prev;
	char	rotate_b;
	char	rotate_a;
	char	push;
	char	final_rotate_a;
	char	final_rotate_b;
	char	rotate_total;
	char	part;
	char	moves;
}			t_utils;

/*folder: List - Utils and others of doubly linked list*/
/*swap and rotate*/
t_dlist	*rotate(t_dlist *lst, t_utils *utils);
t_dlist	*r_rotate(t_dlist *lst, t_utils *utils);
t_dlist	*swap(t_dlist *test, t_utils *utils);
t_dlist	*swap_b(t_dlist *test, t_utils *utils);

/*push*/
t_dlist	*push(t_dlist *lsti, t_dlist **lstd, t_utils *utils);
t_dlist	*push_final(t_dlist *lsti, t_dlist **lstd, t_utils *utils);
t_dlist	*pushing_toa(t_dlist *lsta, t_dlist *lstb);
int		deletefromb(t_dlist *lstb);

/*delete from front*/
t_dlist	*delete_from_front(t_dlist *lsta);
/*add to front*/
t_dlist	*add_to_front(int data, t_dlist *lsti);
/*free list*/
void	free_list(t_dlist **head);
/*create node*/
t_dlist	*ft_createnode(int data);
/*size*/
int		ft_tdsize(t_dlist *head);
/*print*/
void	print_dblist(t_dlist *lst);
void	print_dblist2(t_dlist *lst1, t_dlist *lst2);

/*start the list from the argv*/
int		checking_digits(char **argv);
t_dlist	*first_list(char **argv, int argc);
int		checking_list(t_dlist *lst);
long	ft_atol(const char *nptr);
void	error_func(t_dlist **list);

/*create stack a and stacka_part2*/
t_dlist	*aux_stacka(t_dlist *stacka, int i, int j);
t_dlist	*finish_stack(t_dlist *lst, t_dlist *stacka, int min);
t_dlist	*create_stack(t_dlist *lst);

/*sort 3 and 5 numbers*/
t_dlist	*sort3numbers(t_dlist *stacka, t_utils *utils);
t_dlist	*sort5numbers(t_dlist *stacka, t_dlist **lstb, t_utils *utils);
t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb, t_utils *utils);
t_dlist	*sort3numbers_rev(t_dlist *stacka, t_utils *utils);

/*utils*/
int		get_max(t_dlist *lst);
int		get_min(t_dlist *lst);
int		get_max2(t_dlist *lst, int max);
int		get_min2(t_dlist *lst, int min);
t_utils	creting_struck(t_dlist *stacka);

/*order 500*/
t_dlist	*bigalgorithm(t_dlist *stacka, t_dlist **stackb, t_utils *utils);
t_dlist	*test_part2(t_dlist *stacka, t_dlist **stackb, t_utils *utils);
t_dlist	*test(t_dlist *stacka, t_dlist **stackb, t_utils *utils);
t_dlist	*last_three(t_dlist *stacka, t_dlist **stackb, t_utils *utils);
/*algo_utils2*/
int		total_moves(int data, t_dlist *sa, t_dlist **sb, t_utils *u);
int		total_moves_other(int data, t_dlist *sa, t_dlist **sb, t_utils *u);
t_utils	*final_check(t_utils *utils);
t_utils	*check_movements(int data, t_dlist *sa, t_dlist **sb, t_utils *u);
t_utils	*instructions(t_dlist *stacka, t_dlist **stackb, t_utils *utils);
/*algo_utils*/
int		get_values(int data, t_dlist **stackb, t_utils *utils);
int		get_values2(int a, int data, t_dlist **stackb, t_utils *utils);

/*main*/
t_dlist	*annalysing_stack(t_dlist *stacka, t_dlist **stackb);
int		checking_ifordered(t_dlist *stacka, int i);
int		find_number(t_dlist *stack, int number);

#endif
