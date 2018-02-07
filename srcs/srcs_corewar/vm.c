/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:40:32 by cfrouin           #+#    #+#             */
/*   Updated: 2018/02/07 11:42:48 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				vm_start(t_data *data)
{
	while (1)
	{
		// c = get_key();
		// if (c == 27)
		// {
		// 	ft_putstr("\033[H\033[J\e[?25h");
		// 	exit(1);
		// }
		// else if (c == 32 && data->pause)
		// 	data->pause = 0;
		// else if (c == 32)
		// 	data->pause = 1;
		// if (data->pause != 1)
		// {
			usleep(100000);
			prepare_next_op(data);
			do_next_op(data);
			data->cycle++;
			data->cyclec++;
			if (data->dump != 0)
			{
				if (data->cycle % data->dump == 0)
					dump(data);
			}
			else
				display_map(data);
		// }
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
