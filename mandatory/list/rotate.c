/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:58:30 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/17 17:16:35 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*rotate(t_dlist *lst, t_utils *utils)
{
	int		temp;

	temp = lst->data;
	while (lst)
	{
		if (lst->next)
			lst->data = lst->next->data;
		else
		{
			lst->data = temp;
			break ;
		}
		lst = lst->next;
	}
	if (utils->rotate_total == 'a')
		ft_printf("ra\n");
	else if (utils->rotate_total == 'b')
		ft_printf("rb\n");
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

t_dlist	*r_rotate(t_dlist *lst, t_utils *utils)
{
	int		temp;

	while (lst->next)
		lst = lst->next;
	temp = lst->data;
	while (lst)
	{
		if (lst->prev)
			lst->data = lst->prev->data;
		else
		{
			lst->data = temp;
			break ;
		}
		lst = lst->prev;
	}
	if (utils->rotate_total == 'a')
		ft_printf("rra\n");
	else if (utils->rotate_total == 'b')
		ft_printf("rrb\n");
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
