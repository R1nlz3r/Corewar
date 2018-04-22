/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 20:03:19 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 20:03:20 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_unsigned(unsigned int nb)
{
	if (nb >= 10)
		if (ft_putnbr_unsigned(nb / 10) == -1)
			return (-1);
	return (ft_putchar(nb % 10 + '0'));
}
