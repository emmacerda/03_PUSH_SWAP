/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:52:39 by emcerda           #+#    #+#             */
/*   Updated: 2026/05/22 10:56:46 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] != '\0') && ((str[i] == 32)
			|| (str[i] >= 9 && str[i] <= 13)))
		i++;
	if ((str[i] != '\0') && ((str[i] == '-') || (str[i] == '+')))
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

long	ft_atol(char *str)
{
	long	i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] != '\0') && ((str[i] == 32)
			|| (str[i] >= 9 && str[i] <= 13)))
		i++;
	if ((str[i] != '\0') && ((str[i] == '-') || (str[i] == '+')))
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}
