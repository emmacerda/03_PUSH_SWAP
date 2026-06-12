/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_complex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:45:22 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 10:11:34 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_count_digit(t_list *stack_a)
{
	int	counter;
	int	prev_counter;
	int	save;
	int	content;

	counter = 0;
	prev_counter = 0;
	save = 0;
	while (stack_a != NULL)
	{
		prev_counter = counter;
		counter = 0;
		content = stack_a->index;
		while (content > 0)
		{
			content = content / 10;
			counter++;
		}
		if (counter > prev_counter)
			save = counter;
		stack_a = stack_a->next;
	}
	return (save);
}

void	ft_replace_stack_a(t_list **stack_a, t_list **stack_b, struct data *b)
{
	int	digit_parcourus;
	int	size;

	digit_parcourus = 0;
	size = ft_lstsize_stack(*stack_b);
	while (digit_parcourus < size)
	{
		pa(stack_a, stack_b, b);
		digit_parcourus++;
	}
}

void	ft_replace_stack_b(t_list **stack_a, t_list **stack_b, struct data *b)
{
	int	digit_parcourus;
	int	size;

	digit_parcourus = 0;
	size = ft_lstsize_stack(*stack_a);
	while (digit_parcourus < size)
	{
		pb(stack_a, stack_b, b);
		digit_parcourus++;
	}
}
