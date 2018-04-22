/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:37:01 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/12 17:04:44 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	count;

	count = 0;
	if (s != NULL && (*f) != NULL)
		while (s[count] != '\0')
		{
			(*f)(count, &s[count]);
			++count;
		}
}
