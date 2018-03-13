/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:27:32 by dwald             #+#    #+#             */
/*   Updated: 2018/03/13 17:24:39 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Take a registry and two indexes (potentially registries) add the two indexes
** and use this result as an address where the value of the first parameter
** will be copied.
*/

int		corewar_sti(t_data *data, t_champion *champ)
{
	t_node	*tmp;
	short	pc_dest;
	int		parameter[2];

	// Display tests
	dump_state("STI", data, champ);
	//end of tests
	tmp = NULL;
	pc_dest = mem_mod(champ->ipc + champ->args[0] % IDX_MOD);
	(void)data;
	if (champ->argsType[0] != REG_CODE || (champ->argsType[2] != DIR_CODE
	&& champ->argsType[2] != REG_CODE))
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-1);
	}
//  2nd param
	if (champ->argsType[1] == REG_CODE)
		parameter[0] = champ->reg[champ->args[1]];
	else if (champ->argsType[1] == IND_CODE)
	{
		ft_printf(RED"Looking for indirect value\n"RESET);
		parameter[0] = find_indirect_value(champ, 1);
	}
	else if (champ->argsType[1] == DIR_CODE)
		parameter[0] = champ->args[1];
//	3rd param
	if (champ->argsType[2] == REG_CODE)
		parameter[1] = champ->reg[champ->args[2]];
	else if (champ->argsType[2] == DIR_CODE)
		parameter[1] = champ->args[2];
//get final address and stock there reg[param1]
	pc_dest = mem_mod((parameter[0] + parameter[1]) % IDX_MOD);
//	ft_printf(YELLOW"champ ipc = %d, pc_dest = %d\n"RESET,champ->ipc, pc_dest);
	pc_dest = write_in_ram(champ, pc_dest);
//	write_in_ram(champ, pc_dest, parameter[2]); possible adaptation
	if (verbose_operations(data) == 1)
	{
		ft_printf(CYAN"Player #%i | sti r%i %i %i\n\
	  | -> store to %i + %i = %i (with pc and mod %i) register value %i\n"RESET,
		champ->number, champ->args[0], parameter[0], parameter[1], parameter[0],
		parameter[1], parameter[0] + parameter[1], pc_dest,
		champ->reg[champ->args[0]]);
	}
	return (1);
}
