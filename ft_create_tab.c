/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 09:31:50 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 10:08:47 by emcerda          ###   ########.fr       */
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

int	*ft_create_clone(char *argv[])
{
	int	*clone;
	int	i;
	int	j;
	int	save_i;

	i = 0;
	j = 0;
	save_i = ft_clone_size(argv);
	clone = malloc(sizeof(int) * save_i);
	if (clone == NULL)
		return (NULL);
	while (argv[i] != NULL)
	{
		clone[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	ft_sort_int_tab(clone, save_i);
	return (clone);
}
