/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:23:49 by cyrillef          #+#    #+#             */
/*   Updated: 2018/02/07 11:38:00 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				dump(t_data *data)
{
	int				i;
	t_node			*node;

	i = 0;
	node = data->map;
	while (node->id != 0 || i == 0)
	{
		if (i % 32 == 0)
		{
			if (i != 0)
				ft_putchar('\n');
			ft_printf("0x%04x : ", i * 2);
		}
		ft_printf("0x%02x ", node->contentn);
		i++;
		node = node->next;
	}
	exit(1);
}
