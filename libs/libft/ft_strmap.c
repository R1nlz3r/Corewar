/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:03:53 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 20:03:47 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		count;
	char	*str;

	if (s != NULL && (*f) != NULL)
	{
		if ((str = malloc((ft_strlen((char *)(uintptr_t)s) + 1)
			* sizeof(char))) == NULL)
			return (NULL);
		count = -1;
		while (s[++count] != '\0')
			str[count] = (*f)(s[count]);
		str[ft_strlen((char *)(uintptr_t)s)] = '\0';
		return (str);
	}
	return (NULL);
}
