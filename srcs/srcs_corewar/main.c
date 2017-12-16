/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:50 by cyrillef          #+#    #+#             */
/*   Updated: 2017/12/16 15:42:12 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char				g_hex_tab[] =
{
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

void			win(t_data *data)
{
	t_champion	*player;

	player = data->champions;
	if (player == NULL)
		ft_printf("Match ended in a draw\n");
	else
		ft_printf("Player %d (%s) won!\n", player->number, player->name);
}

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
	ft_printf("%d player entered the game.\n", data->nb_champion);
	if (vm_start(data) == -1)
		corewar_error(data, "Error during vm execution\n");
	win(data);
	free_data(data);
	return (0);
}
