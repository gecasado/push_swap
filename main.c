/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:46:14 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:46:33 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	get_mid_num(t_list *stack, int limit)
{
	int	mid_number;
	int	*array;

	array = lst_to_int_array(stack, limit);
	mid_number = array[limit / 2];
	free(array);
	return (mid_number);
}*/

int	get_min_value(t_list **l)
{
	t_list	*lista;
	void	*min;

	lista = *l;
	min = lista->content;
	while (lista)
	{
		if ((int)lista->content < (int)min)
			min = lista->content;
		lista = lista->next;
	}
	lista = *l;
	ft_lstrem(&lista, min);
	*l = lista;
	return ((int)min);
}

int	parse_numbers(t_stacks **s, char **argv, int argc)
{
	t_stacks	*stacks;
	long		nbr;

	stacks = *s;
	while (argc-- > 0)
	{
		check_valid_number(*argv);
		nbr = ft_atoilong(*argv);
		if (nbr < -2147483648 || nbr > 2147483647)
			exit_error();
		check_duplicates(&stacks->stack_a, nbr);
		ft_lstadd_back(&stacks->stack_a, ft_lstnew((void *)nbr));
		argv++;
	}
	return (0);
}

void	exit_error(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void	sort_3numbers(t_stacks **s)
{
	t_stacks	*stacks;

	stacks = *s;
	if ((long)stacks->stack_a->content
		< (long)ft_lstlast(stacks->stack_a)->content)
		op_swap(&stacks, "sa");
	while ((long)stacks->stack_a->content
		> (long)ft_lstlast(stacks->stack_a)->content)
		op_rotate(&stacks, "ra");
	if ((long)stacks->stack_a->content > (long)stacks->stack_a->next->content)
		op_swap(&stacks, "sa");
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (0);
	stacks = init_stacks();
	parse_numbers(&stacks, ++argv, --argc);
	if (stack_is_ordered(stacks->stack_a, 1))
		return (0);
	if (ft_lstsize(stacks->stack_a) == 3)
		sort_3numbers(&stacks);
	else
		sort_numbers(&stacks);
	free_stacks(&stacks);
	return (0);
}
