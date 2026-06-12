/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 11:06:07 by emcerda           #+#    #+#             */
/*   Updated: 2026/06/01 11:40:15 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_lstsize_stack(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ft_check_int(int content, int *clone, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (content == clone[i])
			return (i);
		else
			i++;
	}
	return (0);
}

void    add_node(t_list **stack_a, t_list *baby_node, t_list **parent_node)
{
    if (*stack_a == NULL)
    {
        baby_node->prev = NULL;
        *stack_a = baby_node;
    }
    else
    {
        (*parent_node)->next = baby_node;
        baby_node->prev = *parent_node;
    }
    *parent_node = baby_node;
}

t_list    *ft_create_stack_a(char *argv[], int *clone)
{
    int        content;
    t_list    *stack_a;
    t_list    *baby_node;
    t_list    *parent_node;
    int        i;

    stack_a = NULL;
    i = 0;
    while (argv[i] != NULL)
    {
        content = ft_atoi(argv[i]);
        baby_node = ft_lstnew(content);
        baby_node->index = ft_check_int(content, clone, ft_clone_size(argv));
        if (baby_node == NULL)
        {
            ft_lstclear(&stack_a);
            ft_dprintf(2, "Error\n");
            exit(1);
        }
        add_node(&stack_a, baby_node, &parent_node);
		i++;
    }
    free(clone);
    return (stack_a);
}
// t_list	*ft_create_stack_a(char *argv[], int *clone)
// {
// 	int		content;
// 	t_list	*stack_a;
// 	t_list	*baby_node;
// 	t_list	*parent_node;
//
// 	int		(i) = 0;
// 	stack_a = NULL;
// 	while (argv[i] != NULL)
// 	{
// 		content = ft_atoi(argv[i]);
// 		baby_node = ft_lstnew(content);
// 		baby_node->index = ft_check_int(content, clone, ft_clone_size(argv));
// 		if (baby_node == NULL)
// 		{
// 			ft_lstclear(&stack_a);
// 			ft_error();
// 		}
// 		if (stack_a == NULL)
// 		{
// 			baby_node->prev = NULL;
// 			stack_a = baby_node;
// 		}
// 		else
// 		{
// 			parent_node->next = baby_node;
// 			baby_node->prev = parent_node;
// 		}
// 		parent_node = baby_node;
// 		i++;
// 	}
// 	free(clone);
// 	return (stack_a);
// }

t_list	*ft_create_stack_b(void)
{
	t_list	*stack_b;

	stack_b = NULL;
	return (stack_b);
}
