/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:03:58 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/26 13:35:09 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_which_conver(const char *text, va_list args, t_info *Info)
{
	if (Info->tab[Info->size_tab] == 'c')
		ft_check_carac(args, Info);
	else if (Info->tab[Info->size_tab] == 115)
		ft_check_carac(args, Info);
	else if (Info->tab[Info->size_tab] == 112)
		ft_check_point(text, args, Info);
	else if (Info->tab[Info->size_tab] == 100)
		ft_check_int(args, Info);
	else if (Info->tab[Info->size_tab] == 105)
		ft_check_int(args, Info);
	else if (Info->tab[Info->size_tab] == 117)
		ft_check_int(args, Info);
	else if (Info->tab[Info->size_tab] == 120)
		ft_check_hexa(args, Info);
	else if (Info->tab[Info->size_tab] == 88)
		ft_check_hexa(args, Info);
	else if (Info->tab[Info->size_tab] == 37)
	{
		ft_putchar(Info->tab[Info->size_tab]);
		Info->indice++;
	}
}

static int	ft_len_nbr(t_info *Info, int i)
{
	int		size;

	size = 0;
	while (ft_isdigit(Info->tab[i--]) && i >= 0)
		size++;
	return (size);
}

static void	ft_wich_one(t_info *Info, int i, char *nbr)
{
	if (Info->tab[i] == '%' && Info->nbr_aff == 0)
		Info->nbr_aff = ft_atoi(nbr);
	else if (Info->tab[i] == '-' && Info->nbr_aff == 0)
	{
		Info->minus = 1;
		Info->nbr_aff = ft_atoi(nbr);
	}
	else if (Info->tab[i] == '.' && Info->precision == 0)
		Info->precision = ft_atoi(nbr);
	if (Info->tab[i + 1] == 0)
		Info->minus = 1;
}

void	ft_check_tab(const char *text, va_list args, t_info *Info)
{
	char	*nbr;
	int		i;
	int		size_nbr;
	
	i = Info->size_tab - 1;
	size_nbr = ft_len_nbr(Info, i);
	while (i >= 0)
	{
		while (!ft_isdigit(Info->tab[i]) && i >= 0)
			i--;
		nbr = malloc(sizeof(char) * size_nbr + 1);
		while (ft_isdigit(Info->tab[i]) && i >= 0)
		{
			nbr[size_nbr] = Info->tab[i];
			i--;
		}
		ft_wich_one(Info, i, nbr);
		free(nbr);
		i--;
	}
	if (Info->minus == 1)
		Info->zeros = 0;
	ft_which_conver(text, args, Info);
}
