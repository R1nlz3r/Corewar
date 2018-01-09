/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 18:50:08 by cfrouin           #+#    #+#             */
/*   Updated: 2017/12/15 17:56:49 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					live(t_data *data, t_process *process, unsigned int arg)
{
	t_champion		*champion;

	champion = data->champions;
	while (champion && champion->number != arg)
		champion = champion->next;
	if (champion == NULL)
		corewar_error(data, "TODO : live champion does not exist\n");
	ft_printf("A process shows that player %d (%s) is alive\n",
				process->player, champion->name);
	process->lastlive = data->cycle;
	data->lastlive = process->player;
	return (1);
}
