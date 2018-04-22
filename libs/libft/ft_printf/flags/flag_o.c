/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:25:59 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:35 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int					flag_o_next(t_printf_data **data, int size
								, char *octal, unsigned long long o)
{
	int						len;

	len = do_flag_zero(data, 0, size, 0);
	len += precision_char(data, octal);
	if ((*data)->hash == 1 && octal[0] != '0'
		&& (*data)->precision <= (int)ft_strlen(octal))
		len += write(1, "0", 1);
	if ((*data)->precision != -1 && o == 0)
	{
		if ((*data)->hash == 1)
			len += write(1, "0", 1);
		free(octal);
		return (len);
	}
	len += ft_putstr(octal);
	len = do_flag_zero(data, 1, size, len);
	free(octal);
	return (len);
}

int							flag_o(t_printf_data **data)
{
	unsigned long long		o;
	char					*octal;
	int						size;

	o = take_unsignedlonglong(data);
	(*data)->str = (*data)->str + 1;
	if ((octal = ft_longlong_to_octal(o)) == NULL)
		return (-1);
	if ((int)ft_strlen(octal) > (*data)->precision)
		size = (int)ft_strlen(octal);
	else
		size = (*data)->precision;
	(*data)->plus = '\0';
	if ((*data)->precision != -1 && o == 0)
		--size;
	if ((*data)->hash == 1 && octal[0] != '0'
		&& (*data)->precision <= (int)ft_strlen(octal))
		++size;
	return (flag_o_next(data, size, octal, o));
}
