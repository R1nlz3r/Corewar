/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:11:55 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 14:13:54 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		count;
	char		*tmp;
	const char	*tmp2;

	if (dest == NULL || src == NULL)
		return (NULL);
	tmp = dest;
	tmp2 = src;
	count = 0;
	while (count < n)
	{
		tmp[count] = tmp2[count];
		++count;
	}
	return (tmp);
}
