/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_percent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:26:10 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:26:26 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						flag_percent(t_printf_data **data)
{
	int					len;

	(*data)->str = (*data)->str + 1;
	len = do_flag_zero(data, 0, 1, 0);
	len += (int)write(1, "%", 1);
	if ((*data)->zero[1] != 0)
		len = do_flag_zero(data, 1, 1, len);
	return (len);
}
