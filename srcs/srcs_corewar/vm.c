/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:40:32 by cfrouin           #+#    #+#             */
/*   Updated: 2018/01/31 18:43:35 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				vm_start(t_data *data)
{
	// while (1)
	// {
		ft_printf("nothing worked?\n");
		prepare_next_op(data);
		ft_printf("prepare_next_op worked?\n");
		do_next_op(data);
		ft_printf("do_next_op worked?\n");
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
		data->cycle++;
		data->cyclec++;
	// }
	return (1);
}
