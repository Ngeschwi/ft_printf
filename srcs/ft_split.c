/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 11:26:24 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/22 10:07:38 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	*free_tab(char **tab, int i)
{
	while (i--)
		free(tab[i]);
	free(tab);
	return (NULL);
}

static int	size_word(char const *s, char c, int i)
{
	int		size;

	size = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static int	count_word(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i + 1] == '\0')
			count++;
		else if (s[i] != c && s[i + 1] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	while (j < count_word(s, c))
	{
		k = 0;
		tab[j] = malloc(sizeof(char) * (size_word(s, c, i) + 1));
		if (tab[j] == NULL)
			return ((char **)free_tab(tab, j));
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			tab[j][k++] = s[i++];
		tab[j++][k] = '\0';
	}
	tab[j] = NULL;
	return (tab);
}
