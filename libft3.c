/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:45:10 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:45:28 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		write(fd, "\n", 1);
	}
}

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size)
	{
		ptr = malloc(size);
		if (ptr)
		{
			ft_bzero(ptr, size);
			return (ptr);
		}
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
