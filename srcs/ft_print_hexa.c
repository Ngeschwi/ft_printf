/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:50:48 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/17 15:24:35 by ngeschwi         ###   ########.fr       */
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
	if (Info->precision == -1 && size_hexa == 1 && *nbr == 48)
		diff++;
	return (diff);
}

static void	ft_printf_hexa(t_info *Info, char *nbr)
{
	int		diff;

	if (Info->precision == -1 && nbr[0] == '0')
		return ;
	diff = Info->precision - ft_strlen(nbr);
	if (diff > 0)
		while (diff-- > 0)
			ft_putchar('0');
	ft_putstr(nbr);
	free(nbr);
}

static void	ft_print_hexa_minus(t_info *Info, int diff, char *nbr)
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
