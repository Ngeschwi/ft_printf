/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:38:20 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/21 10:50:34 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_get_tab(const char *text, va_list args, t_info *Info)
{
	const char	*list_conver;
	int			i;

	list_conver = "cspdiuxX%";
	i = 0;
	Info->indice -= (Info->size_tab - 1);
	while (i < Info->size_tab)
	{
		Info->tab[i] = text[Info->indice];
		Info->indice++;
		i++;
	}
	Info->tab[i] = '\0';
	i = 0;
	ft_replace_in_text(Info, args);
	Info->size_tab = ft_strlen(Info->tab);
	while (list_conver[i])
	{
		if (list_conver[i] == Info->tab[Info->size_tab - 1])
			ft_check_tab(args, Info);
		i++;
	}
}

static int	ft_len_tab(const char *text, t_info *Info)
{
	int		i;
	int		count;

	i = 1;
	while (text[Info->indice] && !ft_isalpha(text[Info->indice]))
	{
		count = 0;
		if (text[Info->indice] == '%')
			break ;
		i++;
		Info->indice++;
	}
	Info->size_tab += i + 1;
	return (Info->size_tab);
}

static void	ft_init_struct(t_info *Info)
{
	Info->size_tab = 0;
	Info->minus = 0;
	Info->zeros = 0;
	Info->nbr_aff = 0;
	Info->precision = 0;
	Info->star = NULL;
	Info->new_tab = NULL;
	Info->split_tab = NULL;
}

int	ft_printf(const char *text, ...)
{
	va_list		args;
	t_info		Info;

	ft_init_struct(&Info);
	Info.indice = 0;
	va_start(args, text);
	while (text[Info.indice])
	{
		if (text[Info.indice] == '%')
		{
			Info.indice++;
			Info.tab = malloc(sizeof(char) * (ft_len_tab(text, &Info) + 1));
			ft_get_tab(text, args, &Info);
			Info.indice--;
			free(Info.tab);
			ft_init_struct(&Info);
		}
		else
			ft_putchar(text[Info.indice]);
		Info.indice++;
	}
	va_end(args);
	return (1);
}
