/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcerda <emcerda@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 10:35:46 by emcerda           #+#    #+#             */
/*   Updated: 2026/05/22 11:48:22 by emcerda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_push_swap.h"

void	ft_write_in_tab(char const *s, char **new_tab, char c, int count_words)
{
	int	i;
	int	ii;
	int	j;

	i = 0;
	j = 0;
	// printf("1");
	while (i < count_words)
	{
		ii = 0;
		if (s[j] == c)
		{
			while ((s[j] == c) && (s[j] != '\0'))
				j++;
		}
		while ((s[j] != c) && (s[j] != '\0'))
		{
			new_tab[i][ii] = s[j];
			j++;
			ii++;
		}
		new_tab[i][ii] = '\0';
		i++;
	}
	new_tab[i] = NULL;
}

size_t	ft_count_words(char const *s, char c)
{
	int		i;
	size_t	count_words;

	i = 0;
	count_words = 0;
	// printf("2");
	while (s[i] != '\0')
	{
		while ((s[i] != '\0') && (s[i] == c))
			i++;
		if ((s[i] != '\0') && (s[i] != c))
		{
			count_words++;
			while ((s[i] != '\0') && (s[i] != c))
				i++;
		}
	}
	return (count_words);
}

char	**ft_free(char **new_str, int i)
{
	// printf("3");
	while (i >= 0)
	{
		free(new_str[i]);
		i--;
	}
	free(new_str);
	return (NULL);
}

int	ft_count_letters(char const *s, char c, int j)
{
	int	counter_letters;

	counter_letters = 0;
	// printf("4");
	while ((s[j] != c) && (s[j] != '\0'))
	{
		counter_letters++;
		j++;
	}
	return (counter_letters);
}

char	**ft_split(char *s, char c)
{
	int		counter_letters;
	char	**new_tab;

	int (i) = 0;
	int (j) = 0;
	// printf("5");
	new_tab = malloc(sizeof(char *) * ((ft_count_words(s, c) + 1)));
	if (new_tab == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		while ((s[j] == c) && (s[j] != '\0'))
			j++;
		if (s[j] != '\0')
		{
			counter_letters = ft_count_letters(s, c, j);
			new_tab[i] = malloc(sizeof(char) * (counter_letters + 1));
			if (new_tab[i] == NULL)
				return (ft_free(new_tab, i - 1));
			i++;
			j = j + counter_letters;
		}
	}
	ft_write_in_tab(s, new_tab, c, ft_count_words(s, c));
	return (new_tab);
}

