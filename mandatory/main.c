/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:56:25 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/07 13:43:57 by idias-al         ###   ########.fr       */
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
}

t_dlist	*annalysing_stack(t_dlist *stacka, t_dlist **stackb)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if(!str)
		return (NULL);
	str[0] = '\0';
	if (checking_ifordered(stacka, 1) == 1)
	{
		free_list(&stacka);
		exit(EXIT_SUCCESS);
	}
	if (ft_tdsize(stacka) < 3)
		stacka = swap(stacka, 1, &str);
	else if (ft_tdsize(stacka) < 4)
		stacka = sort3numbers(stacka, &str);
	else if (ft_tdsize(stacka) < 6)
		stacka = sort5numbers(stacka, stackb, &str);
	else if (ft_tdsize(stacka) <= 100)
		stacka = sortless100numbers(stacka, stackb, &str);
	int i = 0;
	int count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	printf("%s", str);
	//treating_string(str, count);
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
