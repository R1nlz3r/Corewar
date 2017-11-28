/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:26:45 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:06 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		flag_s_precision(t_printf_data **data, int len, char *s)
{
	int			count;
	int			size;

	count = 0;
	size = (int)ft_strlen(s);
	if (s == NULL)
		size = 6;
	while (count < (*data)->precision && count < size)
		++count;
	len = do_flag_zero(data, 0, count, 0);
	if (s == NULL)
		len += (int)write(1, "(null)", (size_t)count);
	else
		len += (int)write(1, s, (size_t)count);
	len = do_flag_zero(data, 1, count, len);
	return (len);
}

int				flag_s(t_printf_data **data)
{
	char		*s;
	int			len;

	if ((*data)->length == L)
		return (flag_ups(data));
	s = (char *)va_arg((*data)->ap, char *);
	(*data)->str = (*data)->str + 1;
	len = 0;
	if ((*data)->precision == -1)
	{
		(*data)->plus = '\0';
		len = do_flag_zero(data, 0, (int)ft_strlen(s), 0);
		if (s == NULL)
			len += ft_putstr("(null)");
		else
			len += ft_putstr(s);
		len = do_flag_zero(data, 1, (int)ft_strlen(s), len);
	}
	else
		return (flag_s_precision(data, len, s));
	return (len);
}
