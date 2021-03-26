/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:41:41 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/25 10:09:17 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		total;
	int		nbrless;

	nbrless = 1;
	i = 0;
	total = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nbrless = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	return (total * nbrless);
}
