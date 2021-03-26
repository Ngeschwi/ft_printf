/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_carac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:00:10 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/26 12:01:44 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_carac(va_list args, t_info *Info)
{
	if (Info->tab[Info->size_tab] == 99)
		ft_putchar((unsigned char) va_arg(args, int));
	else
		ft_putstr(va_arg(args, char *));
}

void	ft_check_carac(va_list args, t_info *Info)
{
	int	diff;

	if (Info->nbr_aff == 0)
		ft_printf_carac(args, Info);
	else
	{
		diff = Info->nbr_aff - ft_strlen(va_arg(args, char *));
		if (Info->minus == 0)
		{
			if (Info->zeros == 1)
				while (diff-- >= 0)
					ft_putchar('0');
			else
				while (diff-- >= 0)
					ft_putchar(' ');
			ft_printf_carac(args, Info);
		}
		else
		{
			ft_printf_carac(args, Info);
			while (diff-- >= 0)
				ft_putchar(' ');
		}
	}
}
