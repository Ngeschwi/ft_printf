/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_carac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:00:10 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/14 14:45:18 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_carac(t_info *Info, char *text)
{
	int	i;

	i = 0;
	if (Info->tab[Info->size_tab - 1] == 99)
		ft_putchar((char)text);
	else
	{
		if (Info->precision > 0)
		{
			while (i < ft_strlen(text) && i < Info->precision)
			{
				ft_putchar((char)text[i]);
				i++;
			}
		}
		else if (Info->precision == -1)
			return ;
		else
			ft_putstr(text);
	}
}

void	ft_print_carac_minus(t_info *Info, int diff, char *text)
{
	if (Info->zeros == 1)
		while (diff-- > 0)
			ft_putchar('0');
	else
		while (diff-- > 0)
			ft_putchar(' ');
	ft_printf_carac(Info, text);
}

int	ft_calcul_diff(t_info *Info, char *text)
{
	int	diff;

	if (Info->tab[Info->size_tab - 1] == 99)
		diff = Info->nbr_aff - 1;
	else
	{
		if (Info->precision == 0 && ft_strlen(text) > Info->precision)
			diff = Info->nbr_aff - ft_strlen(text);
		else if (Info->precision != 0 && ft_strlen(text) <= Info->precision)
			diff = Info->nbr_aff - ft_strlen(text);
		else
		{
			if (Info->precision == -1)
				diff = Info->nbr_aff - (Info->precision + 1);
			else
				diff = Info->nbr_aff - Info->precision;
		}
	}
	return (diff);
}

void	ft_check_carac(va_list args, t_info *Info)
{
	int		diff;
	char	*text;

	text = va_arg(args, char *);
	if (text == NULL && Info->tab[Info->size_tab - 1] == 115)
		text = "(null)";
	if (Info->nbr_aff == 0)
		ft_printf_carac(Info, text);
	else
	{
		diff = ft_calcul_diff(Info, text);
		if (Info->minus == 0)
			ft_print_carac_minus(Info, diff, text);
		else
		{
			ft_printf_carac(Info, text);
			while (diff-- > 0)
				ft_putchar(' ');
		}
	}
}
