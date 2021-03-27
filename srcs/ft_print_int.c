/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:38:47 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/27 17:16:52 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_calcul_diff(t_info *Info, va_list args)
{
	int	diff;

	if (Info->precision >= ft_strlen(va_arg(args, char *)))
		diff = Info->nbr_aff - Info->precision;
	else
		diff = Info->nbr_aff - ft_strlen(va_arg(args, char *));
	return (diff);
}

void	ft_printf_int(va_list args, t_info *Info)
{
	char	*nbr;
	int		diff;

	if (Info->tab[Info->size_tab] == 117)
	{
		nbr = ft_utoa(va_arg(args, unsigned int));
		diff = Info->precision - ft_strlen(nbr);
		if (diff > 0)
			while (diff-- != 0)
				write(1, "0", 1);
		ft_putstr(nbr);
	}
	else
	{
		nbr = ft_itoa(va_arg(args, int));
		diff = Info->precision - ft_strlen(nbr);
		if (diff > 0)
			while (diff-- != 0)
				write(1, "0", 1);
		ft_putstr(nbr);
	}
}

void	ft_check_int(va_list args, t_info *Info)
{
	int	diff;

	if (Info->nbr_aff == 0)
		ft_printf_int(args, Info);
	else
	{
		diff = ft_calcul_diff(Info, args);
		if (Info->minus == 0)
		{
			if (Info->zeros == 1)
				while (diff-- >= 0)
					ft_putchar('0');
			else
				while (diff-- >= 0)
					ft_putchar(' ');
			ft_printf_int(args, Info);
		}
		else
		{
			ft_printf_int(args, Info);
			while (diff-- >= 0)
				ft_putchar(' ');
		}
	}
}
