/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 09:37:11 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/27 16:07:52 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	recursive(unsigned int nbr, char *str, int size_int, char *base)
{
	long int	a;

	a = nbr;
	if (a < 0)
	{
		write(1, "-", 1);
		a = -a;
	}
	if (a >= 16)
	{
		recursive(a / 16, str, size_int - 1, base);
		recursive(a % 16, str, size_int, base);
	}
	else
		str[size_int - 1] = base[a];
}

static int	ft_nbrlen(int nbr)
{
	int	compt;

	compt = 0;
	while (nbr >= 16)
	{
		nbr = nbr / 16;
		compt++;
	}
	return (compt + 1);
}

char	*ft_base_hexa(unsigned int nbr, char *base)
{
	unsigned int	nb;
	char			*str;
	int				size_int;

	nb = nbr;
	size_int = ft_nbrlen(nbr);
	str = malloc(sizeof(int) * size_int + 1);
	if (str == NULL)
		return (NULL);
	recursive(nb, str, size_int, base);
	return (str);
}
