/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:50 by cyrillef          #+#    #+#             */
/*   Updated: 2018/04/21 11:45:49 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char			g_hex_tab[] =
{
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'a', 'b', 'c', 'd', 'e', 'f'
};

void			win(t_data *data)
{
	t_champion	*player;

	if (data->graph)
		ft_putstr("\033[H");
	player = data->champions;
	while (player->alive == 0 && player->next != NULL)
		player = player->next;
	ft_printf("Player %d (%s) won!\n", player->number, player->name);
}

int				main(int ac, char **av)
{
	t_data		*data;

	data = NULL;
	if ((data = init_data(ac, av)) == NULL)
		corewar_error(data, "Couldn't initialize data\n");
	sort_champions(data);
	if (data->nb_player <= 0)
	{
		free_data(data);
		usage();
	}
	if (read_champions(data) == -1)
		corewar_error(data, "Couldn't initialize champions\n");
	if (init_map(data) == -1)
		corewar_error(data, "Couldn't initialize map\n");
	if (vm_start(data) == -1)
		corewar_error(data, "Error during vm execution\n");
	win(data);
	free_data(data);
	ft_putstr("\e[?25h");
	return (0);
}
