/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:30:32 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 09:33:55 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_is_duplicate(char *argv[], int flag)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	if (flag == 1) // OU 2 POUR BENCH
	{
		i = 2;
		j = 3;
	}
	while (argv[i] != NULL)
	{
		while (argv[j] != NULL)
		{
			if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	is_valid_range(char *str)
{
	long	i;

	i = ft_atol(str);
	if (i > INT_MAX || i < INT_MIN)
	{
		ft_dprintf(2, "Error\n");
		exit(1);
	}
}

int	ft_is_double_flag(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	while (argv[i] != NULL)
	{
		if (ft_is_flag(argv[i]))
		{
			while (argv[j] != NULL)
			{
				if (ft_is_flag(argv[j]) == 1)
					return (1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

void	ft_is_number(char *argv[], int i, int ii)
{
	while (argv[i][ii] != '\0')
	{
		if ((argv[i][ii] < '0' || argv[i][ii] > '9')
				&& (argv[i][ii] != 32) && (argv[i][0] != '-'))
		{
			ft_dprintf(2, "Error\n");
			exit(1);
		}
		ii++;
	}
}
