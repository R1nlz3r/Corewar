/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlonglen_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 20:59:48 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/22 20:59:50 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_longlonglen_unsigned(unsigned long long nbr)
{
	int		count;

	count = 1;
	while (nbr > 9)
	{
		++count;
		nbr /= 10;
	}
	return (count);
}
