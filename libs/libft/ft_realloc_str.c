/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:20:21 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/15 17:05:02 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc_str(char *ptr, size_t size)
{
	char	*str;

	if (ptr == NULL)
		return (malloc(size));
	if ((str = ft_strnew((ft_strlen(ptr) + size + 1) * sizeof(char))) == NULL)
		return (NULL);
	str = ft_strncpy(str, ptr, ft_strlen(ptr));
	free(ptr);
	return (str);
}
