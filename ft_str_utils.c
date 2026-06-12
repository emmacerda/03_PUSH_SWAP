/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 12:55:09 by emcerda           #+#    #+#             */
/*   Updated: 2026/05/29 12:56:13 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_strncmp(const char *str1, const char *str2, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (((str1[i] != '\0' && str2[i] != '\0') && (str1[i] == str2[i]))
		&& (i < length - 1))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	ft_strlen(char *str1, char *str2)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str1[i] != '\0')
		i++;
	while (str2[j] != '\0')
		j++;
	if (i < j)
		return (j);
	else if (j < i)
		return (i);
	return (i);
}
