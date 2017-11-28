/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_bin_to_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:54:36 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/06 17:30:50 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_convert_bin_to_decimal(char *bin)
{
	int		count;
	int		count2;
	double	tmp;
	int		decimal;

	decimal = 0;
	count = (int)ft_strlen(bin);
	count2 = 0;
	while (--count >= 0)
	{
		tmp = ft_pow((double)2, (double)count);
		decimal += (bin[count2] - '0') * (int)tmp;
		++count2;
	}
	return (decimal);
}
