/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idias-al <idias-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:05:55 by idias-al          #+#    #+#             */
/*   Updated: 2023/03/03 18:02:58 by idias-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

int	main(void)
{
	char *str;
	char *str1;
	int		i;
	int		j;

	i = 0;
	j = 0;
	//int fd = open("txt", O_RDONLY);
	str1 = get_next_line(0);
	j++;
	while (1)
	{	
			str = get_next_line(0);
			if (!str)
				break ;
			if (!ft_strncmp(str, "ra", 2))
				if (!ft_strncmp(str1, "rb", 2))
					i++;
			else if (!ft_strncmp(str, "rb", 2))
				if (!ft_strncmp(str1, "ra", 2))
					i++;
			else if (!ft_strncmp(str, "rra", 2))
				if (!ft_strncmp(str1, "rrb", 2))
					i++;
			else if (!ft_strncmp(str, "rrb", 2))
				if (!ft_strncmp(str1, "rra", 2))
					i++;
			else if (!ft_strncmp(str, "sa", 2))
				if (!ft_strncmp(str1, "sb", 2))
					i++;
			else if (!ft_strncmp(str, "sb", 2))
				if (!ft_strncmp(str1, "sa", 2))
					i++;
			str1 = str;
			j++;
	}
	printf("%d\n", i);
}
