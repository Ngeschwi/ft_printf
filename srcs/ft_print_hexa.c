/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:50:48 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/26 12:02:24 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_calcul_diff(t_info *Info, va_list args)
{
	int		diff;
	int		size_hexa;
	char	*nbr_hexa;

	nbr_hexa = ft_base_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	size_hexa = ft_strlen(nbr_hexa);
	if (Info->precision >= size_hexa)
		diff = Info->nbr_aff - Info->precision;
	else
		diff = Info->nbr_aff - size_hexa;
	return (diff);
}

void	ft_printf_hexa(va_list args, t_info *Info)
{
	char	*nbr;
	int		diff;

	if (Info->tab[Info->size_tab] == 120)
	{
		nbr = ft_base_hexa(va_arg(args, unsigned int), "0123456789abcdef");
		diff = Info->precision - ft_strlen(nbr);
		if (diff > 0)
			while (diff-- != 0)
				write(1, "0", 1);
		ft_putstr(nbr);
	}
	if (Info->tab[Info->size_tab] == 88)
	{
		nbr = ft_base_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
		diff = Info->precision - ft_strlen(nbr);
		if (diff > 0)
			while (diff-- != 0)
				write(1, "0", 1);
		ft_putstr(nbr);
	}
	Info->indice++;
}

void	ft_check_hexa(va_list args, t_info *Info)
{
	int		diff;

	if (Info->nbr_aff == 0)
		ft_printf_hexa(args, Info);
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
			ft_printf_hexa(args, Info);
		}
		else
		{
			ft_printf_hexa(args, Info);
			while (diff-- >= 0)
				ft_putchar(' ');
		}
	}
}
