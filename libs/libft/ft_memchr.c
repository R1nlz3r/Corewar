/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:07:13 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:14:52 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t				count;
	unsigned char		*tmp;
	unsigned char		tmp_c;

	count = 0;
	if (s == NULL)
		return (NULL);
	tmp = (unsigned char *)(uintptr_t)s;
	tmp_c = (unsigned char)c;
	while (count < n)
	{
		if (*tmp == tmp_c)
			return ((void *)tmp);
		tmp++;
		++count;
	}
	return (NULL);
}
