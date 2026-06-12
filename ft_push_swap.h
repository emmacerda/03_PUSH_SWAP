/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:09:43 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 10:28:19 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "ft_dprintf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

struct s_data
{
	int		flag_bench;
	int		flag;
	int		check_flag;
	int		count;
	int		base;
	int		digit_parcourus;
	float	disorder;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
};

void	ft_error(void);
void	is_valid_range(char *str);
int		ft_is_double_flag(char *argv[]);
void	ft_is_number(char *argv[], int i, int ii);
int		main(int argc, char *argv[]);
int		ft_dprintf(int fd, const char *str, ...);
t_list	*ft_checkarg(char *argv[]);
t_list	*ft_create_stack_a(char *argv[], int *clone);
t_list	*ft_create_stack_b(void);
void	ft_replace_stack_b(t_list **stack_a, t_list **stack_b, struct s_data *b);
void	ft_replace_stack_a(t_list **stack_a, t_list **stack_b, struct s_data *b);
int		ft_count_digit(t_list *stack_a);
int		ft_clone_size(char *argv[]);
char	**ft_split(char *str, char c);
char	**ft_free(char **resdult, int i);
int		ft_atoi(char *str);
long	ft_atol(char *str);
int		ft_is_flag(char *argv);
int		ft_is_duplicate(char *argv[]);
int		*ft_create_clone(char *argv[]);
t_list	*ft_lstnew(int content);
void	ft_print_list(t_list *lst);
void	ft_lstclear(t_list **lst);
void	ft_del(int *content);
float	ft_find_disorder(t_list *lst);
t_list	*ft_adaptive(t_list **stack_a, t_list **stack_b, struct s_data *p);
int		ft_strncmp(const char *str1, const char *str2, size_t length);
void	pa(t_list **stack_a, t_list **stack_b, struct s_data *b);
void	pb(t_list **stack_a, t_list **stack_b, struct s_data *b);
t_list	*ft_lstlast(t_list *lst);
void	reverse(t_list **stack);
void	rra(t_list **stack_a, struct s_data *b);
void	rrb(t_list **stack_b, struct s_data *b);
void	rrr(t_list **stack_a, t_list **stack_b, struct s_data *b);
void	rotate(t_list **stack);
void	ra(t_list **stack_a, struct s_data *b);
void	rb(t_list **stack_b, struct s_data *b);
void	rr(t_list **stack_a, t_list **stack_b, struct s_data *b);
void	swap(t_list **stack);
void	sa(t_list **stack_a, struct s_data *b);
void	sb(t_list **stack_b, struct s_data *b);
void	ss(t_list **stack_a, t_list **stack_b, struct s_data *b);
int		ft_lstsize(t_list *lst);
int		find_min(t_list *a);
int		get_position(t_list *a);
void	move_to_top(t_list **a, struct s_data *p);
t_list	*simple(t_list **a, t_list **b, struct s_data *p);
int		ft_lstsize_stack(t_list *lst);
t_list	*ft_complex(t_list **stack_a, t_list **stack_b, struct s_data *b);
t_list	*ft_create_stack_temp(t_list *stack_b);
int		ft_strlen(char *argv);
int		ft_is_bench(char *argv);
void	ft_bench( struct s_data *p);
void	move_top(t_list **stack_b, struct s_data *b);
t_list	*find_max(t_list *b);
void	push_chunks(t_list **stack_a, t_list **stack_b, int nc, struct s_data *b);
int		count_chunk(t_list *a, int chunk, int nc, int size);
int		is_in_chunk(t_list *lst, int chunk, int nc, int size);
void	assign_index(t_list *lst);
t_list	*medium(t_list **stack_a, t_list **stack_b, struct s_data *b);

#endif
