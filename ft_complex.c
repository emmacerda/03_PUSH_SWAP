/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:35:33 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/01 11:10:09 by emcerda          ###   ########.fr       */
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
		// printf("prev = %d", prev_b->counter);
		while (content > 0)
		{
			content = content / 10;
			counter++;
			// printf("content = %d", stack_a->content);
		}
		if (counter > prev_counter)
			save = counter;
		stack_a = stack_a->next;
	}
	return (save);
}

t_list	*ft_complex(t_list *stack_a, t_list *stack_b, struct data *b)
{
	int	digit;
	int	digit_parcourus;
	int	size;
	int	save_size;
	int	max_digit;
	int	base;
	int	i;

	digit = 9;
	digit_parcourus = 0;
	size = ft_lstsize_stack(stack_a);
	save_size = size;
	max_digit = ft_count_digit(stack_a);
	while (stack_a != NULL)
	{
		while (digit >= 0)
		{
			while (digit_parcourus < size)
			{
				if (((stack_a->index) % 10) == digit)
				{
					pb(&stack_a, &stack_b);
					b->count++;
					b->pb++;
					rb(&stack_b);
					b->count++;
					b->rb++;
					save_size--;
				}
				else
				{
					ra(&stack_a);
					b->count++;
					b->ra++;
				}
				digit_parcourus++;
			}
			size = save_size;
			digit_parcourus = 0;
			digit--;
		}
	}
	digit = 9;
	base = 10;
	i = 0;
	if (max_digit == 1)
	{
		size = ft_lstsize_stack(stack_b);
		while (digit_parcourus < size)
		{
			pa(&stack_a, &stack_b);
			b->pa++;
			digit_parcourus++;
		}
		printf("A\n");
		ft_print_list(stack_a);
		return (stack_a);
	}
	digit_parcourus = 0;
	while (i < max_digit - 1)
	{
		size = ft_lstsize_stack(stack_b);
		save_size = size;
		while ((digit >= 0) && (stack_b != NULL))
		{
			while ((digit_parcourus < size) && (stack_b != NULL))
			{
				if ((stack_b->index / base) % 10 == digit)
				{
					pa(&stack_a, &stack_b);
					b->count++;
					b->pa++;
					// ra(&stack_a, b);
					// b->count++;
					// b->rb++;v
					save_size--;
				}
				else
				{
					rb(&stack_b);
					b->count++;
					b->rb++;
				}
				digit_parcourus++;
			}
			size = save_size;
			digit_parcourus = 0;
			digit--;
		}
		i++;
		digit = 9;
		base = base * 10;
		size = ft_lstsize_stack(stack_a);
		while (digit_parcourus < size)
		{
			pb(&stack_a, &stack_b);
			b->pb++;
			digit_parcourus++;
		}
	}
	digit_parcourus = 0;
	size = ft_lstsize_stack(stack_b);
	while (digit_parcourus < size)
	{
		pa(&stack_a, &stack_b);
		b->pa++;
		digit_parcourus++;
	}
	printf("AFTER");
	printf("STACK_A :\n");
	ft_print_list(stack_a);
	// ft_lstclear(&stack_a);
	return (stack_a);
}
