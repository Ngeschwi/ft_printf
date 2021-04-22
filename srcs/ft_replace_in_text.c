/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_in_text.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:37:52 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/22 10:14:01 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_remove_point(char *tab, t_info *Info)
{
	char	*new_tab;
	int		size_tab;
	int		i;

	i = 0;
	size_tab = ft_strlen(tab);
	new_tab = malloc(sizeof(char) * size_tab);
	if (!new_tab)
		return (NULL);
	while (i < size_tab - 1)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = '\0';
	free(Info->new_tab);
	return (new_tab);
}

static int	ft_len_split(char **split_tab)
{
	int	i;

	i = 0;
	while (split_tab[i])
		i++;
	return (i);
}

static void	ft_free(t_info *Info)
{
	int	i;

	i = 0;
	while (i < ft_len_split(Info->split_tab))
	{
		free(Info->split_tab[i]);
		i++;
	}
	free(Info->new_tab);
}

void	ft_replace_in_text(t_info *Info, va_list args)
{
	int		i;
	int		len_split_tab;

	i = 0;
	Info->split_tab = ft_split(Info->tab, '*');
	while (i < ft_len_split(Info->split_tab) - 1)
	{
		Info->new_tab = ft_strjoin(Info->new_tab, Info->split_tab[i], Info);
		len_split_tab = ft_strlen(Info->split_tab[i]);
		Info->star = ft_itoa(va_arg(args, int));
		if (Info->split_tab[i][len_split_tab - 1] == '.'
			&& Info->star[0] == '-')
			Info->new_tab = ft_remove_point(Info->new_tab, Info);
		else
			Info->new_tab = ft_strjoin(Info->new_tab, Info->star, Info);
		i++;
		free(Info->star);
	}
	Info->new_tab = ft_strjoin(Info->new_tab, Info->split_tab[i], Info);
	free(Info->tab);
	Info->tab = ft_strdup(Info->new_tab);
	ft_free(Info);
	free(Info->split_tab);
}
