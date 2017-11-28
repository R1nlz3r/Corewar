/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:50 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/28 13:26:36 by cyrillefrouin    ###   ########.fr       */
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

	t_champion	*champion;

	champion = data->champions;
	while (champion) {
		ft_printf("%s - %d\n", champion->filename, champion->number);
		champion = champion->next;
	}
	// free(champion);
	return (0);
}
