/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:11:27 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/15 14:54:42 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen_char(char *str, char c)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != c && str[count] != '\0')
		++count;
	return (count);
}
