/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:38:51 by cyrillef          #+#    #+#             */
/*   Updated: 2018/04/03 16:13:41 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		kill_champ(t_data *data, t_champion *champ)
{
	ft_printf("CHAMPION KILLED\n");
	champ->alive = 0;
	// if (champ->filename != NULL)
	// 	free(champ->filename);
	// if (champ->prev != NULL && champ->next != NULL)
	// {
	// 	champ->prev->next = champ->next;
	// 	champ->next->prev = champ->prev;
	// }
	// else if (champ->prev == NULL && champ->next != NULL)
	// 	champ->next->prev = NULL;
	// else if (champ->prev != NULL && champ->prev == NULL)
	// 	champ->prev->next = NULL;
	// else
	// 	data->champions = NULL;
	data->nb_champion--;
	// free(champ);
	ft_printf(RED"TEST\n"RESET);
}

int				check_live(t_data *data)
{
	t_champion	*champ;
	t_champion	*tmp;

	if (data->cycle % data->cycletodie == 0)
	{
		champ = data->champions;
		while (champ->next != NULL)
			champ = champ->next;
		while (champ != NULL && data->nb_champion > 1)
		{
			if (champ->alive == 0)
				continue ;
			tmp = champ->prev;
			ft_printf(CYAN"Testing %s\n"RESET, champ->name);
			if (champ->liveNbr == 0)
				kill_champ(data, champ);
			else
			{
				champ->previousLive = champ->liveNbr;
				champ->liveNbr = 0;
			}
			ft_printf(CYAN"End of testing the champion, next champion switch\n"RESET);
			champ = tmp;
			ft_printf("%s\n", data->champions->name);
			ft_printf(CYAN"Switch complete. %d champions left alive\n"RESET, data->nb_champion);
		}
		ft_printf(GREEN"END OF CHECK LIVE\n"RESET);
	}
	return (-1);
}
