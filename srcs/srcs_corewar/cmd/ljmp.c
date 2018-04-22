/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ljmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:46:06 by dwald             #+#    #+#             */
/*   Updated: 2018/04/22 16:52:22 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_ljmp(int param, int player, t_data *data)
{
	if (param != DIR_CODE)
	{
		if ((data->verbose & 32) == 32)
			ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", player);
		return (-2);
	}
	else
		return (0);
}

int				corewar_ljmp(t_data *data, t_champion *champ)
{
	short	pc_dest;
	int		index;
	char	color[7];

	pc_dest = 0;
	if (data->debug)
		dump_state("ljump", data, champ);
	if (check_error_ljmp(champ->argstype[0], champ->number, data) == -1)
		return (-1);
	pc_dest = mem_mod(champ->oldpc->id + champ->args[0]);
	index = pc_dest - champ->oldpc->id;
	color_champion(champ->number, color);
	if (champ->carry == 1)
	{
		while (champ->pc->id != pc_dest)
			champ->pc = champ->pc->next;
		if ((data->verbose & 4) == 4)
			ft_printf("%sPlayer #%d | ljmp %d (%d) OK (PC: %d)\n"RESET,
			color, champ->number, champ->args[0], index, champ->pc->id);
		return (1);
	}
	if ((data->verbose & 4) == 4)
		ft_printf("%sPlayer #%d | ljmp %d (%d) FAILED (PC: %d)\n"RESET,
		color, champ->number, champ->args[0], index, champ->pc->id);
	return (1);
}
