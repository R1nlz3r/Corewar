/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:03:07 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/17 18:03:28 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int			fill_blank(int len, unsigned char type)
{
	while (len < 3)
	{
		len += 1;
		type = type << 2;
	}
	return (type);
}

void				type_param(t_data *data, int line, int word)
{
	unsigned char	type;
	int				count;
	int				len;

	count = -1;
	len = 0;
	type = 0;
	while (data->tab[line][word][++count] != '\0')
	{
		if (count == 0 || data->tab[line][word][count - 1] == SEPARATOR_CHAR)
		{
			if (data->tab[line][word][count] == 'r')
				type += 0b01;
			else if (data->tab[line][word][count] == DIRECT_CHAR)
				type += 0b10;
			else
				type += 0b11;
			type = type << 2;
			++len;
		}
	}
	type = fill_blank(len, type);
	write(data->fd, &type, 1);
}
