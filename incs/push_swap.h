/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:18:17 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/28 18:01:49 by idias-al         ###   ########.fr       */
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

t_dlist *annalysing_stack(t_dlist *stacka, t_dlist **stackb);
t_dlist	*sort100numbers(t_dlist *stacka, t_dlist **stackb);

/*Utils*/
t_dlist	*ft_createnode(int data);
int		ft_tdsize(t_dlist *head);
void	print_dblist(t_dlist *lst);
void	free_list(t_dlist **head);
t_dlist	*reorder_stacks(t_dlist *stacka);
int		checking_ifordered(t_dlist *stacka, int i);

/*swap*/
t_dlist	*swap(t_dlist *test, int a);
void	swap_total(t_dlist *stacka, t_dlist *stackb);

/*insert and delete*/
t_dlist	*stack_creation(char *args, t_dlist *head);
t_dlist	*first_list(char **argv, int argc);
int		checking_list(t_dlist *lst);

/*create stack a*/
t_dlist	*create_stack(t_dlist *lst);
t_dlist	*stack_creation_ind(t_dlist *head);

/*push*/
t_dlist	*pushing_toa(t_dlist *lsta, t_dlist *lstb);
t_dlist	*deletefromstack(t_dlist *lsta, int size, int a);
t_dlist	*deletefromb(t_dlist *lstb);
t_dlist	*pushing_to_stack(t_dlist *lsta, t_dlist *lstb, int size);

/*rotate*/
t_dlist	*rotate(t_dlist *head, int a);
void	rotate_total(t_dlist **stack_a, t_dlist **stack_b);
t_dlist	*r_rotate(t_dlist *lst, int a);
void	r_rotate_total(t_dlist **stack_a, t_dlist **stack_b);

/*sort 3 and 5 numbers*/
t_dlist	*sort3numbers(t_dlist *stacka);
t_dlist	*sort3numbers_rev(t_dlist *stackb);
t_dlist	*check_top(t_dlist *lsta, t_dlist **stackb, int min, int min2);
t_dlist	*sort5numbers(t_dlist *stacka, t_dlist **stackb);
t_dlist	*sort5numbers_rev(t_dlist *stackb, t_dlist **stacka);

/*max*/
int		get_max(t_dlist *lst);
int		get_min(t_dlist *lst);
int		get_max2(t_dlist *lst, int max);
int	get_min2(t_dlist *lst, int min);

#endif