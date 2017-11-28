/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:27:22 by kda-silv          #+#    #+#             */
/*   Updated: 2017/10/04 21:08:12 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*str;
	size_t	count;

	if (s1 == NULL)
		return (NULL);
	count = 0;
	if ((str = malloc(sizeof(char) * (1 + ft_strlen((char *)(uintptr_t)s1))))
		== NULL)
		return (NULL);
	while (s1[count])
	{
		str[count] = s1[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
