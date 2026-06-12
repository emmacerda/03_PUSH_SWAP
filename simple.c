/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 17:25:09 by romapere          #+#    #+#             */
/*   Updated: 2026/05/30 11:50:55 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include "ft_push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		count;

	count = 0;
	node = lst;
	while (node)
	{
		node = node->next;
		count++;
	}
	return (count);
}

int	find_min(t_list *a)
{
	int		min;
	t_list	*tmp;

	tmp = a;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	get_position(t_list *a)
{
	int	i;
	int	min;

	i = 0;
	min = find_min(a);
	while (a)
	{
		if (a->content == min)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	move_to_top(t_list **a, struct s_data *b)
{
	int	size;
	int	pos;

	pos = get_position(*a);
	size = ft_lstsize(*a);
	while (pos > 0)
	{
		if (pos <= size / 2)
			ra(a, b);
		else
			rra(a, b);
		pos = get_position(*a);
		size = ft_lstsize(*a);
	}
}

t_list	*simple(t_list **a, t_list **b, struct s_data *p)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (!*a)
	{
		ft_dprintf(2, "Error");
		exit (1);
	}
	while (size_a > 1)
	{
		move_to_top(a, p);
		pb(a, b, p);
		size_a = ft_lstsize(*a);
	}
	while (*b)
	{
		pa(a, b, p);
	}
	return (*a);
}
