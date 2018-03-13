/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:00:20 by cfrouin           #+#    #+#             */
/*   Updated: 2018/03/13 17:34:29 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Apply an & (bit-to-bit AND) over the first two arguments and store the result
** in a registry, which is the third argument. Modifies the carry.
*/

int			corewar_and(t_data *data, t_champion *champ)
{
	// Display tests
	if (data->debug)
		dump_state("AND", data, champ);
	//end of tests

	int		parameter[2];

	parameter[0] = champ->argsType[0];
	parameter[1] = champ->argsType[1];
	(void)data;
	if (champ->argsType[2] != REG_CODE)
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-1);
	}
	if (parameter[0] == REG_CODE)
		parameter[0] = champ->reg[champ->args[0]];
	else if (parameter[0] == DIR_CODE)
		parameter[0] = champ->args[0];
/*	else if (parameter[0] == IND_CODE)
	{
		tmp = find_pc_node(champ, mem_mod(champ->ipc + champ->args[0] % IDX_MOD);
		parameter[0] = tmp->contentn;
	}
	if (parameter[1] == REG_CODE)
		parameter[1] = champ->reg[champ->args[1]];
	else if (parameter[1] == DIR_CODE)
		parameter[1] = champ->args[1];
	else if (parameter[1] == IND_CODE)
	{

	}

*/
	champ->reg[champ->args[2]] = champ->reg[champ->args[0]]
	& champ->reg[champ->args[1]];
	champ->carry = (champ->reg[champ->args[2]] == 0) ? 1 : 0;
	return (1);
}
