/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlong_to_binaire.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 20:59:22 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/22 20:59:24 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*decal(char *binaire)
{
	int			count;

	while (binaire[0] == 'a')
	{
		count = -1;
		while (binaire[++count + 1] != '\0')
			binaire[count] = binaire[count + 1];
		binaire[count] = '\0';
	}
	return (binaire);
}

char			*ft_longlong_to_binaire(unsigned long long nbr)
{
	char		*binaire;
	int			len;

	len = 66;
	if ((binaire = malloc((size_t)len * sizeof(char))) == NULL)
		return (NULL);
	binaire[len - 1] = '\0';
	len = len - 2;
	if (nbr == 0)
		binaire[len--] = '0';
	else
		while (nbr > 0)
		{
			binaire[len] = (nbr % 2) + 48;
			nbr /= 2;
			--len;
		}
	while (len >= 0)
	{
		binaire[len] = 'a';
		--len;
	}
	return (decal(binaire));
}
