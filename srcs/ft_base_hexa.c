/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 09:37:11 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/26 12:03:06 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	recursive(unsigned int nbr, char *str, int size_int, char *base)
{
	if (nbr >= 16)
	{
		recursive(nbr / 16, str, size_int - 1, base);
		recursive(nbr % 16, str, size_int, base);
	}
	else
		str[size_int - 1] = base[nbr];
}

static int	ft_nbrlen(unsigned int nbr)
{
	int	compt;

	compt = 1;
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		compt++;
	}
	return (compt);
}

char	*ft_base_hexa(unsigned int nbr, char *base)
{
	char			*str;
	int				size_int;

	size_int = ft_nbrlen(nbr);
	str = malloc(sizeof(int) * size_int);
	if (!str)
		return (NULL);
	recursive(nbr, str, size_int, base);
	str[size_int] = '\0';
	return (str);
}
