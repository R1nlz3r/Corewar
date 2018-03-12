/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:00:20 by cfrouin           #+#    #+#             */
/*   Updated: 2018/03/12 17:08:00 by dwald            ###   ########.fr       */
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
	ft_printf("AND called at cycle %d\n", data->cycle);
	ft_printf(GREEN"pc %d\n"RESET, champ->pc->id);
	for (int i = 0; i < 3; i++)
		ft_printf(GREEN"arg type %d args[%d] = %d\n"RESET, champ->argsType[i], i, champ->args[i]);
	//end of tests

	int		parameter[2];

	parameter[0] = champ->argsType[0];
	parameter[1] = champ->argsType[1];
	(void)data;
	if (champ->argsType[2] != T_REG)
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-1);
	}
	if (parameter[0] == T_REG)
		parameter[0] = champ->reg[champ->args[0]];
	else if (parameter[0] == T_DIR)
		parameter[0] = champ->args[0];
/*	else if (parameter[0] == T_IND)
	{
		tmp = find_pc_node(champ, mem_mod(champ->ipc + champ->args[0] % IDX_MOD);
		parameter[0] = tmp->contentn;
	}
	if (parameter[1] == T_REG)
		parameter[1] = champ->reg[champ->args[1]];
	else if (parameter[1] == T_DIR)
		parameter[1] = champ->args[1];
	else if (parameter[1] == T_IND)
	{

	}

*/
	champ->reg[champ->args[2]] = champ->reg[champ->args[0]]
	& champ->reg[champ->args[1]];
	champ->carry = (champ->reg[champ->args[2]] == 0) ? 1 : 0;
	return (1);
}
