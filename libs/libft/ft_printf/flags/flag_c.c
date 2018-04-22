/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:25:24 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:27:04 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				flag_c(t_printf_data **data)
{
	char		c;
	int			len;

	if ((*data)->length == L)
		return (flag_upc(data));
	c = (char)va_arg((*data)->ap, int);
	(*data)->str = (*data)->str + 1;
	(*data)->plus = '\0';
	len = do_flag_zero(data, 0, 1, 0);
	len += write(1, &c, 1);
	len = do_flag_zero(data, 1, 1, len);
	return (len);
}
