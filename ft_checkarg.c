/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 08:50:36 by emcerda           #+#    #+#             */
/*   Updated: 2026/05/30 11:10:31 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_push_swap.h"
#include <limits.h>

// SI ARGV EST SOUS FORME ./a.out X X XX X
// t_list	*ft_checkargs(char *argv[])
// {
// 	int i;
// 	int ii;
//
// 	i = 1;
// 	ii = 0;
// 	while (argv[i] != NULL)
// 	{
// 		while (argv[i][ii] != '\0')
// 		{
// 			if (argv[i][ii] < '0' || argv[i][ii] > '9')
// 				return (NULL);
// 			ii++;
// 		}
// 		ii = 0;
// 		i++;
// 	}
// 	return (ft_create_stack(argv)); //DECALER LE POINTEUR DE 1
//
// }

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
	// i = 0;
	// printf("0000000000\n");
	// while(i < save_i)
	// {
	// 	printf("%d\n", clone[i]);
	// 	i++;
	// }
	// printf("0000000000\n");
	ft_sort_int_tab(clone, save_i);
	// i = 0;
	// printf("CLONE\n");
	// while(i < save_i)
	// {
	// 	printf("%d\n", clone[i]);
	// 	i++;
	// }
	// printf("CLoNE\n");
	return (clone);
}

t_list	*ft_checkarg(char *argv[])
{
	int	ii;
	int	i;
	int	flag;
	int	*clone;

	i = 1;
	ii = 0;
	flag = 0;
	// is_valid_range(argv[0]);
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if ((ft_is_flag(argv[i]) == 0) && ((ft_is_bench(argv[i]) == 0)
					&& (i == 1)))
			{
				ft_dprintf(2, "Error\n");
				exit(1);
			}
			flag++;
		}
		else if (ft_is_duplicate(argv, flag) == 1)
		{
			ft_dprintf(2, "Error\n");
			exit(1);
		}
		// else if (ft_is_double_flag(argv) == 1)
		// {
		// 	ft_dprintf(2, "Error");
		// 	return (NULL);
		// }
		else
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
		is_valid_range(argv[i]);
		ii = 0;
		i++;
		// save = argv[i];
	}
	// if (i == 2)//SI ARGV EST 1, SOUS FORME DE "XX X XX"
	// {
	// 	result = ft_split(argv[1], 32);
	// 	return (ft_create_stack_a(result));
	// }
	clone = ft_create_clone(argv + 1 + flag);
	return (ft_create_stack_a((argv + 1 + flag), clone)); //, clone));
	// result = ft_split(argv[1],32);
	// return (ft_create_stack(result));
}
