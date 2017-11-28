/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:00:25 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/12 17:02:32 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		count;
	char		*tmp;
	const char	*tmp2;

	count = 0;
	if (src == NULL || dest == NULL)
		return (NULL);
	tmp = dest;
	tmp2 = src;
	while (count < n)
	{
		if ((*tmp++ = *tmp2++) == c)
			return (tmp);
		++count;
	}
	return (NULL);
}
