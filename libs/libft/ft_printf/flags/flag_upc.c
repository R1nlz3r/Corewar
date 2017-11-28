/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_upc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:26:59 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:24:17 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_upc(t_printf_data **data)
{
	wchar_t				c;
	int					len;

	c = (wchar_t)va_arg((*data)->ap, wchar_t);
	(*data)->str = (*data)->str + 1;
	(*data)->plus = '\0';
	len = do_flag_zero(data, 0, 1, 0);
	len += ft_wputchar(c);
	len = do_flag_zero(data, 1, 1, len);
	return (len);
}
