/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 12:29:44 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:23:35 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long			take_unsignedlonglong(t_printf_data **data)
{
	int						tmp;
	unsigned long long		n;

	if ((*data)->length == 0)
	{
		tmp = va_arg((*data)->ap, int);
		if (tmp < 0)
			n = (unsigned long long)(UINT_MAX + (unsigned int)tmp + 1);
		else
			n = (unsigned long long)tmp;
	}
	else
		n = (unsigned long long)return_length_unsigned(data);
	return (n);
}

t_printf_data				*init_functions(t_printf_data *data)
{
	data->functions[0] = &flag_zero;
	data->functions[1] = &flag_length;
	data->functions[2] = &flag_c;
	data->functions[3] = &flag_upc;
	data->functions[4] = &flag_s;
	data->functions[5] = &flag_ups;
	data->functions[6] = &flag_d;
	data->functions[7] = &flag_i;
	data->functions[8] = &flag_long;
	data->functions[9] = &flag_ulong;
	data->functions[10] = &flag_u;
	data->functions[11] = &flag_o;
	data->functions[12] = &flag_x;
	data->functions[13] = &flag_upx;
	data->functions[14] = &flag_point;
	data->functions[15] = &flag_hashtag;
	data->functions[16] = &flag_p;
	data->functions[17] = &flag_percent;
	data->functions[18] = &flag_upd;
	data->functions[19] = &flag_upu;
	data->functions[20] = &flag_upo;
	data->functions[21] = &flag_b;
	return (data);
}
