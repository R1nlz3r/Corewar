/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 15:25:19 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:27:09 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							flag_b(t_printf_data **data)
{
	unsigned long long		b;
	int						len;
	char					*binaire;

	b = take_unsignedlonglong(data);
	(*data)->str = (*data)->str + 1;
	if ((binaire = ft_longlong_to_binaire(b)) == NULL)
		return (-1);
	len = 0;
	len += ft_putstr(binaire);
	free(binaire);
	return (len);
}
