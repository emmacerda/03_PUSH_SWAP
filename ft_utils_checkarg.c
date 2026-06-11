/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_checkarg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:19:28 by romapere          #+#    #+#             */
/*   Updated: 2026/06/11 16:19:32 by romapere         ###   ########.fr       */
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

int	ft_is_bench(char *argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;
	{
		if (ft_strncmp("--bench", argv, 7) == 0)
			return (1);
		return (0);
	}
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

void	ft_swap(int *tab, int i)
{
	int	swap;

	swap = tab[i];
	tab[i] = tab[i - 1];
	tab[i - 1] = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tour_de_tab;

	i = 1;
	j = 0;
	tour_de_tab = size;
	while (j < tour_de_tab)
	{
		while (i < size)
		{
			if (tab[i] < tab[i - 1])
			{
				ft_swap(tab, i);
				i++;
			}
			else
				i++;
		}
		i = 1;
		j++;
	}
}
