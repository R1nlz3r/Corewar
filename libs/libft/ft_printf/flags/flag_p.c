/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:26:06 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:31 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					flag_p(t_printf_data **data)
{
	unsigned long	p;
	int				len;
	int				size;
	char			*hexa;

	(*data)->plus = '\0';
	p = (unsigned long)va_arg((*data)->ap, void *);
	(*data)->str = (*data)->str + 1;
	if ((hexa = ft_longlong_to_hexa(p, "abcdef")) == NULL)
		return (-1);
	size = (int)ft_strlen(hexa);
	len = 0;
	if ((*data)->zero[0] == 2 && (*data)->zero[2] == 0)
		len += ft_putstr("0x");
	len = do_flag_zero(data, 0, size + 2, len);
	if ((*data)->zero[0] != 2)
		len += ft_putstr("0x");
	len += precision_char(data, hexa);
	if ((*data)->precision != 0)
		len += ft_putstr(hexa);
	len = do_flag_zero(data, 1, size + 2, len);
	free(hexa);
	return (len);
}
