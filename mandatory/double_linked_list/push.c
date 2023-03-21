/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:28:12 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/19 17:02:00 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*push(t_dlist *lsti, t_dlist **lstd, t_utils *utils)
{
	if (!lstd)
		return (lsti);
	lsti = add_to_front((*lstd)->data, lsti);
	*lstd = delete_from_front(*lstd);
	if (utils->push == 'a')
		ft_printf("pa\n");
	else if (utils->push == 'b')
		ft_printf("pb\n");
	return (lsti);
}

t_dlist	*push_final(t_dlist *lsti, t_dlist **lstd, t_utils *utils)
{
	int		i;

	(void)utils;
	lsti = pushing_toa(lsti, *lstd);
	i = deletefromb(*lstd);
	while (i > 0)
	{
		ft_printf("pa\n");
		i--;
	}
	return (lsti);
}

t_dlist	*pushing_toa(t_dlist *lsta, t_dlist *lstb)
{
	int		i;
	t_dlist	*temp;
	t_dlist	*stackb;

	i = 0;
	if (!lstb)
		return (lsta);
	stackb = lstb;
	temp = NULL;
	while (i < ft_tdsize(stackb))
	{
		temp = ft_createnode(lstb->data);
		lsta->prev = temp;
		temp->next = lsta;
		lsta = temp;
		lstb = lstb->next;
		i++;
	}
	while (lsta->prev)
		lsta = lsta->prev;
	return (lsta);
	free_list(&temp);
}

int	deletefromb(t_dlist *lstb)
{
	t_dlist	*temp;
	int		i;

	i = 0;
	while (lstb)
	{
		if (lstb->next)
		{
			temp = lstb;
			lstb = lstb->next;
			temp->next = NULL;
			lstb->prev = NULL;
			free(temp);
		}
		else
		{
			free(lstb);
			break ;
		}
		i++;
	}
	i++;
	return (i);
}
