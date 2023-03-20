/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:10:09 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/20 11:48:42 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap_bonus.h"

int	checking_ifordered(t_dlist *lst, int i)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->data > lst->next->data && i == 1)
				return (0);
			else if (lst->data < lst->next->data && i == 2)
				return (0);
			lst = lst->next;
		}	
	}
	return (1);
}

int	find_number(t_dlist *stack, int number)
{
	int	i;

	i = 1;
	while (stack->prev)
		stack = stack->prev;
	while (stack)
	{
		if (stack->data == number)
			return (i);
		else if (!stack->next)
			break ;
		stack = stack->next;
		i++;
	}
	return (0);
}

t_utils	*start_utils(t_utils *utils)
{
	utils->rotate_total = 'c';
	utils->movements_t = 0;
	return (utils);
}

t_dlist	*check_order(t_dlist *stacka, t_dlist **stackb, t_utils *utils)
{
	char	*str;
	
	utils = start_utils(utils);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!ft_strncmp(str, "ra\n", 3))
			stacka = rotate(stacka, utils);
		else if (!ft_strncmp(str, "rb\n", 3))
			*stackb = rotate(*stackb, utils);
		else if (!ft_strncmp(str, "rr\n", 3))
		{
			stacka = rotate(stacka, utils);
			*stackb = rotate(*stackb, utils);
		}
		else if (!ft_strncmp(str, "rra\n", 4))
			stacka = r_rotate(stacka, utils);
		else if (!ft_strncmp(str, "rrb\n", 4))
			*stackb = r_rotate(*stackb, utils);
		else if (!ft_strncmp(str, "rrr\n", 4))
		{
			stacka = r_rotate(stacka, utils);
			*stackb = r_rotate(*stackb, utils);
		}
		else if (!ft_strncmp(str, "sa\n", 3))
			stacka = swap(stacka, utils);
		else if (!ft_strncmp(str, "sb\n", 3))
			*stackb = swap(*stackb, utils);
		else if (!ft_strncmp(str, "ss\n", 3))
		{
			stacka = swap(stacka, utils);
			*stackb = swap(*stackb, utils);
		}
		else if (!ft_strncmp(str, "pa\n", 3))
			stacka = push(stacka, stackb, utils);
		else if (!ft_strncmp(str, "pb\n", 3))
			*stackb = push(*stackb, &stacka, utils);
		free(str);
	}
	return (stacka);
}

int	main(int argc, char *argv[])
{
	t_dlist	*stacka;
	t_dlist	*stackb;
	t_utils	utils;

	if (argc < 2)
		return (0);
	checking_digits_bonus(argv);
	stacka = first_list_bonus(argv, argc);
	checking_list_bonus(stacka, argv);
	stackb = NULL;
	stacka = check_order(stacka, &stackb, &utils);
	if (checking_ifordered(stacka, 1) != 1)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_list(&stacka);
	return (0);
}