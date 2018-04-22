/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_longlong_unsigned.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 21:01:04 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/22 21:01:11 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_longlong_unsigned(unsigned long long nb)
{
	if (nb >= 10)
		if (ft_putnbr_longlong_unsigned(nb / 10) == -1)
			return (-1);
	return (ft_putchar(nb % 10 + '0'));
}
