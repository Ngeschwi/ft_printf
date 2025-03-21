/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:51:13 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/26 12:03:06 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ull_base(unsigned long long ull)
{
	char				*val_rtn;
	unsigned long long	ull_save;
	int					count;
	char				*base;

	base = "0123456789abcdef";
	count = 0;
	ull_save = ull;
	while (ull >= 16)
	{
		ull /= 16;
		count++;
	}
	val_rtn = malloc(sizeof(char) * (count + 1));
	if (!val_rtn)
		return (0);
	val_rtn[count + 1] = '\0';
	while (count >= 0)
	{
		val_rtn[count] = base[ull_save % 16];
		ull_save /= 16;
		count--;
	}
	return (val_rtn);
}

static int	ft_calcul_diff(t_info *Info, char *point)
{
	int	diff;

	if (Info->precision >= (ft_strlen(point) + 2))
		diff = Info->nbr_aff - Info->nbr_aff;
	else
		diff = Info->nbr_aff - (ft_strlen(point) + 2);
	if (Info->precision == -1 && ft_strlen(point) == 1 && *point == 48)
		diff++;
	return (diff);
}

static void	ft_printf_point(t_info *Info, char *point)
{
	int	diff;

	diff = Info->precision - ft_strlen(point);
	if (Info->zeros == 0)
		ft_putstr("0x", Info);
	if (diff > 0)
		while (diff-- > 0)
			ft_putchar('0', Info);
	if ((ft_strlen(point) != 1 && *point != 48) || Info->precision != -1)
		ft_putstr(point, Info);
	free(point);
}

static void	ft_print_point_minus(t_info *Info, int diff, char *point)
{
	if (Info->zeros == 1)
	{
		ft_putstr("0x", Info);
		while (diff-- > 0)
			ft_putchar('0', Info);
	}
	else
		while (diff-- > 0)
			ft_putchar(' ', Info);
	ft_printf_point(Info, point);
}

void	ft_check_point(va_list args, t_info *Info)
{
	char				*point;
	unsigned long long	ull;
	int					diff;

	ull = va_arg(args, unsigned long long);
	point = ft_ull_base(ull);
	if (Info->nbr_aff == 0)
		ft_printf_point(Info, point);
	else
	{
		diff = ft_calcul_diff(Info, point);
		if (Info->minus == 0)
			ft_print_point_minus(Info, diff, point);
		else
		{
			ft_printf_point(Info, point);
			while (diff-- > 0)
				ft_putchar(' ', Info);
		}
	}
}
