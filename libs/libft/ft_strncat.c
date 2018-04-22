/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:24:14 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/12 17:05:09 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	int		size_dest;
	int		count;

	if (dest == NULL || src == NULL)
		return (NULL);
	count = 0;
	while (dest[count] != '\0')
		++count;
	size_dest = count;
	count = -1;
	while (src[++count] != '\0' && n > 0)
	{
		dest[size_dest + count] = src[count];
		--n;
	}
	dest[size_dest + count] = '\0';
	return (dest);
}
