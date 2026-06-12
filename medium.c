/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romapere <romapere@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:16:12 by romapere          #+#    #+#             */
/*   Updated: 2026/06/10 17:15:41 by romapere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// void	print_stack(t_list *stack, char *name)
// {
//     write(1, name, 1);
//     write(1, ": ", 2);
//     while (stack)
//     {
//         printf("%d ", stack->value);
//         stack = stack->next;
//     }
//     write(1, "\n", 1);
// }

t_list	*medium(t_list **stack_a, t_list **stack_b, struct data *b)
{
	int	nc;
	int	size;

	if (!*stack_a)
		return (NULL);
	assign_index(*stack_a);
	nc = 0;
	size = ft_lstsize(*stack_a);
	while (nc * nc < size)
	{
		nc++;
	}
	push_chunks(stack_a, stack_b, nc, b);
	while (*stack_b)
	{
		move_top(stack_b);
		pa(stack_a, stack_b, b);
	}
	return (*stack_a);
}

void	assign_index(t_list *lst)
{
	t_list	*node;
	t_list	*tmp;
	int		count;

	node = lst;
	while (node)
	{
		count = 0;
		tmp = lst;
		while (tmp)
		{
			if (tmp->content < node->content)
				count++;
			tmp = tmp->next;
		}
		node->index = count;
		node = node->next;
	}
}

int	is_in_chunk(t_list *lst, int chunk, int nc, int size)
{
	if (lst->index * nc / size == chunk)
		return (1);
	else
		return (0);
}

int	count_chunk(t_list *a, int chunk, int nc, int size)
{
	int	count;

	count = 0;
	while (a)
	{
		if (is_in_chunk(a, chunk, nc, size))
			count++;
		a = a->next;
	}
	return (count);
}

void	push_chunks(t_list **stack_a, t_list **stack_b, int nc, struct data *b)
{
	int	chunk;
	int	size;

	size = ft_lstsize(*stack_a);
	chunk = 0;
	while (chunk < nc)
	{
		while (*stack_a && count_chunk(*stack_a, chunk, nc, size) > 0)
		{
			if (is_in_chunk(*stack_a, chunk, nc, size))
			{
				pb(stack_a, stack_b, b);
			}
			else
			{
				ra(stack_a, b);
			}
		}
		chunk++;
	}
}

/*
t_list	*new_node(int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	push_back(t_list **head, int value)
{
	t_list	*node;
	t_list	*tmp;

	node = new_node(value);
	if (!*head) { *head = node; return ; }
	tmp = *head;
	while (tmp->next) tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
}

int	main(void)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	// stack A (10 valeurs)
	a = new_node(9);
	a->next = new_node(1);
	a->next->prev = a;
	a->next->next = new_node(8);
	a->next->next->prev = a->next;
	a->next->next->next = new_node(3);
	a->next->next->next->prev = a->next->next;
	a->next->next->next->next = new_node(7);
	a->next->next->next->next->prev = a->next->next->next;
	a->next->next->next->next->next = new_node(2);
	a->next->next->next->next->next->prev = a->next->next->next->next;
	a->next->next->next->next->next->next = new_node(6);
	a->next->next->next->next->next->next->prev =
	a->next->next->next->next->next;
	a->next->next->next->next->next->next->next = new_node(5);
	a->next->next->next->next->next->next->next->prev =
	a->next->next->next->next->next->next;
	a->next->next->next->next->next->next->next->next = new_node(4);
	a->next->next->next->next->next->next->next->next->prev =
	a->next->next->next->next->next->next->next;
	a->next->next->next->next->next->next->next->next->next = new_node(10);
	a->next->next->next->next->next->next->next->next->next->prev
	= a->next->next->next->next->next->next->next->next;
	printf("=== BEFORE ===\n");
	print_stack(a, "A");
	print_stack(b, "B");
	medium(&a, &b);
	printf("\n=== AFTER ===\n");
	print_stack(a, "A");
	print_stack(b, "B");
	return (0);
}
*/
