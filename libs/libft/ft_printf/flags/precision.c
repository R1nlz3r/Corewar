/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 20:04:17 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:27:51 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			precision_long(t_printf_data **data, long long nbr)
{
	int		count;
	int		len;

	len = 0;
	if ((*data)->precision >= 0)
	{
		count = ft_longlonglen(nbr);
		count = (*data)->precision - count;
		if (count > 0)
			len = count;
		if (count > 0)
			while (count-- > 0)
				write(1, "0", 1);
	}
	return (len);
}

int			precision_unsigned_long(t_printf_data **data
				, unsigned long long nbr)
{
	int		count;
	int		len;

	len = 0;
	if ((*data)->precision >= 0)
	{
		count = ft_longlonglen_unsigned(nbr);
		count = (*data)->precision - count;
		if (count > 0)
			len = count;
		if (count > 0)
			while (count-- > 0)
				write(1, "0", 1);
	}
	return (len);
}

int			precision_char(t_printf_data **data, char *str)
{
	int		count;
	int		len;

	len = 0;
	if ((*data)->precision >= 0)
	{
		count = (int)ft_strlen(str);
		count = (*data)->precision - count;
		if (count > 0)
			len = (int)count;
		if (count > 0)
			while (count-- > 0)
				write(1, "0", 1);
	}
	return (len);
}
