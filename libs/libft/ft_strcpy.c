/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:43:20 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/12 16:59:52 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	int		count;

	if (dest == NULL || src == NULL)
		return (NULL);
	count = -1;
	while (src[++count] != '\0')
		dest[count] = src[count];
	dest[count] = '\0';
	return (dest);
}
