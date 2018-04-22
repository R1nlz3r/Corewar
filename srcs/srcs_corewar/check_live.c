/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 15:38:51 by cyrillef          #+#    #+#             */
/*   Updated: 2018/04/20 21:12:24 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		kill_champ(t_data *data, t_champion *champ)
{
	if ((data->verbose & 8) == 8)
		ft_printf("%s died.\n", champ->name);
	champ->alive = 0;
	data->nb_champion--;
}

static void		check_champions(t_data *data, t_champion *champ)
{
	t_champion	*tmp;

	while (champ != NULL && data->nb_champion > 1)
	{
		if (champ->alive == 0)
		{
			champ = champ->prev;
			continue ;
		}
		tmp = champ->prev;
		if (champ->livenbr <= 0)
			kill_champ(data, champ);
		else
		{
			champ->livenbr = 0;
		}
		champ = tmp;
	}
}

int				check_live(t_data *data)
{
	t_champion	*champ;

	if (data->cycle % data->cycletodie == 0 && data->cycle > 0)
	{
		champ = data->champions;
		while (champ->next != NULL)
			champ = champ->next;
		check_champions(data, champ);
		data->maxcheck++;
		if (data->live >= NBR_LIVE || data->maxcheck >= MAX_CHECKS)
		{
			data->cycletodie -= CYCLE_DELTA;
			data->maxcheck = 0;
		}
		data->live = 0;
		if (data->nb_champion <= 1)
			return (1);
	}
	return (0);
}
