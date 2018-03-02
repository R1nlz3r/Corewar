/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_cycles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 15:16:11 by dwald             #+#    #+#             */
/*   Updated: 2018/03/01 15:20:36 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

		printf(CYAN"Cycle : %d\n"RESET, data->cycle);
int		cycle_check(t_data *data)
{
		vm_dump_if_necessary(vm);
	vm->cycle_nbr += 1;
	if (vm_verbose_cycles(vm))
		ft_printf("It is now cycle %d\n", vm->cycle_nbr);
	vm->cycles_since_last_check += 1;
	vm_advance_processes_one_cycle(vm);
	if (vm->cycles_since_last_check >= vm->cycle_to_die)
	{
		vm_check_lives_and_kill(vm);
		vm->cycles_since_last_check = 0;
	}
	return (vm_check_alive_processes(vm));
		









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
