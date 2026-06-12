/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:17:32 by romapere          #+#    #+#             */
/*   Updated: 2026/05/30 11:53:35 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = lst;
	while (node->next)
	{
		node = node->next;
	}
	return (node);
}

void	rotate(t_list **stack)
{
	t_list	*node;
	t_list	*last;

	if (!*stack || !(*stack)->next)
		return ;
	node = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last = ft_lstlast(*stack);
	last->next = node;
	node->prev = last;
	node->next = NULL;
}

void	ra(t_list **stack_a, struct s_data *b)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
	b->count++;
	b->ra++;
}

void	rb(t_list **stack_b, struct s_data *b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
	b->count++;
	b->rb++;
}

void	rr(t_list **stack_a, t_list **stack_b, struct s_data *b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
	b->count++;
	b->rr++;
}

// big main
// t_list  *new_node(int value)
// {
//     t_list  *node;

//     node = malloc(sizeof(t_list));
//     if (!node)
//         return (NULL);
//     node->value = value;
//     node->index = 0;
//     node->next = NULL;
//     node->prev = NULL;
//     return (node);
// }

// void    print_stack(t_list *stack, char *name)
// {
//     write(1, name, 1);
//     write(1, ": ", 2);
//     while (stack)
//     {
//         printf("%d ", stack->value);
//         stack = stack->next;
//     }
//     write(1, "\n", 1);
// }

// int main(void)
// {
//     t_list *a;
//     t_list *b;

//     a = new_node(1);
//     a->next = new_node(2);
//     a->next->prev = a;
//     a->next->next = new_node(3);
//     a->next->next->prev = a->next;

//     rr(&a, &b);
//     print_stack(a, "A");

//     return (0);
// }
