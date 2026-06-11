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

int find_min(t_list *a)
{
    int min;
    t_list *tmp;
    
    tmp = a;
    min = tmp->content;
    while(tmp)
    {
        if (tmp->content < min)
            min = tmp->content;
        tmp = tmp->next;
    }
    return (min);
}

int  get_position(t_list *a)
{
    int i;
    int min;

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

void     move_to_top(t_list **a, struct data *b)
{
    int size;
    int pos;

    pos = get_position(*a);
    size = ft_lstsize(*a);
    while(pos > 0)
    {
        if (pos <= size / 2)
		{
            ra(a);
			b->count++;
			b->ra++;
		}
        else
		{
            rra(a);
			b->count++;
			b->rra++;
		}
        pos = get_position(*a);
        size = ft_lstsize(*a);
    }
}

t_list    *simple(t_list **a, t_list **b, struct data *p)
{
    int size_a;

    size_a = ft_lstsize(*a);
    if (!*a)
        return (0);  //ERROR ?
    while (size_a > 1)
    {
        move_to_top(a, p);
        pb(a, b);
		p->count++;
		p->pb++;
        size_a = ft_lstsize(*a);
    }
    while (*b)
    {
        pa(a, b);
		p->count++;
		p->pa++;
    }
	return (*a);
}

//big main
// t_list  *new_node(int content)
// {
//     t_list  *node;

//     node = malloc(sizeof(t_list));
//     if (!node)
//         return (NULL);
//     node->content = content;
//     node->index = 0;
//     node->next = NULL;
//     node->prev = NULL;
//     return (node);
// }

// void    print_stack(t_list *stack, char *name)
// {
//     write(1, name, 1);
//     write(1, ": ", 2);
//     while (stack)
//     {
//         printf("%d ", stack->content);
//         stack = stack->next;
//     }
//     write(1, "\n", 1);
// }

// int main(void)                                           //MMDRRR J ADORE LE MAIN
// {
//     t_list *a = NULL;
//     t_list *b = NULL;

//     // stack A (10 valeurs)
//     a = new_node(9);
//     a->next = new_node(1);
//     a->next->prev = a;

//     a->next->next = new_node(8);
//     a->next->next->prev = a->next;

//     a->next->next->next = new_node(3);
//     a->next->next->next->prev = a->next->next;

//     a->next->next->next->next = new_node(7);
//     a->next->next->next->next->prev = a->next->next->next;

//     a->next->next->next->next->next = new_node(2);
//     a->next->next->next->next->next->prev = a->next->next->next->next;

//     a->next->next->next->next->next->next = new_node(6);
//     a->next->next->next->next->next->next->prev = a->next->next->next->next->next;

//     a->next->next->next->next->next->next->next = new_node(5);
//     a->next->next->next->next->next->next->next->prev = a->next->next->next->next->next->next;

//     a->next->next->next->next->next->next->next->next = new_node(4);
//     a->next->next->next->next->next->next->next->next->prev = a->next->next->next->next->next->next->next;

//     a->next->next->next->next->next->next->next->next->next = new_node(0);
//     a->next->next->next->next->next->next->next->next->next->prev = a->next->next->next->next->next->next->next->next;

//     printf("=== BEFORE ===\n");
//     print_stack(a, "A");
//     print_stack(b, "B");

//     simple(&a, &b);

//     printf("\n=== AFTER ===\n");
//     print_stack(a, "A");
//     print_stack(b, "B");

//     return 0;
// }
