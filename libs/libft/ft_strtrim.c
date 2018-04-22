/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:22:48 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:29:18 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	int		count;
	size_t	size;
	char	*str;

	if (s == NULL)
		return (NULL);
	size = ft_strlen((char *)(uintptr_t)s);
	while (s[size - 1] == ' ' || s[size - 1] == '\t' || s[size - 1] == '\n')
		size--;
	count = -1;
	while (s[++count] == ' ' || s[count] == '\t' || s[count] == '\n')
		size--;
	if (size <= 0)
		size = 0;
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	s = s + count;
	count = -1;
	while (++count < (int)size)
		str[count] = *s++;
	str[count] = '\0';
	return (str);
}
