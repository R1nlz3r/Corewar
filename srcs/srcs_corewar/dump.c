/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:23:49 by cyrillef          #+#    #+#             */
/*   Updated: 2018/02/28 15:43:03 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				dump(t_data *data)
{
	int				i;
	t_node			*node;

	i = 0;
	node = data->map;
	ft_printf("%d ipc\n", data->champions->ipc);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			if (i != 0)
			{
				ft_putchar('\n');
			}
			ft_printf("0x%04x : ", i);
		}
		ft_printf("%s ", node->content);
		i++;
		node = node->next;
	}
	exit(1);
}
