/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:40:02 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/12 10:43:06 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_push_swap.h"

void	ft_putfloat(int nb)
{
	char	c;

	if (nb > 9)
		ft_putfloat(nb / 10);
	c = (nb % 10) + 48;
	write(2, &c, 1);
}

void	ft_float(float b)
{
	int	nb;

	nb = (b * 10000);
	write(2, "disorder: ", 10);
	ft_putfloat(nb / 100);
	write(2, ".", 1);
	ft_putfloat(nb % 100);
	write(2, "\n", 1);
}

void	ft_printf_adaptive_strat(struct s_data *b)
{
	if (b->disorder >= 0 && b->disorder < 0.2)
		ft_dprintf(2, "Strategy: Adaptive / O(n2)\n");
	else if (b->disorder >= 0.2 && b->disorder < 0.5)
		ft_dprintf(2, "Strategy: Adaptive / O(n√n)\n");
	else if (b->disorder >= 0.5 && b->disorder <= 1)
		ft_dprintf(2, "Strategy: Adaptive / O(n log n)\n");
}

void	ft_bench(struct s_data *b)
{
	ft_float(b->disorder);
	if (b->check_flag == 0)
		ft_printf_adaptive_strat(b);
	else
	{
		if (b->check_flag == 1)
			ft_dprintf(2, "Strategy: Simple / O(n2)\n");
		else if (b->check_flag == 2)
			ft_dprintf(2, "Strategy: Medium / O(n√n)\n");
		else if (b->check_flag == 3)
			ft_dprintf(2, "Strategy: Complex / O(n log n)\n");
		else if (b->check_flag == 4)
			ft_printf_adaptive_strat(b);
	}
	ft_dprintf(2, "Total_ops: %d\n", b->count);
	ft_dprintf(2, "sa: %d, sb: %d, ss: %d, pa: %d, pb: %d\n", b->sa, b->sb,
		b->ss, b->pa, b->pb);
	ft_dprintf(2, "ra: %d, rb: %d, rr: %d, rra: %d, rrb: %d, rrr: %d\n", b->ra,
		b->rb, b->rr, b->rra, b->rrb, b->rrr);
}
