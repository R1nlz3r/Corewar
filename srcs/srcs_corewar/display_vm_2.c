/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_vm_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:28:05 by mapandel          #+#    #+#             */
/*   Updated: 2018/02/07 20:12:13 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		update_legend(t_data *data)
{
	t_champion	*tmp;
	int			i;

	tmp = data->champions;
	i = 0;
	if (data->pause)
		ft_putstr("\033[0;97m\033[3;200H** PAUSED ** ");
	else
		ft_putstr("\033[0;97m\033[3;200H** RUNNING **");
	ft_printf("\033[5;208H%dx%-10", data->speed);
	ft_putstr("\033[8;208H");
	ft_putnbr(data->cycle);
	// Processes
	while (i < data->nb_champion)
	{
		ft_printf("\033[%d;214H%21d", i * 4 + 13, tmp->lastLive);
		ft_printf("\033[%d;228H%7d", i++ * 4 + 14, tmp->liveNbr);
		tmp = tmp->next;
	}
	// Live breakdown for current period
	// Live breakdown for last period
	ft_printf("\033[%d;215H%-37d", (data->nb_champion - 1) * 4 + 22,
		data->cycletodie);
}
