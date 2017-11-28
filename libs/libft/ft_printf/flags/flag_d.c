/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:25:29 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:59 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		flag_d_next(t_printf_data **data, int len, long long d
					, int size)
{
	if ((*data)->d_space == '1' && (*data)->plus == '\0')
	{
		len += (int)write(1, " ", 1);
		++size;
	}
	len = do_flag_zero(data, 0, size, len);
	if ((*data)->precision == 0 && d == 0)
		return (len);
	if ((*data)->plus == '-' && (*data)->zero[1] == 0 && (*data)->precision > 0)
		len += (int)write(1, "-", 1);
	len += precision_long(data, d);
	ft_putnbr_longlong(d);
	if ((*data)->precision > ft_longlonglen(d))
		size = (*data)->precision;
	else
		size = ft_longlonglen(d);
	len = do_flag_zero(data, 1, size, len);
	if (d < 0)
		len += ft_longlonglen_unsigned((unsigned long long)(d * -1));
	else
		len += ft_longlonglen(d);
	return (len);
}

int				flag_d(t_printf_data **data)
{
	long long	d;
	int			len;
	int			size;

	if ((*data)->length == 0)
		d = (long long)va_arg((*data)->ap, int);
	else
		d = (long long)return_length(data);
	(*data)->str = (*data)->str + 1;
	len = 0;
	if (d < 0)
	{
		d = d * -1;
		(*data)->plus = '-';
	}
	size = ft_longlonglen(d);
	if (((*data)->precision - size) > 0)
		size += (*data)->precision - size;
	if ((*data)->precision == 0 && d == 0)
		--size;
	return (flag_d_next(data, len, d, size));
}
