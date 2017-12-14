/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:23:58 by cfrouin           #+#    #+#             */
/*   Updated: 2017/12/14 15:45:54 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// TODO

t_process		*create_process(t_data *data, int i)
{
	t_process	*process;
	t_champion	*player;

	if ((process = malloc(sizeof(t_process))) == NULL)
		return (NULL);
	player = data->champions;
	while (player && player->lo != i)
		player = player->next;
	if (player == NULL)
	{
		free(process);
		return (NULL);
	}
	process->id = i;
	process->player = player->number;
	process->pos = (MEM_SIZE / data->nb_champion) * i;
	process->carry = 0;
	process->timeleft = 0;
	process->prev = NULL;
	process->next = NULL;
	return (process);
}

int				init_processes(t_data *data)
{
	int			i;
	t_process	*process;
	t_process	*tmp;

	i = 0;
	tmp = data->processes;
	while (i < data->nb_champion)
	{
		if ((process = create_process(data, i)) == NULL)
			return (-1);
		if (tmp == NULL)
			data->processes = process;
		else
		{
			tmp->next = process;
			process->prev = tmp;
		}
		tmp = process;
		i++;
	}
	return (1);
}
