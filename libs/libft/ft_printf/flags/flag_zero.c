/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 20:59:58 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:27:46 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			kick_precision(t_printf_data **data)
{
	int				count;
	char			*str;

	count = 0;
	while ((*data)->str[count] >= '0' && (*data)->str[count] <= '9')
		++count;
	if ((str = ft_strnew((size_t)count)) == NULL)
		return (-1);
	if ((str = ft_strncpy(str, (*data)->str, (size_t)count)) == NULL)
		return (-1);
	if ((*data)->zero[1] < ft_atoi(str))
		(*data)->zero[1] = ft_atoi(str);
	free(str);
	(*data)->str = (*data)->str + count;
	return (0);
}

static int			test_good_flag(t_printf_data **data)
{
	int				count;
	int				count2;
	int				flag;

	count = 0;
	while ((*data)->str[count] == '+' || (*data)->str[count] == '-'
		|| (*data)->str[count] == '.' || (*data)->str[count] == ' '
		|| ((*data)->str[count] >= '0' && (*data)->str[count] <= '9'))
	{
		if ((*data)->str[count] == '.' && ((*data)->str[count + 1] >= '0'
			&& (*data)->str[count + 1] <= '9'))
			return (-3);
		++count;
	}
	count2 = 0;
	flag = -2;
	while ((*data)->flags[count2] != '\0')
	{
		if ((*data)->flags[count2] == (*data)->str[count])
			++flag;
		++count2;
	}
	return (flag);
}

static int			flag_zero_next(t_printf_data **data)
{
	int				tmp;

	if ((*data)->str[0] == '+')
	{
		(*data)->plus = '+';
		(*data)->str = (*data)->str + 1;
	}
	if ((tmp = do_flags(data)) == -2)
	{
		do_flag_zero(data, 0, 1, 0);
		write(1, (*data)->str, 1);
		(*data)->str = (*data)->str + 1;
		do_flag_zero(data, 1, 1, 0);
		tmp = (*data)->zero[1];
	}
	return (tmp);
}

int					flag_zero(t_printf_data **data)
{
	(*data)->zero[0] = 1;
	while ((*data)->str[0] == '0' || (*data)->str[0] == '-'
		|| (*data)->str[0] == '+')
	{
		if ((*data)->str[0] == '+')
			(*data)->plus = '+';
		if ((*data)->str[0] == '0')
			(*data)->zero[0] = 2;
		if ((*data)->str[0] == '-')
			(*data)->zero[2] = 1;
		(*data)->str = (*data)->str + 1;
	}
	if (test_good_flag(data) == -3 || (*data)->precision > 0
		|| (*data)->prec_exist == '1')
		(*data)->zero[0] = 1;
	if (kick_precision(data) == -1)
		return (-1);
	return (flag_zero_next(data));
}
