/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaprotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:54:36 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:54:39 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(t_stacks **s, char *op)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_strncmp(op, "ra", 2) == 0 || ft_strncmp(op, "rr", 2) == 0)
		stack_rotate(&stacks->stack_a);
	if (ft_strncmp(op, "rb", 2) == 0 || ft_strncmp(op, "rr", 2) == 0)
		stack_rotate(&stacks->stack_b);
	ft_putendl_fd(op, 1);
}

void	stack_rotate(t_list **s)
{
	t_list	*stack;
	t_list	*first_elem;

	stack = *s;
	if (ft_lstsize(stack) < 2)
		return ;
	first_elem = stack;
	stack = stack->next;
	first_elem->next = NULL;
	ft_lstlast(stack)->next = first_elem;
	*s = stack;
}

void	op_swap(t_stacks **s, char *op)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_strncmp(op, "sa", 2) == 0 || ft_strncmp(op, "ss", 2) == 0)
		stack_swap(&stacks->stack_a);
	if (ft_strncmp(op, "sb", 2) == 0 || ft_strncmp(op, "ss", 2) == 0)
		stack_swap(&stacks->stack_b);
	ft_putendl_fd(op, 1);
}

void	stack_swap(t_list **s)
{
	t_list	*stack;
	int		*aux;

	stack = *s;
	if (ft_lstsize(stack) < 2)
		return ;
	aux = stack->next->content;
	stack->next->content = stack->content;
	stack->content = aux;
}
