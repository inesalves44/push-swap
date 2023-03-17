/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:03:15 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/17 12:21:11 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	free_list(t_dlist **head)
{
	while ((*head)->prev)
		*head = (*head)->prev;
	if (head)
	{
		while (*head)
		{
			(*head)->data = 0;
			if ((*head)->next)
			{
				(*head) = (*head)->next;
				free((*head)->prev);
			}
			else
			{
				free(*head);
				break ;
			}
		}
	}
}
