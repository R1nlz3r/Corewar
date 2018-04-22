/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:05:31 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:31:50 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size_nbr(int n)
{
	size_t		count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		++count;
	}
	while (n != 0)
	{
		++count;
		n = n / 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		len;

	len = ft_size_nbr(n);
	if ((str = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	if (n >= 0)
		n = n * -1;
	else
		str[0] = '-';
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n < 0)
	{
		--len;
		str[len] = ((n % 10) * -1) + '0';
		n = n / 10;
	}
	return (str);
}
