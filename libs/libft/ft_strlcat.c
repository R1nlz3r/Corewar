/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:30:07 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/23 12:28:07 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	size_dest;

	if (dest == NULL || src == NULL)
		return (0);
	count = 0;
	while (count < size && dest[count] != '\0')
		++count;
	size_dest = count;
	while (src[count - size_dest] != '\0' && count < (size - 1))
	{
		dest[count] = src[count - size_dest];
		++count;
	}
	if (size_dest < size)
		dest[count] = '\0';
	return (size_dest + ft_strlen((char *)(uintptr_t)src));
}
