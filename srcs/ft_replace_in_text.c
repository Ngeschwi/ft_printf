/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_in_text.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:37:52 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/20 16:56:20 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_remove_point(char *tab)
{
	char	*new_tab;
	int		size_tab;
	int		i;

	i = 0;
	size_tab = ft_strlen(tab);
	new_tab = malloc(sizeof(char) * size_tab);
	while (i < size_tab - 1)
	{
		new_tab[i] = tab[i];
		i++;
	}
	new_tab[i] = '\0';
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

void	ft_replace_in_text(t_info *Info, va_list args)
{
	char	**split_tab;
	char	*new_tab;
	int		i_nbr_split;
	int		len_split_tab;

	i_nbr_split = 0;
	split_tab = ft_split(Info->tab, '*');
	while (i_nbr_split < ft_len_split(split_tab) - 1)
	{
		new_tab = ft_strjoin(new_tab, split_tab[i_nbr_split]);
		len_split_tab = ft_strlen(split_tab[i_nbr_split]);
		Info->star = ft_itoa(va_arg(args, int));
		if (split_tab[i_nbr_split][len_split_tab - 1] == '.'
			&& Info->star[0] == '-')
			new_tab = ft_remove_point(new_tab);
		else
			new_tab = ft_strjoin(new_tab, Info->star);
		i_nbr_split++;
		free(Info->star);
	}
	new_tab = ft_strjoin(new_tab, split_tab[i_nbr_split]);
	free(Info->tab);
	Info->tab = ft_strdup(new_tab);
	free(split_tab);
	free(new_tab);
}
