/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:47:05 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:48:35 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_valid_number(char *str)
{
	if (!ft_isdigit(*str) && ft_strncmp(str++, "-", 1) != 0)
		exit_error();
	if (strlen(str) <= 0)
		exit_error();
	while (*str)
	{
		if (!ft_isdigit(*(str++)))
			exit_error();
	}
}

void	check_duplicates(t_list **alst, long number)
{
	t_list	*lista;

	lista = *alst;
	if (lista)
	{
		while (lista->next != NULL)
		{
			if ((int)lista->content == number)
				exit_error();
			lista = lista->next;
		}
		if ((int)lista->content == number)
			exit_error();
	}
}
