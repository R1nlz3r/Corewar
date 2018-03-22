/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:46:06 by dwald             #+#    #+#             */
/*   Updated: 2018/03/22 16:13:18 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_zjmp(t_data *data, t_champion *champ)
{
	short	pc_dest;
	int		index;
	t_node	*tmp;

	tmp = champ->pc;
	pc_dest = 0;
	index = champ->args[0];
	if (data->debug)
		dump_state("ZJUMP", data, champ);
	if (champ->argsType[0] != DIR_CODE)
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-1);
	}
	if (champ->carry == 1)
	{
	//	ft_printf(CYAN"champ->args[0] = %d\n"RESET,champ->args[0]);
	//	ft_printf(CYAN"champ->args[0] % IDX_MOD = %d\n"RESET,champ->args[0]%IDX_MOD);
		pc_dest = mem_mod(champ->oldipc + index);
		if (verbose_operations(data))
			ft_printf("Player #%d | zjmp %d OK\n", champ->number, pc_dest);
	}
	else
	{
		if (verbose_operations(data))
			ft_printf("Player #%d | zjmp %d FAILED\n", champ->number, pc_dest);
	}
	return (1);
}
/*
	{
		pc_dest = champ->args[0] + champ->ipc;
		while (champ->ipc < pc_dest--)
			tmp = tmp->next;
//assigning new node pointer (memory emplacement in VM's RAM)
		champ->pc = tmp;
//changing PC accordingly
		champ->ipc = champ->args[0] + champ->ipc;
		printf("champ->ipc = %d", champ->ipc);
	}
*/
