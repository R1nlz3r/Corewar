/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:26:49 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:02 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							flag_u(t_printf_data **data)
{
	unsigned long long		u;
	int						len;
	int						size;

	u = take_unsignedlonglong(data);
	(*data)->str = (*data)->str + 1;
	(*data)->plus = '\0';
	if (ft_longlonglen_unsigned(u) > (*data)->precision)
		size = ft_longlonglen_unsigned(u);
	else
		size = (*data)->precision;
	if ((*data)->precision != -1 && u == 0)
		--size;
	len = do_flag_zero(data, 0, size, 0);
	len += precision_unsigned_long(data, u);
	if ((*data)->precision != -1 && u == 0)
		return (len);
	ft_putnbr_longlong_unsigned(u);
	len = do_flag_zero(data, 1, ft_longlonglen_unsigned(u), len);
	return (ft_longlonglen_unsigned(u) + len);
}
