/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gecasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 20:04:20 by gecasado          #+#    #+#             */
/*   Updated: 2022/04/04 18:53:05 by gecasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <strings.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*cklist_a;
	t_list	*cklist_b;
}				t_stacks;

int			ft_isdigit(int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr(char *s);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
long		ft_atoilong(const char *str);
void		ft_lstadd_back(t_list **alst, t_list *new);
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
t_list		*ft_lstlast(t_list *lst);
void		ft_putendl_fd(char *s, int fd);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		*ft_memalloc(size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_lstrem(t_list **alst, void *content);
t_stacks	*init_stacks(void);
void		exit_error(void);
void		check_valid_number(char *str);
void		check_duplicates(t_list **alst, long number);
int			parser_numbers(t_stacks **s, char **argv, int argc);
int			stack_is_ordered(t_list *stack, int asc);
void		stack_swap(t_list **s);
void		op_swap(t_stacks **s, char *op);
void		stack_rotate(t_list **s);
void		op_rotate(t_stacks **s, char *op);
void		sort3(t_stacks **s);
void		copy_stack(t_list **src, t_list **dst, int limit);
int			get_min_value(t_list **l);
void		free_single_stack(t_list **l);
int			*lst_to_int_array(t_list *stack, int limit);
long		get_last_disordered(t_list *stack, int n);
void		stack_push_a(t_stacks **s);
void		stack_push_b(t_stacks **s);
void		op_push(t_stacks **s, char *op);
void		stack_reverse_rotate(t_list **s);
void		op_reverse_rotate(t_stacks **s, char *op);
void		process_chunk_a(t_stacks **s, int cksize, int new_cksize, \
		int first);
void		from_a_to_b(t_stacks **s, int first_exec);
void		from_b_to_a(t_stacks **s);
void		process_chunk_b(t_stacks **s, int cksize, int new_cksize);
void		sort_numbers(t_stacks **s);
void		free_stacks(t_stacks **s);

#endif
