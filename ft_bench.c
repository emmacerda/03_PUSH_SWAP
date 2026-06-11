/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:40:02 by emcerda           #+#    #+#             */
/*   Updated: 2026/05/29 09:52:16 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_push_swap.h"

// #include "ft_dprintf.h"
// #include <unistd.h>
// #include <stdio.h>
//
void	ft_putfloat(int nb)
{
	char c;

	if (nb > 9)
		ft_putfloat(nb / 10);
	c = (nb % 10) + 48;
	write(2, &c, 1);
}

void ft_float(float b)
{
	int nb;

	nb = (b * 10000);
	write(2, "disorder: ", 10);
	ft_putfloat(nb / 100);
	write(2, ".", 1);
	ft_putfloat(nb % 100);
}
//
// int	main(void)
// {
// 	ft_float(0.2);
// 	return (0);
// }

void	ft_bench(struct data *b)
{
	ft_float(b->disorder);
	if (b->check_flag == 0)
	{
		if (b->disorder >= 0 && b->disorder < 0.2)
			ft_dprintf(2, "Strategy: Adaptive / O(n2)\n");
		else if (b->disorder >= 0.2 && b->disorder < 0.5)
			ft_dprintf(2, "Strategy: Adaptive / O(n√n)\n");
		else if (b->disorder >= 0.5 && b->disorder <= 1)
			ft_dprintf(2, "Strategy: Adaptive / O(n log n)\n");
	}
	else
	{
		if(b->check_flag == 1)	
			ft_dprintf(2, "Strategy: Simple / O(n2)\n");
		else if (b->check_flag == 2)
			ft_dprintf(2, "Strategy: Medium / O(n√n)\n");
		else if (b->check_flag == 3)
			ft_dprintf(2, "Strategy: Complex / O(n log n)\n");
		else if (b->check_flag == 4)
		{
			if (b->disorder >= 0 && b->disorder < 0.2)
				ft_dprintf(2, "Strategy: Adaptive / O(n2)\n");
			else if (b->disorder >= 0.2 && b->disorder < 0.5)
				ft_dprintf(2, "Strategy: Adaptive / O(n√n)\n");
			else if (b->disorder >= 0.5 && b->disorder <= 1)
				ft_dprintf(2, "Strategy: Adaptive / O(n log n)\n");
		}
	}
	ft_dprintf(2, "Total_ops: %d\n", b->count);
	ft_dprintf(2, "sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", b->sa, b->sb, 
			b->ss, b->pa, b->pb);
	ft_dprintf(2, "ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", b->ra,
			b->rb, b->rr, b->rra, b->rrb, b->rrr);

}

// After sorting :
// The computed bench.disorder (% with two decimals).
// ◦ The name of the strategy used and its theoretical complexity class.
// ◦ The total number of operations.
// ◦ The count of each operation type (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr).
// The benchmark output must be sent to stderr and only appear when the flag is present.
