/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:38:47 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/02 08:58:41 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_calcul_diff(t_info *Info, char *nbr)
{
	int		diff;

	if (Info->precision >= ft_strlen(nbr))
		diff = Info->nbr_aff - Info->precision;
	else
		diff = Info->nbr_aff - ft_strlen(nbr);
	return (diff);
}

void	ft_printf_int(t_info *Info, char *nbr)
{
	int		diff;

	if (nbr[0] == '-')
	{
		nbr = ft_reduce_tab(nbr);
		if (!(Info->zeros == 1 && Info->nbr_aff != 0))
			ft_putchar('-');
	}
	if (Info->tab[Info->size_tab - 1] == 117)
	{
		diff = Info->precision - ft_strlen(nbr);
		if (diff > 0)
			while (diff-- > 0)
				write(1, "0", 1);
		ft_putstr(nbr);
	}
	else
	{
		diff = Info->precision - ft_strlen(nbr);
		if (diff > 0)
			while (diff-- > 0)
				write(1, "0", 1);
		ft_putstr(nbr);
	}
}

void	ft_print_int_minus(t_info *Info, int diff, char *nbr)
{
	if (Info->zeros == 1)
	{
		if (nbr[0] == '-')
		{
			ft_putchar('-');
			diff++;
		}
		while (diff-- > 0)
			ft_putchar('0');
	}
	else
		while (diff-- > 0)
			ft_putchar(' ');
	ft_printf_int(Info, nbr);
}

void	ft_check_int(va_list args, t_info *Info)
{
	int		diff;
	char	*nbr;

	if (Info->tab[Info->size_tab - 1] == 117)
		nbr = ft_utoa(va_arg(args, unsigned int));
	else
		nbr = ft_itoa(va_arg(args, int));
	if (Info->nbr_aff == 0)
		ft_printf_int(Info, nbr);
	else
	{
		diff = ft_calcul_diff(Info, nbr);
		if (nbr[0] == '-' && (Info->precision != 0 || Info->zeros != 0))
			diff--;
		if (Info->minus == 0)
			ft_print_int_minus(Info, diff, nbr);
		else
		{
			ft_printf_int(Info, nbr);
			while (diff-- > 0)
				ft_putchar(' ');
		}
	}
}
