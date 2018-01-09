/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:23:58 by cfrouin           #+#    #+#             */
/*   Updated: 2018/01/09 13:17:42 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// TODO
// 
// static t_process		*create_process(t_data *data, t_champion *player, int i)
// {
// 	t_process	*process;
//
// 	if ((process = malloc(sizeof(t_process))) == NULL)
// 		return (NULL);
// 	if (player == NULL)
// 	{
// 		free(process);
// 		return (NULL);
// 	}
// 	process->id = i;
// 	process->player = player->number;
// 	process->pos = (MEM_SIZE / data->nb_champion) * i;
// 	process->carry = 0;
// 	process->timeleft = 0;
// 	process->lastlive = 0;
// 	process->prev = NULL;
// 	process->next = NULL;
// 	return (process);
// }
//
// static void		add_process(t_champion *player, t_process *process)
// {
// 	t_process	*tmp;
//
// 	tmp = player->processes;
// 	if (tmp == NULL)
// 	{
// 		player->processes = process;
// 		return ;
// 	}
// 	while (tmp->next != NULL)
// 		tmp = tmp->next;
// 	tmp->next = process;
// 	process->prev = tmp;
// }
//
// int				init_processes(t_data *data)
// {
// 	int			i;
// 	t_process	*process;
// 	t_champion	*player;
//
// 	i = 0;
// 	while (i < data->nb_champion)
// 	{
// 		player = data->champions;
// 		while (player && player->lo != i)
// 			player = player->next;
// 		if ((process = create_process(data, player,  i)) == NULL)
// 			return (-1);
// 		add_process(player, process);
// 		i++;
// 	}
// 	return (1);
// }
