/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:53:18 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/26 12:03:06 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_n(unsigned int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i + 1);
}

static void	ft_recursive(unsigned int n, char *str, int size_int)
{
	unsigned int	nbr;

	nbr = n;
	if (nbr >= 10)
	{
		ft_recursive(nbr / 10, str, size_int - 1);
		ft_recursive(nbr % 10, str, size_int);
	}
	else
		str[size_int] = nbr + '0';
}

char	*ft_utoa(unsigned int n)
{
	char			*str;
	int				size_int;

	size_int = ft_size_n(n);
	str = malloc(sizeof(char) * size_int + 1);
	if (str == NULL)
		return (NULL);
	ft_recursive(n, str, size_int - 1);
	str[size_int] = '\0';
	return (str);
}
