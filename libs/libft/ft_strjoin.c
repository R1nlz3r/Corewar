/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:34:38 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:28:05 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		if ((str = malloc(((ft_strlen((char *)(uintptr_t)s1)
			+ ft_strlen((char *)(uintptr_t)s2)) + 1) * sizeof(char))) == NULL)
			return (NULL);
		ft_bzero(str, ((ft_strlen((char *)(uintptr_t)s1)
			+ ft_strlen((char *)(uintptr_t)s2)) + 1));
		str = ft_strcat(str, s1);
		str = ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}
