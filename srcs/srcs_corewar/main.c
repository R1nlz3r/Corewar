/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:50 by cyrillef          #+#    #+#             */
/*   Updated: 2017/12/06 17:32:46 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int ac, char **av)
{
	t_data		*data;

	if ((data = init_data(ac, av)) == NULL)
	{
		corewar_error("Couldn't initialize data\n");
		return (-1);
	}
	if (read_champions(data) == -1)
	{
		corewar_error("Couldn't initialize data\n");
		return (-1);
	}
	if (init_map(data) == -1)
	{
		corewar_error("Couldn't initialize map\n");
		return (-1);
	}

	t_node		*node = data->map;
	do
	{
		printf("% 2s|", node->content);
		node = node->next;
	} while (node->id != 0);

	// t_champion	*tmp;
    //
	// tmp = data->champions;
	// while (tmp)
	// {
	// 	ft_printf("%d\n%s\n", tmp->size, tmp->code);
	// 	tmp = tmp->next;
	// }
	return (0);
}
