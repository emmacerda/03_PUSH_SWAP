/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 17:32:09 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 10:11:05 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_push_swap.h"

int	ft_check_flags_bis(char *argv, t_list **stack_a, t_list **stack_b,
		struct s_data *b)
{
	if (argv[0] == '-' && argv[1] == '-')
	{
		if (ft_strncmp("--simple", argv, 8) == 0)
		{
			simple(stack_a, stack_b, b);
			return (1);
		}
		else if (ft_strncmp ("--medium", argv, 8) == 0)
		{
			medium(stack_a, stack_b, b);
			return (2);
		}
		else if (ft_strncmp("--complex", argv, 9) == 0)
		{
			ft_complex(stack_a, stack_b, b);
			return (3);
		}
		else if (ft_strncmp("--adaptive", argv, 10) == 0)
		{
			ft_adaptive(stack_a, stack_b, b);
			return (4);
		}
	}
	return (0);
}

int	ft_check_flags(char *argv[], t_list **stack_a, t_list **stack_b,
		struct s_data *b)
{
	int	(i) = 0;
	int	(ii) = 0;
	int (res) = 0;

	while (argv[i] != NULL)
	{
		while (argv[i][ii] != '\0')
		{
			res = ft_check_flags_bis(argv[i], stack_a, stack_b, b);
			ii++;
		}
		i++;
		ii = 0;
	}
	return (res);
}

struct s_data	ft_init_struct(struct s_data bench)
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
	bench.base = 1;
	bench.digit_parcourus = 0;
	return (bench);
}

static void    run_sort(t_list **stack_a, t_list **stack_b, struct s_data *b,
		char *argv[])
{
	b->disorder = ft_find_disorder(*stack_a);
	if (b->disorder == 0)
		return ;
	b->check_flag = ft_check_flags(argv, stack_a, stack_b, b);
	if (b->check_flag == 0)
		*stack_a = ft_adaptive(stack_a, stack_b, b);
	if (ft_strncmp("--bench", argv[1], 7) == 0)
		ft_bench(b);
	ft_print_list(*stack_a);
	ft_lstclear(stack_b);
}

int    main(int argc, char *argv[])
{
	t_list            *stack_a;
	t_list            *stack_b;
	struct s_data    bench;
	struct s_data    *b;

	if (argc == 1)
		return (0);
	b = &bench;
	bench = ft_init_struct(bench);
	b->flag_bench = ft_is_bench(argv[1]);
	stack_a = ft_checkarg(argv);
	stack_b = ft_create_stack_b();
	if (!stack_a)
	{
		ft_dprintf(2, "Error\n");
		exit(1);
	}
	run_sort(&stack_a, &stack_b, b, argv);
	// ft_lstclear(&stack_a);
	stack_a = NULL;
	return (0);
}

// int	main(int argc, char *argv[])
// {
// 	t_list		*stack_a;
// 	t_list		*stack_b;
// 	struct data	bench;
// 	struct data	*b;
//
// 	b = &bench;
// 	bench = ft_init_struct(bench);
// 	b->flag_bench = ft_is_bench(argv[1]);
// 	if (argc == 1)
// 		exit(1);
// 	if (argc > 1)
// 	{
// 		stack_a = ft_checkarg(argv);
// 		stack_b = ft_create_stack_b();
// 		if (stack_a == NULL)
// 			ft_error();
// 		else
// 		{
// 			b->disorder = ft_find_disorder(stack_a);
// 			if (b->disorder == 0)
// 			{
// 				// ft_lstclear(&stack_a);
// 				// ft_lstclear(&stack_b);
// 				return (0);
// 			}
// 			b->check_flag = ft_check_flags(argv, &stack_a, &stack_b, b);
// 			if (b->check_flag == 0)
// 			{
// 				printf("\n");
// 				stack_a = ((ft_adaptive(&stack_a, &stack_b, b)));
// 			}
// 			if (ft_strncmp("--bench", argv[1], 7) == 0)
// 				ft_bench(b);
// 			printf("\n");
// 		}
// 		ft_print_list(stack_a);
// 		ft_lstclear(&stack_b);
// 		ft_lstclear(&stack_a);
// 	}
// 	return (0);
// }
