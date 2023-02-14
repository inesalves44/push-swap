/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:18:17 by idias-al          #+#    #+#             */
/*   Updated: 2023/02/14 17:18:19 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/incs/ft_printf.h"
# include "../ft_printf/incs/get_next_line.h"
# include "../ft_printf/incs/get_next_line_bonus.h"

typedef struct  s_list
{
    int data;
    struct  s_list  *next;
}   t_list;

#endif