/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:32:09 by emcerda           #+#    #+#             */
/*   Updated: 2026/05/30 12:24:00 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_push_swap.h"

int	ft_check_flags(char *argv[], t_list *stack_a, t_list *stack_b,
		struct data *b)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (argv[i] != NULL)
	{
		while (argv[i][ii] != '\0')
		{
			if (argv[i][0] == '-' && argv[i][1] == '-')
			{
				if (ft_strncmp("--simple", argv[i], 8) == 0)
				{
					ft_print_list(simple(&stack_a, &stack_b, b));
					return (1);
				}
				else if (ft_strncmp("--medium", argv[i], 8) == 0)
				{
					ft_print_list(medium(&stack_a, &stack_b));
					return (2);
				}
				else if (ft_strncmp("--complex", argv[i], 9) == 0)
				{
					ft_print_list(ft_complex(stack_a, stack_b, b));
					return (3);
				}
				else if (ft_strncmp("--adaptive", argv[i], 10) == 0)
				{
					ft_print_list(ft_adaptive(stack_a, stack_b, b));
					return (4);
				}
			}
			ii++;
		}
		i++;
		ii = 0;
	}
	return (0);
}

struct data	ft_init_struct(struct data bench)
{
	bench.disorder = 0;
	bench.flag_bench = 0;
	bench.check_flag = 0;
	bench.count = 0;
	bench.sa = 0;
	bench.sb = 0;
	bench.ss = 0;
	bench.pa = 0;
	bench.pb = 0;
	bench.ra = 0;
	bench.rb = 0;
	bench.rr = 0;
	bench.rra = 0;
	bench.rrb = 0;
	bench.rrr = 0;
	return (bench);
}

int	main(int argc, char *argv[])
{
	t_list		*stack_a;
	t_list		*stack_b;
	struct data	bench;
	struct data	*b;

	b = &bench;
	bench = ft_init_struct(bench);
	b->flag_bench = ft_is_bench(argv[1]);
	if (argc == 0)
		exit(1);
	if (argc > 1)
	{
		stack_a = ft_checkarg(argv);   // CREATION STACK_A SI ARGS VALIDES
		stack_b = ft_create_stack_b(); // CREATION STACK_B SI STACK_A VALIDE
		if (stack_a == NULL)           // || (stack_b == NULL)) //ERROR
		{
			ft_dprintf(2, "Error\n");
			exit(1);
		}
		else
		{
			b->disorder = ft_find_disorder(stack_a);
			// CALCUL DISORDER STACK_A										//
			if (b->disorder == 0)
			{
				// ft_lstclear(&stack_a);
				// ft_lstclear(&stack_b);
				return (0);
			}
			b->check_flag = ft_check_flags(argv, stack_a, stack_b, b);
			if (b->check_flag == 0) // ON VERIFIE SI IL Y A DES FLAGS
			{
				printf("\n");
				stack_a = ((ft_adaptive(stack_a, stack_b, b))); // SI NON,
				ALGO ADAPTIF
			}
			if (ft_strncmp("--bench", argv[1], 7) == 0)
				ft_bench(b);
			printf("\n");
		}
		ft_print_list(stack_a);
		// ft_dprintf(1, "\n");
		// ft_print_list(stack_b);
		printf("\n");
		ft_lstclear(&stack_b);
		// ft_lstclear(&stack_a);
		// ft_free(argv, argc);
		// ft_lstclear(&stack_a);
	}
	return (0);
}
//
// int	main(int argc, char *argv[])
// {
// 	// t_list *stack_a;
//
// 	if (argc > 0)
// 	{
// 		ft_print_list(ft_checkarg(argv));
// 		// printf("%f", ft_disorder(ft_checkarg(argv)));
// 		// ft_checkarg(argv);
// 		// stack_a = ft_checkarg(argv);
// 		// ft_print_list(stack_a);
// 		// if (stack_a == NULL)
// 		// 	return (0);
// 		// else
// 		// 	printf("%f\n", ft_find_disorder(stack_a));
// 	}
// 	return (0);
// }
