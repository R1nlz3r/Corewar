/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:50 by cyrillef          #+#    #+#             */
/*   Updated: 2017/12/13 18:43:28 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				main(int ac, char **av)
{
	t_data		*data;

	if ((data = init_data(ac, av)) == NULL)
		corewar_error(data, "Couldn't initialize data\n");
	if (read_champions(data) == -1)
		corewar_error(data, "Couldn't initialize champions\n");
	if (init_map(data) == -1)
		corewar_error(data, "Couldn't initialize map\n");
	if (init_processes(data) == -1)
		corewar_error(data, "Couldn't initialize processes\n");
	return (0);
}
