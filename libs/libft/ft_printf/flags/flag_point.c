/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:26:14 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:12 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					flag_point(t_printf_data **data)
{
	size_t			count;
	char			*tmp;

	(*data)->prec_exist = '1';
	(*data)->str = (*data)->str + 1;
	count = 0;
	if ((*data)->str[0] == '-')
		++count;
	while ((*data)->str[count] >= '0' && (*data)->str[count] <= '9')
		++count;
	if (((*data)->str[0] == '-' && count == 1) || count == 0)
		(*data)->precision = 0;
	else
	{
		if ((tmp = malloc((count + 1) * sizeof(char))) == NULL)
			return (-1);
		tmp = ft_strncpy(tmp, (*data)->str, count);
		tmp[count] = '\0';
		(*data)->precision = ft_atoi(tmp);
		if ((*data)->precision < 0)
			(*data)->precision = 0;
		free(tmp);
	}
	(*data)->str = (*data)->str + count;
	return (do_flags(data));
}
