/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:40:32 by cfrouin           #+#    #+#             */
/*   Updated: 2018/04/05 15:48:04 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				vm_start(t_data *data)
{
	int		i;

	if (data->graph == 1)
		display_map(data);
	while (1)
	{
		if (data->graph == 1)
			key_hub(data);
		if (data->pause != 1)
		{
			// usleep(25000);
			dump_state(NULL, data, data->champions);
			prepare_next_op(data);
			do_next_op(data);
			if (data->dump != -1)
			{
				if (data->dump == 0 || data->cycle % data->dump == 0)
					dump(data);
			}
			data->cycle++;
			data->cyclec++;
			if (data->graph == 1
				&& data->speed > 0 && !(data->cycle % data->speed))
				display_map(data);
			else if (data->graph == 1 && data->speed < 0)
			{
				i = data->speed;
				while (i++)
				{
					if (i < data->speed && data->speed < 0)
						i = data->speed;
					else if (data->speed > 0)
						break ;
					display_map(data);
					key_hub(data);
				}
			}
		}
		// COMMENT FROM HERE TO DISABLE END OF GAME
		check_live(data);
		if (data->nb_champion <= 1)
		{
			ft_printf(YELLOW"-------\nEND OF GAME\n-------\n"RESET);
			return (1);
		}
	}
	return (1);
}
