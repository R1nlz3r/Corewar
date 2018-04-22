/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlonglen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 20:59:33 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/22 20:59:41 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_longlonglen(long long nbr)
{
	int		count;

	count = 1;
	if (nbr < 0)
	{
		++count;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		++count;
		nbr /= 10;
	}
	return (count);
}
