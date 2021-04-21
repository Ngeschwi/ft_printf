/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 19:32:56 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/21 14:56:39 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr(char *str, t_info *Info)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		Info->nbr_final++;
		write(1, &str[i], 1);
		i++;
	}
}
