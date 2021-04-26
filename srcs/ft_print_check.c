/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:03:58 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/26 14:43:14 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_which_conver(va_list args, t_info *Info)
{
	if (Info->tab[Info->size_tab - 1] == 99)
		ft_check_carac(args, Info);
	else if (Info->tab[Info->size_tab - 1] == 115)
		ft_check_carac(args, Info);
	else if (Info->tab[Info->size_tab - 1] == 112)
		ft_check_point(args, Info);
	else if (Info->tab[Info->size_tab - 1] == 100)
		ft_check_int(args, Info);
	else if (Info->tab[Info->size_tab - 1] == 105)
		ft_check_int(args, Info);
	else if (Info->tab[Info->size_tab - 1] == 117)
		ft_check_int(args, Info);
	else if (Info->tab[Info->size_tab - 1] == 120)
		ft_check_hexa(args, Info);
	else if (Info->tab[Info->size_tab - 1] == 88)
		ft_check_hexa(args, Info);
	else if (Info->tab[Info->size_tab - 1] == 37)
		ft_printf_pc(Info);
}

static int	ft_len_nbr(t_info *Info, int i)
{
	int		size;

	size = 0;
	while (ft_isdigit(Info->tab[i]) && i > 0)
	{
		size++;
		i--;
	}
	return (size);
}

static int	ft_wich_one(t_info *Info, int i, char *nbr)
{
	if (Info->tab[i] == '%' && Info->nbr_aff == 0)
		Info->nbr_aff = ft_atoi(nbr);
	else if (Info->tab[i] == '-' && Info->nbr_aff == 0)
	{
		Info->minus = 1;
		Info->nbr_aff = ft_atoi(nbr);
	}
	else if (Info->tab[i] == '.' && Info->precision == 0)
	{
		if (ft_atoi(nbr) == 0)
			Info->precision = -1;
		else
			Info->precision = ft_atoi(nbr);
	}
	if (Info->tab[i + 1] == '0' && ft_strlen(nbr) != 1)
		Info->zeros = 1;
	if (Info->nbr_aff != 0 && Info->precision == -1)
		if (Info->tab[Info->size_tab] == 100
			|| Info->tab[Info->size_tab] == 105
			|| Info->tab[Info->size_tab] == 117)
			Info->precision = 0;
	i--;
	return (i);
}

static int	ft_check_flag(t_info *Info, int i)
{
	if (Info->tab[i] == '.' && Info->precision == 0)
		Info->precision = -1;
	i--;
	return (i);
}

void	ft_check_tab(va_list args, t_info *Info)
{
	char	*nbr;
	int		i;
	int		size_nbr;

	i = Info->size_tab - 2;
	while (i >= 0)
	{
		while (!ft_isdigit(Info->tab[i]) && i > 0)
			i = ft_check_flag(Info, i);
		size_nbr = ft_len_nbr(Info, i);
		nbr = malloc(sizeof(char) * (size_nbr + 1));
		nbr[size_nbr] = '\0';
		while (size_nbr > 0)
		{
			nbr[size_nbr - 1] = Info->tab[i];
			size_nbr--;
			i--;
		}
		i = ft_wich_one(Info, i, nbr);
		free(nbr);
	}
	if (Info->minus == 1 || Info->precision != 0)
		if (Info->tab[Info->size_tab - 1] != 37)
			Info->zeros = 0;
	ft_which_conver(args, Info);
}
