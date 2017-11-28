/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlong_to_hexa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:49:40 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/29 20:56:41 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*decal(char *hexa, int len)
{
	int			count;

	while (len >= 0)
	{
		hexa[len] = 'z';
		--len;
	}
	while (hexa[0] == 'z')
	{
		count = -1;
		while (hexa[++count + 1] != '\0')
			hexa[count] = hexa[count + 1];
		hexa[count] = '\0';
	}
	return (hexa);
}

char			*ft_longlong_to_hexa(unsigned long long nbr, char *value)
{
	char		*hexa;
	int			len;

	len = ft_longlonglen_unsigned(nbr) + 1;
	if ((hexa = malloc((size_t)len * sizeof(char))) == NULL)
		return (NULL);
	hexa[len - 1] = '\0';
	len = len - 2;
	if (nbr == 0)
		hexa[len--] = '0';
	else
		while (nbr > 0)
		{
			if ((nbr % 16) <= 9)
				hexa[len] = (nbr % 16) + 48;
			else
				hexa[len] = value[(nbr % 16) - 10];
			nbr /= 16;
			--len;
		}
	return (decal(hexa, len));
}
