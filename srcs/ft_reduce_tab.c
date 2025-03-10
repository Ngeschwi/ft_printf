/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:07:11 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/26 12:03:06 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_reduce_tab(char *nbr)
{
	int		size_nbr;
	int		i;
	char	*new_nbr;

	i = 1;
	size_nbr = ft_strlen(nbr);
	new_nbr = malloc(sizeof(char) * size_nbr);
	if (!new_nbr)
		return (NULL);
	while (i <= size_nbr)
	{
		new_nbr[i - 1] = nbr[i];
		i++;
	}
	return (new_nbr);
}
