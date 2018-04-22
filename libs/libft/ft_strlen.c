/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:22:35 by kda-silv          #+#    #+#             */
/*   Updated: 2017/01/05 15:31:08 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(char *str)
{
	size_t		count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
		++count;
	return (count);
}
