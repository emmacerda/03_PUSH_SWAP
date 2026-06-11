/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 14:02:01 by romapere          #+#    #+#             */
/*   Updated: 2026/05/20 14:03:13 by romapere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

void	ft_write_in_tab(char const *s, char **new_tab, char c, int count_words);
size_t	ft_count_words(char const *s, char c);
char	**ft_free(char **new_str, int i);
int	ft_count_letters(char const *s, char c, int j);
char	**ft_split(char const *s, char c);
char	**ft_checkarg(char *argv);
void	ft_print_tab(char **new_str);
void    pa(t_node **a, t_node **b);
void    pb(t_node **a, t_node **b);
t_node	*ft_lstlast(t_node *lst);
void    reverse(t_node **stack);
void    rra(t_node **a);
void    rrb(t_node **b);
void    rrr(t_node **a, t_node **b);
void    rotate(t_node **stack);
void    ra(t_node **a);
void    rb(t_node **b);
void    rr(t_node **a, t_node **b);
void    swap(t_node **stack);
void    sa(t_node **a);
void    sb(t_node **b);
void    ss(t_node **a, t_node **b);
int	ft_lstsize(t_node *lst);
int find_min(t_node *a);
int  get_position(t_node *a);
void     move_to_top(t_node **a);
void    simple(t_node **a, t_node **b);
void     move_top(t_node **b);
t_node  *find_max(t_node *b);
void    push_chunks(t_node **a, t_node **b, int nc);
int    count_chunk(t_node  *a, int chunk, int nc, int size);
int     is_in_chunk(t_node *lst, int chunk, int nc , int size);
void    assign_index(t_node *lst);
void    medium(t_node **a, t_node **b);
#endif