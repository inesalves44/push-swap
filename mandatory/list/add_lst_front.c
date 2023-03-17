/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_lst_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:40:19 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/16 16:22:09 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*add_to_front(int data, t_dlist *lsti)
{
	if (!lsti)
		lsti = ft_createnode(data);
	else
	{
		lsti->prev = ft_createnode(data);
		lsti->prev->next = lsti;
		lsti = lsti->prev;
	}
	while (lsti->prev)
		lsti = lsti->prev;
	return (lsti);
}
