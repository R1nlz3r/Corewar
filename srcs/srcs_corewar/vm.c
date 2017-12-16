/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:40:32 by cfrouin           #+#    #+#             */
/*   Updated: 2017/12/15 18:59:33 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				vm_start(t_data *data)
{
	t_champion	*champion;

	while (1)
	{
		champion = data->champions;
		if (champion == NULL || data->nb_champion == 1)
			break ;
		// while (champion->next != NULL)
		// 	champion = champion->next;
		if (data->cyclec == data->cycletodie)
		{
			ft_printf("-- %d champions are alive\n", data->nb_champion);
			vm_check_live(data);
			ft_printf("-- %d champions are alive\n", data->nb_champion);
			data->cyclec = 0;
			data->cycletodie -= CYCLE_DELTA;
		}
		data->cycle++;
		data->cyclec++;
	}
	return (1);
}
