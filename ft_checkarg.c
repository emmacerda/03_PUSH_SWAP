/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkarg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 08:50:36 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 09:32:29 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_push_swap.h"

int	ft_is_flag(char *argv)
{
	if (ft_strncmp("--simple", argv, 8) == 0)
		return (1);
	else if (ft_strncmp("--medium", argv, 8) == 0)
		return (1);
	else if (ft_strncmp("--complex", argv, 9) == 0)
		return (1);
	else if (ft_strncmp("--adaptive", argv, 10) == 0)
		return (1);
	return (0);
}

int	ft_is_bench(char *argv)
{
	if (ft_strncmp("--bench", argv, 7) == 0)
		return (1);
	return (0);
}

void	ft_error(void)
{
	ft_dprintf(2, "Error\n");
	exit(1);
}

t_list	*ft_checkarg(char *argv[])
{
	int	*clone;

	int (ii) = 0;
	int (i) = 1;
	int (flag) = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
		{
			if ((ft_is_flag(argv[i]) == 0) && ((ft_is_bench(argv[i]) == 0)
					&& (i == 1)))
				ft_error();
			flag++;
		}
		else if (ft_is_duplicate(argv + 1 + flag) == 1)
			ft_error();
		else if (ft_is_double_flag(argv) == 1)
			ft_error();
		else
			ft_is_number(argv, i, ii);
		is_valid_range(argv[i]);
		i++;
	}
	clone = ft_create_clone(argv + 1 + flag);
	return (ft_create_stack_a((argv + 1 + flag), clone));
}
