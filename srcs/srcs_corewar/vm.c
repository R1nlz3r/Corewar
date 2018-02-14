/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:40:32 by cfrouin           #+#    #+#             */
/*   Updated: 2018/02/14 13:14:25 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				vm_start(t_data *data)
{
	int		i;

	while (1)
	{
		key_hub(data);
		if (data->pause != 1)
		{
			prepare_next_op(data);
			do_next_op(data);
			data->cycle++;
			data->cyclec++;
			if (data->dump != 0)
			{
				if (data->cycle % data->dump == 0)
					dump(data);
			}
			else if (data->speed > 0 && !(data->cycle % data->speed))
				display_map(data);
			else if (data->speed < 0)
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
		else if (data->pause)
			display_map(data);
		// printf("argsType[0] : %d\nargsType[1] : %d\nargsType[2] : %d\n",
			// data->champions->argsType[0], data->champions->argsType[1], data->champions->argsType[2]);
		// printf("args[0] : %d\nargs[1] : %d\nargs[2] : %d\n",
			// data->champions->args[0], data->champions->args[1], data->champions->args[2]);
		// data->champion
		// if (champion == NULL || data->nb_champion == 1)
		// 	break ;
		// if (data->cyclec == data->cycletodie)
		// {
		// 	ft_printf("-- %d champions are alive\n", data->nb_champion);
		// 	vm_check_live(data);
		// 	ft_printf("-- %d champions are alive\n", data->nb_champion);
		// 	data->cyclec = 0;
		// 	data->cycletodie -= CYCLE_DELTA;
		// }
	}
	return (1);
}
