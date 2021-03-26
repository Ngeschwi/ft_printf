/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 12:02:08 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/25 10:09:30 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_size_n(int n)
{
	int				i;
	unsigned int	nbr;

	i = 0;
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i + 1);
}

static void	ft_recursive(int n, char *str, int size_int)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		nbr = -n;
	}
	if (nbr >= 10)
	{
		ft_recursive(nbr / 10, str, size_int - 1);
		ft_recursive(nbr % 10, str, size_int);
	}
	else
		str[size_int] = nbr + '0';
}

char	*ft_itoa(int n)
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
