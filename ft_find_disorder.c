/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:32:25 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 10:14:04 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

float	ft_find_disorder(t_list *lst)
{
	float	valid_pairs;
	float	mistakes;
	float	total_pairs;

	valid_pairs = 0;
	total_pairs = 0;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		if (lst->next->content > lst->content)
			valid_pairs++;
		total_pairs++;
		lst = lst->next;
	}
	mistakes = total_pairs - valid_pairs;
	return (mistakes / total_pairs);
}
