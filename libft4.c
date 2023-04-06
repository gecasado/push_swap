/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:45:38 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:45:53 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_lstrem(t_list **alst, void *content)
{
	t_list	*lst;
	t_list	*lst_prev;

	if (!*alst)
		return ;
	lst = *alst;
	lst_prev = *alst;
	while (lst && lst->content != content)
	{
		lst_prev = lst;
		lst = lst->next;
	}
	if (lst->content == content)
	{
		if (lst == lst_prev)
			*alst = lst->next;
		else
			lst_prev->next = lst->next;
		lst->content = 0;
		free(lst);
	}
}
