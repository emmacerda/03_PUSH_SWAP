/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:56:05 by romapere          #+#    #+#             */
/*   Updated: 2026/05/30 11:54:58 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void    pa(t_list **a, t_list **b)
{
    t_list  *node;
    t_list  *node2;

    if (!*b)
        return ;
    node = *b;
    node2 = *a;
    *b = (*b)->next;
    node->next = node2;
    node->prev = NULL;
    if (node2)
        node2->prev = node;
    *a = node;
   	write (1, "pa\n", 3);
}

void    pb(t_list **a, t_list **b)
{
    t_list  *node;
    t_list  *node2;

    if (!*a)
        return ;
    node = *a;
    node2 = *b;
    *a = (*a)->next;
    node->next = node2;
    node->prev = NULL;
    if (node2)
        node2->prev = node;
    *b = node;
	write (1, "pb\n", 3);
}
