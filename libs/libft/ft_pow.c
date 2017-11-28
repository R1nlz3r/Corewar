/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:39:09 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:40:31 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double			ft_pow(double x, double y)
{
	double		res;

	if (y == 0.00)
		return (1);
	if (y < 0)
		return (1 / (ft_pow(x, (y * -1))));
	if (y == 1.00)
		return (x);
	res = x;
	while (--y > 0)
	{
		res = res * x;
	}
	return (res);
}
