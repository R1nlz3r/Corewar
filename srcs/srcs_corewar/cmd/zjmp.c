/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:46:06 by dwald             #+#    #+#             */
/*   Updated: 2018/03/23 15:03:49 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_zjmp(int param, int player)
{
	if (champ->argsType[0] != DIR_CODE)
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", player);
		return (-1);
	}
	else
		return (0);
}

int		corewar_zjmp(t_data *data, t_champion *champ)
{
	short	pc_dest;
	int		index;

	pc_dest = 0;
	if (data->debug)
		dump_state("ZJUMP", data, champ);
	if (check_error_zjmp(champ->argsType[0], champ->number) == -1)
		return (-1);
	pc_dest = mem_mod(champ->oldpc->id + champ->args[0]);
	index = pc_dest - champ->oldpc->id;
	if (champ->carry == 1)
	{
	//	ft_printf(CYAN"champ->args[0] = %d\n"RESET,champ->args[0]);
	//	ft_printf(CYAN"champ->args[0] % IDX_MOD = %d\n"RESET,champ->args[0]%IDX_MOD);
//		ft_printf(CYAN"oldpc = %d oldipc= %d pc_dest = %d\n"RESET, champ->oldpc->id, champ->oldipc, pc_dest);
		while (champ->pc->id != pc_dest)
			champ->pc = champ->pc->next;
		if (verbose_operations(data))
			ft_printf("Player #%d | zjmp %d OK\n", champ->number, index);
	}
	else
	{
		if (verbose_operations(data))
			ft_printf("Player #%d | zjmp %d FAILED\n", champ->number, index);
	}
	return (1);
}
