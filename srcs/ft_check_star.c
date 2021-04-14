/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_star.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:25:14 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/14 16:42:17 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_check_star(t_info *Info, const char *text)
{
	int	i;

	if (text[Info->indice - 1] == '.' && Info->star[0] == '-')
	{
		Info->size_tab -= 2;
		Info->error_star = 1;
		return (0);
	}
	if (Info->star[0] == '-')
		i = 1;
	else
		i = 0;
	while (Info->star[i])
	{
		if (!ft_isdigit(Info->star[i]))
			return (0);
		i++;
	}
	if (ft_strlen(Info->star) == 0)
		return (0);
	return (1);
}

int	ft_replace_star(t_info *Info, int i)
{
	int	count;

	count = 0;
	if (Info->error_star)
	{
		Info->indice++;
		Info->error_star = 0;
		i--;
		Info->tab[i] = '\0';
		return (i);
	}
	while (count < Info->size_star)
	{
		Info->tab[i] = Info->star[count];
		i++;
		count++;
	}
	Info->indice++;
	return (i);
}
