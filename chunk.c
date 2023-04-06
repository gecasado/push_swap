/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:37:55 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:38:02 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_mid_num(t_list *stack, int limit)
{
	int	mid_number;
	int	*array;

	array = lst_to_int_array(stack, limit);
	mid_number = array[limit / 2];
	free(array);
	return (mid_number);
}

void	process_chunk_a(t_stacks **s, int cksize, int new_cksize, int first)
{
	t_stacks	*stacks;
	int			mid_num;
	int			rotate_count;

	stacks = *s;
	mid_num = get_mid_num(stacks->stack_a, cksize);
	rotate_count = 0;
	while (new_cksize)
	{
		if ((int)stacks->stack_a->content < mid_num)
		{
			op_push(&stacks, "pb");
			new_cksize--;
		}
		else if ((int)ft_lstlast(stacks->stack_a)->content < mid_num && first)
			op_reverse_rotate(&stacks, "rra");
		else
		{
			op_rotate(&stacks, "ra");
			rotate_count++;
		}
	}
	while ((!stacks->cklist_a || ft_lstsize(stacks->stack_a)
			> (int)stacks->cklist_a->content) && rotate_count--)
		op_reverse_rotate(&stacks, "rra");
}

void	process_chunk_b(t_stacks **s, int cksize, int new_cksize)
{
	t_stacks	*stacks;
	int			mid_num;
	int			rotate_count;

	stacks = *s;
	mid_num = get_mid_num(stacks->stack_b, cksize);
	rotate_count = 0;
	while (new_cksize)
	{
		if ((int)stacks->stack_b->content > mid_num)
		{
			op_push(&stacks, "pa");
			new_cksize--;
		}
		else
		{
			op_rotate(&stacks, "rb");
			rotate_count++;
		}
	}
	while (ft_lstsize(stacks->cklist_b) > 1 && rotate_count--)
		op_reverse_rotate(&stacks, "rrb");
}
