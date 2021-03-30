/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_carac.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:00:10 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/30 10:10:33 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_carac(t_info *Info, char *text)
{
	if (Info->tab[Info->size_tab - 1] == 99)
	{
		ft_putchar((char)text);
	}
	else
		ft_putstr(text);
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

void	ft_check_carac(va_list args, t_info *Info)
{
	int	diff;
	char *text;

	if (Info->tab[Info->size_tab - 1] == 99)
		text = va_arg(args, char *);
	else
		text = va_arg(args, char *);
	if (Info->nbr_aff == 0)
		ft_printf_carac(Info, text);
	else
	{
		diff = Info->nbr_aff - ft_strlen(va_arg(args, char *));
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
