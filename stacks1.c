/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:54:05 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:54:09 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_stacks(void)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->cklist_a = NULL;
	stacks->cklist_b = NULL;
	return (stacks);
}

void	free_stacks(t_stacks **s)
{
	t_stacks	*stacks;
	t_list		*stack_a;
	t_list		*stack_b;
	t_list		*cklist_a;
	t_list		*cklist_b;

	stacks = *s;
	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	cklist_a = stacks->cklist_a;
	cklist_b = stacks->cklist_b;
	free_single_stack(&stack_a);
	free_single_stack(&stack_b);
	free_single_stack(&cklist_a);
	free_single_stack(&cklist_b);
	free(stacks);
}

void	free_single_stack(t_list **l)
{
	t_list	*stack;

	stack = *l;
	while (stack)
		ft_lstrem(&stack, stack->content);
}

void	copy_stack(t_list **src, t_list **dst, int limit)
{
	t_list	*source;
	int		i;

	source = *src;
	i = 0;
	while (source && i < limit)
	{
		ft_lstadd_back(&(*dst), ft_lstnew(source->content));
		source = source->next;
		i++;
	}
}
