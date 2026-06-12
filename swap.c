/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:56:10 by romapere          #+#    #+#             */
/*   Updated: 2026/05/30 11:52:43 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
}

void	sa(t_list **stack_a, struct s_data *b)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	b->count++;
	b->sa++;
}

void	sb(t_list **stack_b, struct s_data *b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
	b->count++;
	b->sb++;
}

void	ss(t_list **stack_a, t_list **stack_b, struct s_data *b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	b->count++;
	b->ss++;
}
