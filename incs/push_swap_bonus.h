/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:50:39 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/19 16:10:07 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/incs/ft_printf.h"
# include "../libft/incs/get_next_line.h"
# include "../libft/incs/get_next_line_bonus.h"
# include "push_swap.h"

/*starting list bonus*/
void	error_func_bonus(t_dlist **list, int a, char *argv[], int i);
int		checking_digits_bonus(char **argv);
t_dlist	*first_list_bonus(char **argv, int argc);
int		checking_list_bonus(t_dlist *lst,  char *argv[]);

#endif