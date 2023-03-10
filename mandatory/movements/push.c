/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:28:12 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/09 15:54:07 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_dlist	*push(t_dlist *lsti, t_dlist **lstd, char **str)
{
	t_dlist	*temp;
	char	*str2;

	temp = *lstd;
	lsti = pushing_to_stack(&temp, lsti);
	temp = deletefromstack(temp);
	str2 = mod_strdup("pa\n");
	*str = mod_strjoin(*str, str2);
	free(str2);
	*lstd = temp;
	return (lsti);
}

t_dlist	*push_final(t_dlist *lsti, t_dlist **lstd, char **str)
{
	t_dlist	*temp;
	int		i;
	char	*str2;

	temp = *lstd;
	lsti = pushing_toa(lsti, temp);
	i = deletefromb(temp);
	while (i > 0)
	{
		str2 = ft_strdup("pa\n");
		*str = mod_strjoin(*str, str2);
		free(str2);
		str2 = NULL;
		i--;
	}
	*lstd = NULL;
	return (lsti);
}

t_dlist	*push_b(t_dlist *lsti, t_dlist **lstd, char **str)
{
	t_dlist	*temp;
	char	*str2;

	temp = *lstd;
	lsti = pushing_to_stack(&temp, lsti);
	temp = deletefromstack(temp);
	str2 = mod_strdup("pb\n");
	*str = mod_strjoin(*str, str2);
	free(str2);
	*lstd = temp;
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

t_dlist	*pushing_to_stack(t_dlist **stackd, t_dlist *lsti)
{
	t_dlist *lstd;

	lstd = *stackd;
	if (!lsti)
		lsti = ft_createnode(lstd->data);
	else
	{
		lsti->prev = ft_createnode(lstd->data);
		lsti->prev->next = lsti;
		lsti = lsti->prev;
	}
	while (lstd->prev)
		lstd = lstd->prev;
	while (lsti->prev)
		lsti = lsti->prev;
	*stackd = lstd;
	return (lsti);
}

t_dlist	*deletefromstack(t_dlist *lsta)
{
	t_dlist	*temp;

	temp = lsta;
	if (!lsta->next)
		lsta = NULL;
	else
		lsta = lsta->next;
	temp->next = NULL;
	lsta->prev = NULL;
	free(temp);
	while (lsta->prev)
		lsta = lsta->prev;
	return (lsta);
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
