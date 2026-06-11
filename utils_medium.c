/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:12:26 by romapere          #+#    #+#             */
/*   Updated: 2026/06/10 17:13:35 by romapere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*find_max(t_list *b)
{
	t_list	*max;
	t_list	*tmp;

	tmp = b;
	max = tmp;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

int	get_pos(t_list *stack, t_list *target)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == target)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

void	move_top(t_list **b)
{
	t_list	*max;
	int		size;

	max = find_max(*b);
	size = ft_lstsize(*b);
	while (*b && (*b) != max)
	{
		if (get_pos(*b, max) <= size / 2)
			rb(b);
		else
			rrb(b);
	}
}
