/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:38:47 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/26 12:03:06 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calcul_diff(t_info *Info, char *nbr)
{
	int		diff;

	if (Info->precision >= ft_strlen(nbr))
		diff = Info->nbr_aff - Info->precision;
	else
		diff = Info->nbr_aff - ft_strlen(nbr);
	if (Info->precision == -1 && ft_atoi(nbr) == 0)
		diff++;
	if (nbr[0] == '-' && (Info->precision >= ft_strlen(nbr)
			|| Info->zeros == 1
			|| Info->precision == -1))
		diff--;
	return (diff);
}

static void	ft_printf_int(t_info *Info, char *nbr)
{
	int		diff;
	char	*nbr_save;

	if (nbr[0] == '-')
	{
		nbr_save = ft_reduce_tab(nbr);
		free(nbr);
		nbr = ft_strdup(nbr_save);
		free(nbr_save);
		if (!(Info->zeros == 1 && Info->nbr_aff != 0))
			ft_putchar('-', Info);
	}
	if (Info->precision == -1 && nbr[0] == '0')
	{
		free(nbr);
		return ;
	}
	diff = Info->precision - ft_strlen(nbr);
	if (diff > 0)
		while (diff-- > 0)
			ft_putchar('0', Info);
	ft_putstr(nbr, Info);
	free(nbr);
}

static void	ft_print_int_minus(t_info *Info, int diff, char *nbr)
{
	if (Info->zeros == 1)
	{
		if (nbr[0] == '-')
		{
			ft_putchar('-', Info);
			diff++;
		}
		while (diff-- > 0)
			ft_putchar('0', Info);
	}
	else
		while (diff-- > 0)
			ft_putchar(' ', Info);
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
		if (Info->minus == 0)
			ft_print_int_minus(Info, diff, nbr);
		else
		{
			ft_printf_int(Info, nbr);
			while (diff-- > 0)
				ft_putchar(' ', Info);
		}
	}
}
