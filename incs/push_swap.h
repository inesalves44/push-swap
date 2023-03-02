/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:18:17 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/02 23:08:49 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/incs/ft_printf.h"
# include "../ft_printf/incs/get_next_line.h"
# include "../ft_printf/incs/get_next_line_bonus.h"

# ifndef DIV_STACK
#  define DIV_STACK 3
# endif

typedef struct s_dlist
{
	int				data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

/*movements: swap and rotate*/
t_dlist	*rotate(t_dlist *head, int a);
t_dlist	*r_rotate(t_dlist *lst, int a);
t_dlist	*swap(t_dlist *test, int a);
void	swap_total(t_dlist *stacka, t_dlist *stackb);

/*push*/
t_dlist	*pushing_toa(t_dlist *lsta, t_dlist *lstb);
t_dlist	*deletefromstack(t_dlist *lsta);
t_dlist	*deletefromb(t_dlist *lstb);
t_dlist	*pushing_to_stack(t_dlist **stackd, t_dlist *lsti);
t_dlist	*push(t_dlist *lsti, t_dlist **lstd, char a, char t);

/*create stack a and stacka_part2*/
t_dlist	*stack_creation(char *args, t_dlist *head);
t_dlist	*first_list(char **argv, int argc);
int		checking_list(t_dlist *lst);
t_dlist	*stack_creation_ind(t_dlist *head);
t_dlist	*aux_stacka(t_dlist *stacka, int i, int j);
t_dlist	*finish_stack(t_dlist *lst, t_dlist *stacka, int min);
t_dlist	*create_stack(t_dlist *lst);

/*sort 3 and 5 numbers*/
t_dlist	*sort3numbers(t_dlist *stacka);
t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb, int min, int min2);
t_dlist	*sort5numbers(t_dlist *stacka, t_dlist **stackb);

/*max*/
int		get_max(t_dlist *lst);
int		get_min(t_dlist *lst);
int		get_max2(t_dlist *lst, int max);
int		get_min2(t_dlist *lst, int min);

/*Utils*/
t_dlist	*ft_createnode(int data);
int		ft_tdsize(t_dlist *head);
void	print_dblist(t_dlist *lst);
void	print_dblist2(t_dlist *lst1, t_dlist *lst2);
void	free_list(t_dlist **head);
t_dlist	*reorder_stacks(t_dlist *stacka);

/*order less than 100*/
t_dlist *separte_stacks(t_dlist *stacka, t_dlist **stackb, int size, int high);
int		get_pos(int max, int min, int size, char *test);
t_dlist	*do_stackb(t_dlist *stackb, t_dlist **stacka);
t_dlist	*sortless100numbers(t_dlist *stacka, t_dlist **stackb);

/*main*/
int		checking_ifordered(t_dlist *stacka, int i);
int		find_number(t_dlist *stack, int number);

#endif