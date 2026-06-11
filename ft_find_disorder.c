/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:32:25 by emcerda           #+#    #+#             */
/*   Updated: 2026/05/29 10:04:13 by emcerda          ###   ########.fr       */
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
	// if (total_pairs / 2 <= mistakes)
	// {
	// 		printf("High disorder\n");
	// 		return (mistakes / total_pairs); // (1)
	// }
	// else if (total_pairs / 2 > mistakes)
	// {
	// 	if (mistakes < (total_pairs / 2) / 2)
	// 	{
	// 		printf ("Low disorder\n");
	// 		return (mistakes / total_pairs); // (0)
	// 	}
	// 	else if (mistakes >= (total_pairs / 2) / 2)
	// 	{
	// 		printf("Medium disorder\n");
	// 		return (mistakes / total_pairs); //(0.5)
	// 	}
	// }
	// return (- 1);
	return (mistakes / total_pairs);
}
//
// OU
//
// int	ft_find_dis(t_list *lst)
// {
// 	float total_pairs;
// 	float mistakes;
//
// 	total_pairs = 0;
// 	mistakes = 0;
// 	while (lst->next != NULL)
// 	{
// 		if (lst->next->content < lst->content)
// 			mistakes++;
// 		total_pairs++;
// 		lst = lst->next;
// 	}
// 	return (mistakes / total_pairs);
// }
