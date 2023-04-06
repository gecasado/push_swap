/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:46:41 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:46:43 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_ordered(t_list *stack, int asc)
{
	int	prev;

	prev = (int)stack->content;
	while (stack && ((asc && (int)stack->content >= prev) \
			|| (!asc && (int)stack->content <= prev)))
	{
		prev = (int)stack->content;
		stack = stack->next;
	}
	if (!stack)
		return (1);
	return (0);
}

long	get_last_disordered(t_list *stack, int n)
{
	int		i;
	int		*ord_array;
	long	last_pos;

	if (n < 2)
		return (n);
	i = 0;
	last_pos = 0;
	ord_array = lst_to_int_array(stack, n);
	while (stack && i < n)
	{
		if (ord_array[i] != (int)stack->content)
			last_pos = i;
		stack = stack->next;
		i++;
	}
	free(ord_array);
	return (last_pos + 1);
}

int	*lst_to_int_array(t_list *stack, int limit)
{
	int		*array;
	int		idx;
	int		stack_size;
	t_list	*copia;

	copia = NULL;
	copy_stack(&stack, &copia, limit);
	stack_size = ft_lstsize(copia);
	array = ft_memalloc(sizeof(int) * stack_size + 1);
	idx = 0;
	while (idx < stack_size)
		array[idx++] = get_min_value(&copia);
	free_single_stack(&copia);
	return (array);
}
