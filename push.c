/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:56:05 by romapere          #+#    #+#             */
/*   Updated: 2026/05/30 11:54:58 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, struct s_data *b)
{
	t_list	*node;
	t_list	*node2;

	if (!*stack_b)
		return ;
	node = *stack_b;
	node2 = *stack_a;
	*stack_b = (*stack_b)->next;
	node->next = node2;
	node->prev = NULL;
	if (node2)
		node2->prev = node;
	*stack_a = node;
	write(1, "pa\n", 3);
	b->count++;
	b->pa++;
}

void	pb(t_list **stack_a, t_list **stack_b, struct s_data *b)
{
	t_list	*node;
	t_list	*node2;

	if (!*stack_a)
		return ;
	node = *stack_a;
	node2 = *stack_b;
	*stack_a = (*stack_a)->next;
	node->next = node2;
	node->prev = NULL;
	if (node2)
		node2->prev = node;
	*stack_b = node;
	write(1, "pb\n", 3);
	b->count++;
	b->pb++;
}
