/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:16:12 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 09:37:31 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_list	*ft_adaptive(t_list **stack_a, t_list **stack_b, struct s_data *b)
{
	if (b->disorder >= 0 && b->disorder < 0.2)
	{
		if (b->disorder == 0)
			return (*stack_a);
		return (simple(stack_a, stack_b, b));
	}
	else if (b->disorder >= 0.2 && b->disorder < 0.5)
		return (medium(stack_a, stack_b, b));
	if (b->disorder >= 0.5 && b->disorder <= 1)
		return (ft_complex(stack_a, stack_b, b));
	return (NULL);
}
