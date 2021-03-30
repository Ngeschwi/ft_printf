/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:50:48 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/30 10:11:20 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_calcul_diff(t_info *Info, char *nbr)
{
	int		diff;
	int		size_hexa;

	size_hexa = ft_strlen(nbr);
	if (Info->precision >= size_hexa)
		diff = Info->nbr_aff - Info->precision;
	else
		diff = Info->nbr_aff - size_hexa;
	return (diff);
}

void	ft_printf_hexa(t_info *Info, char *nbr)
{
	int		diff;

	if (Info->tab[Info->size_tab - 1] == 120)
	{
		diff = Info->precision - ft_strlen(nbr);
		if (diff > 0)
			while (diff-- != 0)
				write(1, "0", 1);
		ft_putstr(nbr);
	}
	else
	{
		diff = Info->precision - ft_strlen(nbr);
		if (diff > 0)
			while (diff-- != 0)
				write(1, "0", 1);
		ft_putstr(nbr);
	}
}

void	ft_print_hexa_minus(t_info *Info, int diff, char *nbr)
{
	if (Info->zeros == 1)
		while (diff-- > 0)
			ft_putchar('0');
	else
		while (diff-- > 0)
			ft_putchar(' ');
	ft_printf_hexa(Info, nbr);
}

void	ft_check_hexa(va_list args, t_info *Info)
{
	int		diff;
	char	*nbr;
	if (Info->tab[Info->size_tab - 1] == 120)
		nbr = ft_base_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	else
		nbr = ft_base_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (Info->nbr_aff == 0)
		ft_printf_hexa(Info, nbr);
	else
	{
		diff = ft_calcul_diff(Info, nbr);
		if (Info->minus == 0)
			ft_print_hexa_minus(Info, diff, nbr);
		else
		{
			ft_printf_hexa(Info, nbr);
			while (diff-- > 0)
				ft_putchar(' ');
		}
	}
}
