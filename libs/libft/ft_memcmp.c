/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:04:52 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/12 17:03:03 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t					count;
	const unsigned char		*tmp1;
	const unsigned char		*tmp2;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	if (n == 0)
		return (0);
	count = 0;
	tmp1 = s1;
	tmp2 = s2;
	while (count < n)
	{
		if (tmp1[count] != tmp2[count])
			return (tmp1[count] - tmp2[count]);
		++count;
	}
	return (0);
}
