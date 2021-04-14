/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_change_star.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:25:14 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/14 14:43:52 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_del_zero(t_info *Info)
{
	int	i;

	i = 0;
	if (ft_strlen(Info->star) == 1)
	{
		Info->star[0] = '\0';
		return ;
	}
	while (Info->star[i + 1])
	{
		Info->star[i] = Info->star[i + 1];
		i++;
	}
	Info->star[i + 1] = '\0';
}

int	ft_check_change_star(t_info *Info)
{
	int	i;

	i = 0;
	while (Info->star[i])
	{
		if (!ft_isdigit(Info->star[i]))
			return (0);
		i++;
	}
	while (Info->star[0] == '0')
		ft_del_zero(Info);
	if (ft_strlen(Info->star) == 0)
		return (0);
	return (1);
}

int	ft_replace_star(t_info *Info, int i)
{
	int	count;

	count = 0;
	Info->size_star = ft_strlen(Info->star);
	while (count < Info->size_star)
	{
		Info->tab[i] = Info->star[count];
		i++;
		count++;
	}
	Info->indice++;
	return (i);
}
