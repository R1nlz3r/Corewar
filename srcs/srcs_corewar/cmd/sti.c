/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:27:32 by dwald             #+#    #+#             */
/*   Updated: 2018/03/16 15:55:32 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_sti(int param1, int param2, int param3, int player)
{
	bool	error;

	error = false;
	if ((param1 > 3 || param1 < 1) || (param2 > 3 || param2 < 1) 
	|| (param3 > 3 || param3 < 1))
		error = true;
	else if (param1 != REG_CODE || (param3 != DIR_CODE && param3 != REG_CODE))
		error = true;
	if (error == true)
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", player);
		return (-1);
	}
	else
		return (0);
}

/*
** Take a registry and two indexes (potentially registries) add the two indexes
** and use this result as an address where the value of the first parameter
** will be copied.
*/

int		corewar_sti(t_data *data, t_champion *champ)
{
	t_node	*tmp;
	short	pc_dest;
	int		parameter[3];

	// Display tests
	if (data->debug)
		dump_state("STI", data, champ);
	// End of tests
	tmp = NULL;
	(void)data;
	parameter[0] = champ->argsType[0];
	parameter[1] = champ->argsType[1];
	parameter[2] = champ->argsType[2];
	if (check_error_sti(parameter[0], parameter[1], parameter[2],
	champ->number) == -1)
		return (-1);
//  2nd param
	if (parameter[1] == REG_CODE)
		parameter[0] = champ->reg[champ->args[1]];
	else if (parameter[1] == IND_CODE)
	{
		ft_printf(RED"Looking for indirect value\n"RESET);
		parameter[0] = find_indirect_value(champ, 1);
//	ft_printf("param[0] %d\n", parameter[0]);
	}
	else if (parameter[1] == DIR_CODE)
		parameter[0] = champ->args[1];
//	3rd param
	if (parameter[2] == REG_CODE)
		parameter[1] = champ->reg[champ->args[2]];
	else if (parameter[2] == DIR_CODE)
		parameter[1] = champ->args[2];
//get final address and stock there reg[param1]
	pc_dest = mem_mod((parameter[0] + parameter[1]) % IDX_MOD);
//	ft_printf(YELLOW"champ ipc = %d, pc_dest = %d\n"RESET,champ->ipc, pc_dest);
	pc_dest = write_in_ram(champ, pc_dest);
//	write_in_ram(champ, pc_dest, parameter[2]); possible adaptation
	if (verbose_operations(data) == 1)
	{
		ft_printf(CYAN"Player #%i | sti r%i %i %i\n",
		champ->number, champ->args[0], parameter[0], parameter[1]);
		ft_printf("          | -> store to %i + %i = %i (with pc and mod %i) \
register value %i\n"RESET, parameter[0], parameter[1],
		parameter[0] + parameter[1], pc_dest, champ->reg[champ->args[0]]);
	}
	return (1);
}
