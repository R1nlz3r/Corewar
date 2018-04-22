/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:25:44 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:45 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		return_length_unsigned(t_printf_data **data)
{
	unsigned long long	nbr;

	nbr = 0;
	if ((*data)->length == HH)
		nbr = (unsigned char)va_arg((*data)->ap, int);
	if ((*data)->length == H)
		nbr = (unsigned short)va_arg((*data)->ap, int);
	if ((*data)->length == LL)
		nbr = (unsigned long long)va_arg((*data)->ap, long long);
	if ((*data)->length == L)
		nbr = (unsigned long)va_arg((*data)->ap, long);
	if ((*data)->length == J)
		nbr = (uintmax_t)va_arg((*data)->ap, long long);
	if ((*data)->length == Z)
		nbr = va_arg((*data)->ap, size_t);
	return (nbr);
}

long long				return_length(t_printf_data **data)
{
	long long			nbr;

	nbr = 0;
	if ((*data)->length == HH)
		nbr = (signed char)va_arg((*data)->ap, int);
	if ((*data)->length == H)
		nbr = (short)va_arg((*data)->ap, int);
	if ((*data)->length == LL)
		nbr = va_arg((*data)->ap, long long);
	if ((*data)->length == L)
		nbr = va_arg((*data)->ap, long);
	if ((*data)->length == J)
		nbr = (intmax_t)va_arg((*data)->ap, long long);
	if ((*data)->length == Z)
		nbr = va_arg((*data)->ap, ssize_t);
	return (nbr);
}

static void				flag_length_next(t_printf_data **data, int count)
{
	if ((*data)->str[count] == 'h' || (*data)->str[count] == 'l')
		if (count > 0 && (((*data)->str[count] == 'h'
			&& (*data)->str[count - 1] == 'h') || ((*data)->str[count] == 'l'
			&& (*data)->str[count - 1] == 'l')))
			--count;
	(*data)->str = (*data)->str + count;
	if ((*data)->str[0] == 'h' && (*data)->str[1] == 'h')
		(*data)->length = HH;
	if ((*data)->str[0] == 'h' && (*data)->str[1] != 'h')
		(*data)->length = H;
	if ((*data)->str[0] == 'l' && (*data)->str[1] == 'l')
		(*data)->length = LL;
	if ((*data)->str[0] == 'l' && (*data)->str[1] != 'l')
		(*data)->length = L;
	if ((*data)->str[0] == 'j')
		(*data)->length = J;
	if ((*data)->str[0] == 'z')
		(*data)->length = Z;
	if ((*data)->length == HH || (*data)->length == LL)
		(*data)->str = (*data)->str + 2;
	else
		(*data)->str = (*data)->str + 1;
}

int						flag_length(t_printf_data **data)
{
	int					count;

	count = 0;
	while ((*data)->str[count] == 'h' || (*data)->str[count] == 'l'
		|| (*data)->str[count] == 'j' || (*data)->str[count] == 'z')
		++count;
	--count;
	if (count > 0 && (*data)->str[count] == 'h'
		&& (*data)->str[count - 1] != 'h')
		--count;
	flag_length_next(data, count);
	count = 0;
	while ((*data)->str[count] == 'h' || (*data)->str[count] == 'l'
		|| (*data)->str[count] == 'j' || (*data)->str[count] == 'z')
		++count;
	(*data)->str = (*data)->str + count;
	if ((*data)->str[0] != 'd' && (*data)->str[0] != 'i'
		&& (*data)->str[0] != 'u' && (*data)->str[0] != 'o'
		&& (*data)->str[0] != 'x' && (*data)->str[0] != 'X')
		return (-2);
	return (do_flags(data));
}
