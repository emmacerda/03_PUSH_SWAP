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

//SI ARGV EST SOUS FORME ./a.out X X XX X
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
int	ft_is_flag(char *argv)
{
	if (ft_strncmp ("--simple", argv, 8) == 0)
		//APPEL ALGO SIMPLE
		return 1;
	else if (ft_strncmp ("--medium", argv, 8) == 0)
		//APPEL ALGO MEDIUM
		return 1;
	else if (ft_strncmp ("--complex", argv, 9) == 0)
		//APPEL ALGO COMPLEX
		return 1;
	else if (ft_strncmp ("--adaptive", argv, 10) == 0)
		//APPEL ALGO ADAPTIVE
		return 1;
	return (0);
}

int	ft_is_duplicate(char *argv[], int flag)
{
	int i;
	int j;

	i = 1;
	j = 2;
	if (flag == 1) //OU 2 POUR BENCH
	{
		i = 2;
		j = 3;
	}
	while (argv[i] != NULL)
	{
		while(argv[j] != NULL)
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
	if (ft_strncmp ("--bench", argv, 7) == 0)
		return (1);
	return (0);
}

int	ft_is_double_flag(char *argv[])
{
		int i;
	int j;

	i = 1;
	j = 2;
	while (argv[i] != NULL)
	{
		if (ft_is_flag(argv[i]))
		{
			while(argv[j] != NULL)
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



void    ft_swap(int *tab, int i)
{
    int    swap;

    swap = tab[i];
    tab[i] = tab[i - 1];
    tab [i - 1] = swap;
}

void    ft_sort_int_tab(int *tab, int size)
{
    int    i;
    int    j;
    int    tour_de_tab;

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

int ft_clone_size(char *argv[])
{
	int i = 0;

	while (argv[i] != NULL)
	{
		i++;
	}
	return (i);
}

int *ft_create_clone(char *argv[])
{
	int *clone;
	int i = 0;
	int j = 0;
	int save_i;
	
	save_i = ft_clone_size(argv);
	clone = malloc(sizeof(int) * save_i);
	if (clone == NULL)
		return (NULL);
	while(argv[i] != NULL)
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
	int ii;
	int i = 1;
	ii = 0;
	int flag = 0;
	int *clone;

	while  (argv[i] != NULL)
	{	
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if ((ft_is_flag(argv[i]) == 0) && ((ft_is_bench(argv[i]) == 0) && (i == 1)))
			{
				ft_dprintf(2, "Error\n");
				exit (1);
			}
			flag++;;
		}
		else if (ft_is_duplicate(argv, flag) == 1)
		{	
			ft_dprintf(2, "Error\n");
			exit (1);
		}
		// else if (ft_is_double_flag(argv) == 1)
		// {
		// 	ft_dprintf(2, "Error");
		// 	return (NULL);
		// }
		else
		{
			while(argv[i][ii] != '\0')
			{
				if((argv[i][ii] < '0' || argv[i][ii] > '9') && (argv[i][ii] != 32) && (argv[i][0] != '-'))
				{
					ft_dprintf(2, "Error\n");
					exit (1);
				}
				ii++;
			}
		}
		
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
	return (ft_create_stack_a((argv + 1 + flag), clone));//, clone));
	// result = ft_split(argv[1], 32);
	// return (ft_create_stack(result));
}
