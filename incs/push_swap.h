/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:18:17 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/09 17:35:48 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/incs/ft_printf.h"
# include "../ft_printf/incs/get_next_line.h"
# include "../ft_printf/incs/get_next_line_bonus.h"


typedef struct s_dlist
{
	int				data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct s_utils
{
	int		size;
	int		half;
	int		quarter;
	int		quarter_first;
	int		second;
	int		high;
	int		max;
	int		posmax;
	int		min;
	int		posmin;
	int		min_b;
	int		pos;
	char	test;
	int		do_b;
	char	swap_a;
	char	push_a;
	char	rrotate_a;
	char	rotate_a;
	char	push_f;
}		t_utils;

/*movements: swap and rotate*/
t_dlist	*rotate(t_dlist *lst, char **str);
t_dlist	*rotate_b(t_dlist *lst, char **str);
t_dlist	*r_rotate(t_dlist *lst, char **str);
t_dlist	*r_rotate_b(t_dlist *lst, char **str);
t_dlist	*swap(t_dlist *test, char **str2);
t_dlist	*swap_b(t_dlist *test, char **str2);

/*push*/
t_dlist	*pushing_toa(t_dlist *lsta, t_dlist *lstb);
t_dlist	*deletefromstack(t_dlist *lsta);
int		deletefromb(t_dlist *lstb);
t_dlist	*pushing_to_stack(t_dlist **stackd, t_dlist *lsti);
t_dlist	*push(t_dlist *lsti, t_dlist **lstd, char **str);
t_dlist	*push_final(t_dlist *lsti, t_dlist **lstd, char **str);
t_dlist	*push_b(t_dlist *lsti, t_dlist **lstd, char **str);

/*create stack a and stacka_part2*/
t_dlist	*stack_creation(char *args, t_dlist *head);
t_dlist	*first_list(char **argv, int argc);
int		checking_list(t_dlist *lst);
t_dlist	*stack_creation_ind(t_dlist *head);
t_dlist	*aux_stacka(t_dlist *stacka, int i, int j);
t_dlist	*finish_stack(t_dlist *lst, t_dlist *stacka, int min);
t_dlist	*create_stack(t_dlist *lst);

/*sort 3 and 5 numbers*/
t_dlist	*sort3numbers(t_dlist *stacka, t_utils *utils, char **str);
t_dlist	*sort5numbers(t_dlist *stacka, t_dlist **lstb, t_utils *utils, char **str);
t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb, t_utils *utils, char **str);

/*max*/
int		get_max(t_dlist *lst);
int		get_min(t_dlist *lst);
int		get_max2(t_dlist *lst, int max);
int		get_min2(t_dlist *lst, int min);

/*Utils*/
t_dlist	*ft_createnode(int data);
int		ft_tdsize(t_dlist *head);
t_utils	creting_struck(t_dlist *stacka);
void	free_list(t_dlist **head);
t_dlist	**reorder_stacks(t_dlist **stacka);
void	print_dblist(t_dlist *lst);
void	print_dblist2(t_dlist *lst1, t_dlist *lst2);

/*order 100*/
t_dlist *separte_stacks(t_dlist *stacka, t_dlist **stackb, char **str, t_utils *utils);
int		get_pos(char *s, t_dlist *stackb);
t_dlist	*do_stackb(t_dlist *stackb, t_dlist **stacka, char **str, t_utils *utils);
t_dlist	*sort100numbers(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str);

/*order 500*/
t_dlist	*sort500numbers(t_dlist *stacka, t_dlist **stackb, t_utils *utils, char **str);

/*main*/
int		checking_ifordered(t_dlist *stacka, int i);
int		find_number(t_dlist *stack, int number);

#endif