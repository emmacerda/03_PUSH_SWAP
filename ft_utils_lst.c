/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 11:05:03 by emcerda           #+#    #+#             */
/*   Updated: 2026/05/22 11:59:45 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_del(int *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*save;
	void	(*f)(int *);

	f = &ft_del;
	while (*lst != NULL)
	{
		save = (*lst)->next;
		(*f)(&((*lst)->content));
		free(*lst);
		*lst = save;
	}
}

t_list	*ft_lstnew(int content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		free(node);
		return (NULL);
	}
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_print_list(t_list *lst)
{
	while (lst != NULL)	
	{
		printf("%d", lst->content);
		// if (lst->next != NULL)
		// 	printf("\n");
		printf("\n");
		lst = lst->next;
	}
}
