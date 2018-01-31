/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_live.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 16:35:13 by cfrouin           #+#    #+#             */
/*   Updated: 2018/01/04 16:12:43 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

// static void			vm_check_live_kill_champ(t_data *data, t_champion *champion)
// {
// 	if (champion->prev == NULL && champion->next == NULL)
// 		data->champions = NULL;
// 	if (champion->prev)
// 		champion->prev->next = champion->next;
// 	else
// 		data->champions = champion->next;
// 	if (champion->next)
// 		champion->next->prev = champion->prev;
// 	ft_printf("Champion %s died\n", champion->name);
// 	free(champion->filename);
// 	free(champion);
// 	data->nb_champion--;
// }
//
// static void			vm_check_live_kill_proc(t_champion *champion,
// 											t_process *process)
// {
// 	if (process->prev == NULL && process->next == NULL)
// 		champion->processes = NULL;
// 	if (process->prev)
// 		process->prev->next = process->next;
// 	else
// 		champion->processes = process->next;
// 	if (process->next)
// 		process->next->prev = process->prev;
// 	free(process);
// }
//
// void				vm_check_live_champion(t_champion *champion)
// {
// 	t_process		*process;
// 	t_process		*tmp;
//
// 	process = champion->processes;
// 	while (process != NULL)
// 	{
// 		tmp = process;
// 		if (process->lastlive <= 0)
// 			vm_check_live_kill_proc(champion, process);
// 		else
// 		{
// 			champion->live = 0;
// 			process->lastlive = 0;
// 		}
// 		process = tmp->next;
// 	}
// }

int					vm_check_live(t_data *data)
{
	t_champion		*champion;

	// champion = data->champions;
	// while (champion)
	// {
	// 	vm_check_live_champion(champion);
	// 	if (champion->processes == NULL)
	// 		vm_check_live_kill_champ(data, champion);
	// 	champion = champion->next;
	// }
	return (1);
}
