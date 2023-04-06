/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:53:33 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:53:52 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_push(t_stacks **s, char *op)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_strncmp(op, "pa", 2) == 0)
		stack_push_a(&stacks);
	else if (ft_strncmp(op, "pb", 2) == 0)
		stack_push_b(&stacks);
	ft_putendl_fd(op, 1);
}

void	stack_push_a(t_stacks **s)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_lstsize(stacks->stack_b) < 1)
		return ;
	ft_lstadd_front(&stacks->stack_a, ft_lstnew(stacks->stack_b->content));
	ft_lstrem(&stacks->stack_b, stacks->stack_a->content);
}

void	stack_push_b(t_stacks **s)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_lstsize(stacks->stack_a) < 1)
		return ;
	ft_lstadd_front(&stacks->stack_b, ft_lstnew(stacks->stack_a->content));
	ft_lstrem(&stacks->stack_a, stacks->stack_b->content);
}

void	op_reverse_rotate(t_stacks **s, char *op)
{
	t_stacks	*stacks;

	stacks = *s;
	if (ft_strncmp(op, "rra", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		stack_reverse_rotate(&stacks->stack_a);
	if (ft_strncmp(op, "rrb", 3) == 0 || ft_strncmp(op, "rrr", 3) == 0)
		stack_reverse_rotate(&stacks->stack_b);
	ft_putendl_fd(op, 1);
}

void	stack_reverse_rotate(t_list **s)
{
	t_list	*stack;
	t_list	*last_elem;
	t_list	*aux;

	stack = *s;
	if (ft_lstsize(stack) < 2)
		return ;
	aux = stack;
	while (aux->next->next)
		aux = aux->next;
	last_elem = aux->next;
	aux->next = NULL;
	last_elem->next = stack;
	*s = last_elem;
}
