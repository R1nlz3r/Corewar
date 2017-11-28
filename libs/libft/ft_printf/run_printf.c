/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 12:27:12 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:23:17 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		do_length(t_printf_data **data)
{
	int			tmp;

	tmp = -2;
	if (((*data)->str[0] >= '0' && (*data)->str[0] <= '9')
		|| (*data)->str[0] == '-' || (*data)->str[0] == '+')
	{
		tmp = (*data)->functions[0](data);
		return (tmp);
	}
	if ((*data)->str[0] == 'l' || (*data)->str[0] == 'h'
		|| (*data)->str[0] == 'j' || (*data)->str[0] == 'z')
		tmp = (*data)->functions[1](data);
	return (tmp);
}

int				do_flags(t_printf_data **data)
{
	int			count;
	int			tmp;

	count = 1;
	tmp = -2;
	while ((*data)->flags[++count] != '\0')
	{
		if ((*data)->str[0] == ' ')
		{
			(*data)->d_space = '1';
			(*data)->str = (*data)->str + 1;
		}
		if ((tmp = do_length(data)) == -1)
			return (-1);
		if (tmp != -2)
			return (tmp);
		if ((*data)->flags[count] == (*data)->str[0])
		{
			tmp = (*data)->functions[count](data);
			return (tmp);
		}
	}
	return (tmp);
}

void			reinit_data(t_printf_data **data)
{
	(*data)->precision = -1;
	(*data)->hash = 0;
	(*data)->zero[0] = 0;
	(*data)->zero[1] = 0;
	(*data)->zero[2] = 0;
	(*data)->plus = '\0';
	(*data)->d_space = '\0';
	(*data)->prec_exist = '\0';
	(*data)->length = 0;
}

int				run_printf(t_printf_data **data)
{
	int			count;
	int			tmp;

	count = 0;
	while ((*data)->str[count] != '\0')
	{
		count = 0;
		while ((*data)->str[count] != '\0' && (*data)->str[count] != '%')
			++count;
		if ((tmp = ft_print_from_to((*data)->str, 0, (count - 1))) == -1)
			return (-1);
		(*data)->len += tmp;
		if ((*data)->str[count] == '%')
		{
			(*data)->str = (*data)->str + (count + 1);
			if ((tmp = do_flags(data)) == -1)
				return (-1);
			if (tmp == -2)
				tmp = 0;
			(*data)->len += tmp;
			reinit_data(data);
			count = 0;
		}
	}
	return (0);
}
