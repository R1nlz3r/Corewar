/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 11:23:49 by cyrillef          #+#    #+#             */
/*   Updated: 2018/02/26 17:30:43 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				dump(t_data *data)
{
	int				i;
	t_node			*node;

	i = 0;
	node = data->map;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
		{
			if (i != 0)
				ft_putchar('\n');
			ft_printf("0x%04x : ", i);
		}
		if (node->contentn < 0)
			ft_printf(RED"%s "RESET, node->content);
		else
			ft_printf("%s ", node->content);
		i++;
		node = node->next;
	}
	exit(1);
}
