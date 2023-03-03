
/*t_dlist	*lsta;
	t_dlist	*aux;
	int		help2;
	int		help;
	int		mid;

	lsta = *stacka;
	aux = *temp;
	help = 0;
	mid = 0;
	if (get_max(stackb) % 2 != 0 && aux->next)
		mid = (get_max(stackb) - aux->next->data) / 2 + aux->next->data + 1;
	else if (get_max(stackb) % 2 == 0 && aux->next)
		mid = (get_max(stackb) - aux->next->data) / 2 + aux->next->data;
	else if (!aux->next && get_max(stackb) % 2 == 0)
		mid = get_max(stackb) / 2;
	else if (!aux->next && get_max(stackb) % 2 != 0)
		mid = get_max(stackb) / 2 + 1;
	if (aux->next)
		help2 = get_max(stackb) - aux->next->data;
	else
		help2 = get_max(stackb) / 2;
	while (help2 >= 1)
	{
		print_dblist2(lsta, stackb);
		if (stackb->data > mid)
		{
			lsta = push(lsta, &stackb, 'a', 'n');
			if (lsta->next->data < lsta->data)
				lsta = swap(lsta, 1);
		}
		else
		{
			stackb = rotate(stackb, 1);
			help++;
		}
		help2--;
	}
	print_dblist2(lsta, stackb);
	while (help-- > 0 && aux->next)
		stackb = r_rotate(stackb, 2);
	if (get_max(stackb) % 2 != 0 && aux->next)
		mid = (get_max(stackb) - aux->next->data) / 2 + aux->next->data + 1;
	else if (get_max(stackb) % 2 == 0 && aux->next)
		mid = (get_max(stackb) - aux->next->data) / 2 + aux->next->data;
	else if (!aux->next && get_max(stackb) % 2 == 0)
		mid = get_max(stackb) / 2;
	else if (!aux->next && get_max(stackb) % 2 != 0)
		mid = get_max(stackb) / 2 + 1;
	if (aux->next)
		help2 = get_max(stackb) - aux->next->data;
	else
		help2 = get_max(stackb);
	print_dblist2(lsta, stackb);
	while (help2-- > 0)
	{
		print_dblist2(lsta, stackb);
		lsta = push(lsta, &stackb, 'a', 'n');
		if (lsta->next->data < lsta->data)
			lsta = swap(lsta, 1);
	}
	print_dblist2(lsta, stackb);
	if (ft_tdsize(aux) > 1)
		aux = deletefromstack(aux);
	*stacka = lsta;
	*temp = aux;*/
t_dlist	*pass_to_a(t_dlist *stackb, t_dlist **stacka, int size)
{
	int		i;
	int		j;
	t_dlist	*lsta;

	lsta = *stacka;
	i = 0;
	j = find_maxnumberi(stackb);
	if (j > (ft_tdsize(stackb) / 2))
	{
		while (i < size)
		{
			stackb = r_rotate(stackb, 2);
			if (find_maxnumberi(stackb) == 1)
				break ;
			if (i > 0 && stackb->data < stackb->next->data)
				stackb = swap(stackb, 2);
			i++;
		}
	}
	i = 0;
	int aux;
	aux = 0;
	while (i < size)
	{
		if (find_maxnumberi(stackb) <= 2)
		{
			/*if (lsta->data < stackb->data)
			{
				lsta = rotate(lsta, 1);
				lsta = pushing_to_stack(stackb, lsta, 2);
				stackb = deletefromstack(stackb, 2, 1);
				lsta = r_rotate(lsta, 1);
				i++;
			}*/
			if (stackb->data > stackb->next->data)
			{
				lsta = pushing_to_stack(stackb, lsta, 2);
				stackb = deletefromstack(stackb, 2, 1);
				i++;
			}
			if (aux > 0)
			{
				while (aux--)
					stackb = rotate(stackb, 2);
			}
			else
				stackb = swap(stackb, 2);
		}
		else
		{
			while (find_maxnumberi(stackb) > 2)
			{
				stackb = r_rotate(stackb, 2);
				aux++;	
			}
		}
	}
	while (lsta->prev)
		lsta = lsta->prev;
	*stacka = lsta;
	return (stackb);
}

/*t_dlist	*annalysing_stack_b(t_dlist *stackb, t_dlist **stacka)
{
	if (checking_ifordered(stackb, 2) == 1)
		return(stackb);
	if (ft_tdsize(stackb) < 3)
		stackb = swap(stackb, 1);
	else if (ft_tdsize(stackb) < 4)
		stackb = sort3numbers_rev(stackb);
	else if (ft_tdsize(stackb) < 6)
		stackb = sort5numbers_rev(stackb, stacka);
	else if (ft_tdsize(stackb) < 11)
		stackb = sort10numbers_rev(stackb, stacka);
	else if (ft_tdsize(stackb) < 101)
		stackb = sort100numbers_rev(stackb, stacka);
	return (stackb);
}*/

t_dlist	*separate_stackb(t_dlist *stackb, int size, t_dlist **stacka)
{
	t_dlist	*lsta;

	lsta = *stacka;
	if (ft_tdsize(stackb) == 6 && stackb->data == get_max(stackb))
	{
		lsta = pushing_to_stack(stackb, lsta, 2);
		stackb = deletefromstack(stackb, 2, 1);
		*stacka = lsta;
		return(stackb);
	}
	else if (ft_tdsize(stackb) == 7 && (stackb->data == get_max2(stackb, get_max(stackb)) || stackb->data == get_max(stackb)))
	{
		int aux = get_max(stackb);
		lsta = pushing_to_stack(stackb, lsta, 2);
		stackb = deletefromstack(stackb, 2, 1);
		*stacka = lsta;
		if (lsta->data == aux)
			return (stackb);
		stackb = separate_stackb(stackb, size, stacka);
	}
	if (stackb->data >= size && ft_tdsize(stackb) > 7)
	{
		lsta = pushing_to_stack(stackb, lsta, 2);
		stackb = deletefromstack(stackb, 2, 1);
		*stacka = lsta;
		stackb = separate_stackb(stackb, size, stacka);
	}
	while (stackb)
	{
		if (stackb->data > size)
			break ;
		else if (!stackb->next)
			return (stackb);
		stackb = stackb->next;
	}
	while (stackb->prev)
		stackb = stackb->prev;
	while (lsta->prev)
		lsta = lsta->prev;
	stackb = rotate(stackb, 0);
	*stacka = lsta;
	stackb = separate_stackb(stackb, size, stacka);
	return (stackb);
}

t_dlist	*separate_stacka(t_dlist *stacka, int size, t_dlist **stackb)
{
	t_dlist	*lstb;

	lstb = *stackb;
	if (ft_tdsize(stacka) == 6 && stacka->data == get_min(stacka))
	{
		lstb = pushing_to_stack(stacka, lstb, 2);
		stacka = deletefromstack(stacka, 2, 2);
		*stackb = lstb;
		return (stacka); 
	}
	else if (ft_tdsize(stacka) == 7 && (stacka->data == get_min2(stacka, get_min(stacka)) || stacka->data == get_min(stacka)))
	{
		lstb = pushing_to_stack(stacka, lstb, 2);
		stacka = deletefromstack(stacka, 2, 2);
		*stackb = lstb;
		if (stacka->data == get_min(stacka))
			return (stacka);
		stacka = separate_stacka(stacka, size, stackb); 
	}
	if (stacka->data <= size && ft_tdsize(stacka) > 7)
	{
		lstb = pushing_to_stack(stacka, lstb, 2);
		stacka = deletefromstack(stacka, 2, 2);
		*stackb = lstb;
		stacka = separate_stacka(stacka, size, stackb); 
	}
	while (stacka)
	{
		if (stacka->data < size)
			break ;
		else if (!stacka->next)
		{
			*stackb = lstb;
			return (stacka);
		}
		stacka = stacka->next;
	}
	while (stacka->prev)
		stacka = stacka->prev;
	stacka = rotate(stacka, 1);
	if (lstb)
	{
		while (lstb->prev)
			lstb =lstb->prev;
	}
	*stackb = lstb;
	stacka = separate_stacka(stacka, size, stackb);
	return (stacka);
}

t_dlist	*sort10numbers_rev(t_dlist *stackb, t_dlist **stacka)
{
	int	size;
	t_dlist *lsta;

	lsta = *stacka;
	size = (get_max(stackb) - get_min(stackb)) / 2 + get_min(stackb);
	stackb =  separate_stackb(stackb, size, stacka);
	lsta = *stacka;
	while (stackb->prev)
		stackb = stackb->prev;
	while (lsta->prev)
		lsta = lsta->prev;
	*stacka = lsta;
	lsta = *stacka;
	if (checking_ifordered(stackb, 2) == 0)
		stackb = annalysing_stack_b(stackb, stacka);
	lsta = *stacka;
	while (lsta->prev)
		lsta = lsta->prev;
	while (stackb->prev)
		stackb = stackb->prev;
	if (checking_ifordered(lsta, 1) == 0)
		lsta = annalysing_stack(lsta, &stackb);
	while (lsta->prev)
		lsta = lsta->prev;
	while (stackb->prev)
		stackb = stackb->prev;
	*stacka = lsta;
	return (stackb);
}

t_dlist	*sort100numbers_rev(t_dlist *stackb, t_dlist **stacka)
{
	int		size;
	t_dlist	*lsta;
	
	size = (get_max(stackb) - get_min(stackb)) / 2 + get_min(stackb);
	if (ft_tdsize(stackb) > 5)
		stackb = separate_stackb(stackb, size, stacka);
	lsta = *stacka;
	while (lsta->prev)
		lsta = lsta->prev;
	while (stackb->prev)
		stackb = stackb->prev;
	*stacka = lsta;
	if (checking_ifordered(stackb, 2) != 1)
		stackb = annalysing_stack_b(stackb, stacka);
	while (lsta->prev)
		lsta = lsta->prev;
	while (stackb->prev)
		stackb = stackb->prev;
	*stacka = lsta;
	if (checking_ifordered(lsta, 1) != 1)
		lsta = annalysing_stack(lsta, &stackb);
	while (lsta->prev)
		lsta = lsta->prev;
	while (stackb->prev)
		stackb = stackb->prev;
	lsta = *stacka;
	return (stackb);
}

t_dlist	*sort100numbers(t_dlist *stacka, t_dlist **stackb)
{
	int		size;
	t_dlist	*lstb;

	size = (get_max(stacka) - get_min(stacka)) / 2 + get_min(stacka);
	if (ft_tdsize(stacka) > 5)
		stacka = separate_stacka(stacka, size, stackb);
	lstb = *stackb;
	while (stacka->prev)
		stacka = stacka->prev;
	while (lstb->prev)
		lstb = lstb->prev;
	*stackb = lstb;
	if (checking_ifordered(stacka, 1) == 0)
		stacka = annalysing_stack(stacka, stackb);
	lstb = *stackb;
	while (stacka->prev)
		stacka = stacka->prev;
	while (lstb->prev)
		lstb = lstb->prev;
	if (checking_ifordered(lstb, 2) == 0)
		lstb = annalysing_stack_b(lstb, &stacka);
	*stackb = lstb;
	while (stacka->prev)
		stacka = stacka->prev;
	while (lstb->prev)
		lstb = lstb->prev;
	lstb = *stackb;
	while (stacka->prev)
		stacka = stacka->prev;
	return (stacka);
}


t_dlist	*sort10numbers(t_dlist *stacka, t_dlist **stackb)
{
	int	size;
	t_dlist *lstb;

	lstb = *stackb;
	size = (get_max(stacka) - get_min(stacka)) / 2 + get_min(stacka);
	stacka =  separate_stacka(stacka, size, stackb);
	lstb = *stackb;
	while (stacka->prev)
		stacka = stacka->prev;
	while (lstb->prev)
		lstb = lstb->prev;
	*stackb = lstb;
	if (checking_ifordered(stacka, 1) == 0)
		stacka = annalysing_stack(stacka, stackb);
	lstb = *stackb;
	while (stacka->prev)
		stacka = stacka->prev;
	while (lstb->prev)
		lstb = lstb->prev;
	if (checking_ifordered(lstb, 2) == 0)
		lstb = annalysing_stack_b(lstb, &stacka);
	while (stacka->prev)
		stacka = stacka->prev;
	while (lstb->prev)
		lstb = lstb->prev;
	*stackb = lstb;
	while (stacka->prev)
		stacka = stacka->prev;
	return (stacka);
}