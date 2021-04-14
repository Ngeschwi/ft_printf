/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 09:38:20 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/14 16:53:19 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_calcul_indice(t_info *Info)
{
	if (Info->star == NULL)
		Info->indice -= (Info->size_tab - 1);
	else if (Info->error_star == 0)
		Info->indice -= Info->size_tab - Info->size_star;
	else
		Info->indice -= Info->size_tab + 1;
}

static void	ft_get_tab(const char *text, va_list args, t_info *Info)
{
	const char	*list_conver;
	int			i;

	list_conver = "cspdiuxX%";
	i = 0;
	ft_calcul_indice(Info);
	while (i < (Info->size_tab + Info->error_star))
	{
		if (text[Info->indice] == '*')
			i = ft_replace_star(Info, i);
		else
		{
			Info->tab[i] = text[Info->indice];
			Info->indice++;
			i++;
		}
	}
	Info->tab[i] = '\0';
	i = 0;
	while (list_conver[i])
	{
		if (list_conver[i] == Info->tab[Info->size_tab - 1])
			ft_check_tab(args, Info);
		i++;
	}
}

static int	ft_len_tab(const char *text, t_info *Info, va_list args)
{
	int	i;
	int	count;

	i = 1;
	while (text[Info->indice] && !ft_isalpha(text[Info->indice]))
	{
		count = 0;
		if (text[Info->indice] == '%')
			break ;
		if (text[Info->indice] == '*')
		{
			Info->star = ft_itoa(va_arg(args, int));
			Info->size_star = ft_strlen(Info->star);
			if (!ft_check_star(Info, text))
				break ;
			while (Info->star[count++])
				i++;
			i--;
		}
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
	Info->error_star = 0;
	Info->star = NULL;
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
			printf("%d\n", Info.indice);
			Info.tab = malloc(sizeof(char) * (ft_len_tab(text, &Info, args) + 1));
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

int	main()
{
	printf("{%.*d}\n", -5, 42);
	ft_printf("{%.*d}\n", -5, 42);
}