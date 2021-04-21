/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:37:30 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/21 14:57:56 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_pc(t_info *Info)
{
	int	i;

	i = 1;
	if (Info->minus == 0)
	{
		if (Info->zeros == 0)
			while (i++ < Info->nbr_aff)
				ft_putchar(' ', Info);
		else
			while (i++ < Info->nbr_aff)
				ft_putchar('0', Info);
		ft_putchar('%', Info);
	}
	else
	{
		ft_putchar('%', Info);
		while (i++ < Info->nbr_aff)
			ft_putchar(' ', Info);
	}
}
