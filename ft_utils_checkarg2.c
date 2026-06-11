/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_checkarg2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 16:46:40 by romapere          #+#    #+#             */
/*   Updated: 2026/06/11 16:47:11 by romapere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

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

int	ft_is_flag(char *argv)
{
	if (ft_strncmp("--simple", argv, 8) == 0)
		// APPEL ALGO SIMPLE
		return (1);
	else if (ft_strncmp("--medium", argv, 8) == 0)
		// APPEL ALGO MEDIUM
		return (1);
	else if (ft_strncmp("--complex", argv, 9) == 0)
		// APPEL ALGO COMPLEX
		return (1);
	else if (ft_strncmp("--adaptive", argv, 10) == 0)
		// APPEL ALGO ADAPTIVE
		return (1);
	return (0);
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

int	ft_clone_size(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		i++;
	}
	return (i);
}
