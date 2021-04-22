/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:12:57 by ngeschwi          #+#    #+#             */
/*   Updated: 2021/04/22 15:36:17 by ngeschwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_malloc(int size)
{
	char	*str;

	str = malloc(sizeof(char) * (size));
	if (!str)
		return (NULL);
	return (str);
}
