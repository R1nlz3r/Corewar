/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:57:35 by dwald             #+#    #+#             */
/*   Updated: 2018/04/20 15:42:49 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			corewar_live(t_data *data, t_champion *champ)
{
	int		val;
	char	color[7];

	if ((data->verbose & 1) == 1)
	{
		ft_putstr_fd("Player ", 1);
		ft_putstr_fd(champ->name, 1);
		ft_putstr_fd(" was reported alive\n", 1);
	}
	champ->alive = 1;
	champ->livenbr++;
	data->live++;
	data->lastlive = champ->number;
	val = get_mem_32bits(champ, 1);
	if ((data->verbose & 4) == 4)
	{
		color_champion(champ->number, color);
		ft_printf("%sPlayer #%i | live: %d\n"RESET, color, champ->number, val);
	}
	return (1);
}
