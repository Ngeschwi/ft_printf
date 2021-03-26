/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:38:20 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/26 13:39:49 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_get_tab(const char *text, va_list args, t_info *Info)
{
	const char	*list_conver;
	int			i;

	list_conver = "cspdiuxX%";
	i = 0;
	Info->indice -= Info->size_tab - 1;
	while (i++ < Info->size_tab)
	{
		Info->tab[i] = text[Info->indice];
		Info->indice++;
	}
	Info->tab[i] = '\0';
	i = 0;
	Info->indice--;
	while (list_conver[i])
	{
		if (list_conver[i] == Info->tab[Info->size_tab])
			ft_check_tab(text, args, Info);
		i++;
	}
	Info->indice--;
	free(Info->tab);
}

static int	ft_len_tab(const char *text, t_info *Info)
{
	int	i;

	i = 0;
	while (text[Info->indice])
	{
		if (ft_isalpha(text[Info->indice]))
		{
			Info->size_tab = i + 1;
			return (i + 1);
		}
		else
			i++;
		Info->indice++;
	}
	Info->size_tab = i + 1;
	return (i + 1);
}

int	ft_printf(const char *text, ...)
{
	va_list		args;
	t_info		Info;

	Info.indice = 0;
	va_start(args, text);
	while (text[Info.indice])
	{
		if (text[Info.indice] == '%')
		{
			Info.tab = malloc(sizeof(char) * ft_len_tab(text, &Info) + 1);
			ft_get_tab(text, args, &Info);
		}
		else
			ft_putchar(text[Info.indice]);
		Info.indice++;
	}
	va_end(args);
	return (1);
}

int	main()
{
	ft_printf("x  = %d", 15);
}