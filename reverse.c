/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 16:51:24 by romapere          #+#    #+#             */
/*   Updated: 2026/05/30 11:54:25 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	reverse(t_list **stack)
{
	t_list	*last;
	t_list	*before_last;
	t_list	*head;

	// t_list *save;
	if (!*stack || !(*stack)->next)
		return ;
	// (*stack)->prev = NULL;
	last = ft_lstlast(*stack);
	before_last = last->prev;
	// save = last;
	before_last->next = NULL;
	head = *stack;
	last->next = head;
	head->prev = last;
	*stack = last;
}

void	rra(t_list **stack_a, struct data *b)
{
	reverse(stack_a);
	write(1, "rra\n", 4);
	b->count++;
	b->rra++;
}

void	rrb(t_list **stack_b, struct data *b)
{
	reverse(stack_b);
	write(1, "rrb\n", 4);
	b->count++;
	b->rrb++;
}

void	rrr(t_list **stack_a, t_list **stack_b, struct data *b)
{
	reverse(stack_a);
	reverse(stack_b);
	write(1, "rrr\n", 4);
	b->count++;
	b->rrr++;
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

//     rrr(&a, &b);
//     print_stack(a, "A");

//     return (0);
// }
