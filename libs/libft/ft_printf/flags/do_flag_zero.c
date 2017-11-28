/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flag_zero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:25:12 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:27:14 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			write_flag_zero(t_printf_data **data, int size)
{
	int				count;
	int				len;

	count = -1;
	len = 0;
	if ((*data)->zero[0] == 2 && (*data)->zero[2] == 0)
	{
		if ((*data)->plus != '\0')
			len += write(1, &(*data)->plus, 1);
		while (++count < ((*data)->zero[1] - size))
			len += write(1, "0", 1);
	}
	if ((*data)->zero[0] == 1 && (*data)->zero[2] == 0)
	{
		while (++count < ((*data)->zero[1] - size))
			len += write(1, " ", 1);
		if ((*data)->plus != '\0')
			len += write(1, &(*data)->plus, 1);
	}
	return (len);
}

static int			do_flag_zero_next(t_printf_data **data, int len
						, int flag, int size)
{
	int				count;

	count = -1;
	if (flag == 0)
	{
		len += write_flag_zero(data, size);
	}
	else
	{
		if ((*data)->zero[2] == 1)
			while (++count < ((*data)->zero[1] - size))
				len += write(1, " ", 1);
	}
	return (len);
}

int					do_flag_zero(t_printf_data **data
						, int flag, int size, int len)
{
	if (((*data)->len + (*data)->zero[1]) < ((*data)->len + len + size)
		&& (*data)->precision != -1 && flag == 0)
	{
		if ((*data)->plus != '\0')
			len += write(1, &(*data)->plus, 1);
		(*data)->plus = 0;
		return (len);
	}
	if ((*data)->plus != '\0')
	{
		++size;
		if ((*data)->zero[2] == 1 && flag == 0)
			len += write(1, &((*data)->plus), 1);
		if ((*data)->zero[0] == 0 && (*data)->zero[1] == 0
			&& (*data)->zero[2] == 0 && (*data)->plus != '\0' && flag == 0)
			len += write(1, &((*data)->plus), 1);
	}
	return (do_flag_zero_next(data, len, flag, size));
}
