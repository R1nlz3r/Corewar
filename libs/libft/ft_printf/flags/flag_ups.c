/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_ups.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:27:22 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:27:23 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		flag_ups_precision(t_printf_data **data, int len, wchar_t *s)
{
	int			count;
	int			size;

	count = 0;
	size = (int)ft_wstrlen(s);
	if (s == NULL)
		size = 6;
	while (count < (*data)->precision && count < size)
		++count;
	len = do_flag_zero(data, 0, count, 0);
	if (s == NULL)
		return (len + ft_putstr("(null)"));
	else
	{
		if ((len = write_wchar(s, len, count, data)) == -1)
			return (-1);
	}
	len = do_flag_zero(data, 1, count, len);
	return (len);
}

int				flag_ups(t_printf_data **data)
{
	wchar_t		*s;
	int			len;

	s = (wchar_t *)va_arg((*data)->ap, wchar_t *);
	(*data)->str = (*data)->str + 1;
	len = 0;
	if ((*data)->precision == -1)
	{
		(*data)->plus = '\0';
		len = do_flag_zero(data, 0, (int)ft_wstrlen(s), 0);
		if (s == NULL)
			return (len + ft_putstr("(null)"));
		if ((len = write_wchar(s, len, -200, data)) == -1)
			return (-1);
		len = do_flag_zero(data, 1, (int)ft_wstrlen(s), len);
	}
	else
		return (flag_ups_precision(data, len, s));
	return (len);
}
