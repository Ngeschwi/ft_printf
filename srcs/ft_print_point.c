/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@stutent.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 11:51:13 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/03/27 16:21:32 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_point(va_list args, t_info *Info)
{
	char	*point;

	if (Info->indice != 0)
	{
		point = va_arg(args, char*);
	while (point++)
		write(1, &point, 1);
	}
	return ;
}
