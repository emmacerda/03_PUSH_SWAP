/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:35:33 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 09:59:01 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_mouvement(t_list **stack_a, t_list **stack_b, int digit, struct s_data *b)
{
	int	save_size;

	save_size = ft_lstsize_stack(*stack_a);
	if ((((*stack_a)->index) % 10) == digit)
	{
		pb(stack_a, stack_b, b);
		rb(stack_b, b);
		save_size--;
	}
	else
		ra(stack_a, b);
	return (save_size);
}

int	ft_mouvement_bis(t_list **stack_a, t_list **stack_b, int digit,
		struct s_data *b)
{
	int	save_size;

	save_size = ft_lstsize_stack(*stack_b);
	if (((*stack_b)->index / b->base) % 10 == digit)
	{
		pa(stack_a, stack_b, b);
		// ra(&stack_a, b);
		save_size--;
	}
	else
		rb(stack_b, b);
	b->digit_parcourus++;
	return (save_size);
}

t_list	*ft_complex_bis(t_list **stack_a, t_list **stack_b, int max_digit,
		struct s_data *b)
{
	int	size;
	int	save_size;
	int	digit;

	b->digit_parcourus = 0;
	while (max_digit - 1 >= 0)
	{
		digit = 9;
		size = ft_lstsize(*stack_b);
		save_size = size;
		while ((digit >= 0) && (stack_b != NULL))
		{
			while ((b->digit_parcourus < size) && (stack_b != NULL))
				save_size = ft_mouvement_bis(stack_a, stack_b, digit, b);
			size = save_size;
			b->digit_parcourus = 0;
			digit--;
		}
		max_digit--;
		b->base = b->base * 10;
		ft_replace_stack_b(stack_a, stack_b, b);
	}
	ft_replace_stack_a(stack_a, stack_b, b);
	return (*stack_a);
}

t_list	*ft_complex(t_list **stack_a, t_list **stack_b, struct s_data *b)
{
	int (digit) = 9;
	int (digit_parcourus) = 0;
	int (size) = ft_lstsize_stack(*stack_a);
	int (save_size) = size;
	int (max_digit) = ft_count_digit(*stack_a);
	while (digit >= 0)
	{
		while (digit_parcourus < size)
		{
			save_size = ft_mouvement(stack_a, stack_b, digit, b);
			digit_parcourus++;
		}
		size = save_size;
		digit_parcourus = 0;
		digit--;
	}
	if (max_digit == 1)
	{
		ft_replace_stack_a(stack_a, stack_b, b);
		return (*stack_a);
	}
	return (ft_complex_bis(stack_a, stack_b, max_digit, b));
}
