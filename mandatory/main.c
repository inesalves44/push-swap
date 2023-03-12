/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/12 14:34:02 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	checking_ifordered(t_dlist *lst, int i)
{
	if (lst)
	{
		while (lst->next)
		{
			if (lst->data > lst->next->data && i == 1)
			{
				ft_printf("%d\n", lst->data);
				return (0);
			}
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

void	treating_string(char *str, int count)
{
	char	**args;
	int		i;

	args = ft_split(str, '\n');
	i = 0;
	while (i < count - 1)
	{
		if (!ft_strncmp(args[i], "ra", 2) || !ft_strncmp(args[i], "rb", 2))
		{
			if ((!ft_strncmp(args[i + 1], "rb", 2) && !ft_strncmp(args[i], "ra", 2)) || (!ft_strncmp(args[i + 1], "ra", 2) && !ft_strncmp(args[i], "rb", 2)))
			{
				ft_printf("rr");
				i++;
			}
			else
				ft_printf("%s", args[i]);
		}
		else if (!ft_strncmp(args[i], "rra", 3) || !ft_strncmp(args[i], "rrb", 3))
		{	
			if ((!ft_strncmp(args[i + 1], "rrb", 3)&& !ft_strncmp(args[i], "rra", 3)) || (!ft_strncmp(args[i + 1], "rra", 3) && !ft_strncmp(args[i], "rrb", 3)))
			{
				ft_printf("rrr");
				i++;
			}
			else
				ft_printf("%s", args[i]);
		}
		else if (!ft_strncmp(args[i], "sa", 2) || !ft_strncmp(args[i], "sb", 2))
		{	
			if ((!ft_strncmp(args[i + 1], "sb", 3)&& !ft_strncmp(args[i], "sa", 2)) || (!ft_strncmp(args[i + 1], "sa", 2) && !ft_strncmp(args[i], "sb", 2)))
			{
				ft_printf("ss");
				i++;
			}
			else
				ft_printf("%s", args[i]);
		}
		else
			ft_printf("%s", args[i]);
		ft_printf("\n");
		i++;
	}
	ft_printf("%s", args[i]);
	ft_printf("\n");
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

t_dlist	*annalysing_stack(t_dlist *stacka, t_dlist **stackb)
{
	t_utils	utils;
	int		i;
	int		count;
	char	*str;

	str = NULL;
	utils = creting_struck(stacka);
	if (checking_ifordered(stacka, 1) == 1)
	{
		free_list(&stacka);
		free(str);
		exit(EXIT_SUCCESS);
	}
	if (ft_tdsize(stacka) < 3)
		stacka = swap(stacka, &str);
	else if (ft_tdsize(stacka) < 4)
		stacka = sort3numbers(stacka, &utils, &str);
	else if (ft_tdsize(stacka) < 6)
		stacka = sort5numbers(stacka, stackb, &utils, &str);
	else if (ft_tdsize(stacka) <= 100)
		stacka = sort100numbers(stacka, stackb, &utils, &str);
	else if (ft_tdsize(stacka) <= 500)
		stacka = sort500numbers(stacka, stackb, &utils, &str);
	i = 0;
	count = 0;
	while (str[i++] != '\0')
		if (str[i] == '\n')
			count++;
	if (count == 1)
		ft_printf("%s", str);
	else
		//treating_string(str, count);
	free(str);
	return (stacka);
}

int	main(int argc, char *argv[])
{
	t_dlist	*lst;
	t_dlist	*stacka;
	t_dlist	*stackb;

	if (argc < 2)
	{
		ft_printf("Error\n");
		return (1);
	}
	lst = first_list(argv, argc);
	while (lst->prev)
		lst = lst->prev;
	stacka = create_stack(lst);
	free_list(&lst);
	if (!stacka)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	stackb = NULL;
	stacka = annalysing_stack(stacka, &stackb);
	free_list(&stacka);
	return (0);
}
