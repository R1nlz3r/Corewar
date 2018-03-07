/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:27:32 by dwald             #+#    #+#             */
/*   Updated: 2018/03/07 10:13:27 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Take a registry and two indexes (potentially registries) add the two indexes
** and use this result as an address where the value of the first parameter
** will be copied. Modifies carry.
*/

int		corewar_sti(t_data *data, t_champion *champ)
{
	t_node	*tmp;
	short	pc_dest;
	int		parameter[2];

	// Display tests
	ft_printf("STI called at cycle %d\n", data->cycle);
	ft_printf(GREEN"pc %d\n"RESET, champ->pc->id);
	for (int i = 0; i < 3; i++)
		ft_printf(GREEN"arg type %d args[%d] = %d\n"RESET, champ->argsType[i], i, champ->args[i]);
	tmp = NULL;
	(void)data;
	if (champ->argsType[0] != T_REG || (champ->argsType[2] != T_DIR
	&& champ->argsType[2] != T_REG))
		return (-1);
//  2nd param
	if (champ->argsType[1] == T_REG)
		parameter[0] = champ->reg[champ->args[1]];
	else if (champ->argsType[1] == T_IND)
	{
		pc_dest = champ->ipc + (champ->args[0] % IDX_MOD);
		tmp = find_pc_node(champ, pc_dest);
		parameter[0] = tmp->contentn;
	}
	else if (champ->argsType[1] == T_DIR)
		parameter[0] = champ->args[1];
//	3rd param
	if (champ->argsType[2] == T_REG)
		parameter[1] = champ->reg[champ->args[2]];
	else if (champ->argsType[2] == T_DIR)
		parameter[1] = champ->args[2];
//get final address and stock there reg[param1]
	pc_dest = parameter[0] + parameter[1];
	champ->carry = (pc_dest == 0) ? 1 : 0;
	ft_printf(YELLOW"sti pc = %d, carry %d\n"RESET,tmp->id,champ->carry);
	ft_printf(YELLOW"champ ipc = %d, pc_dest = %d\n"RESET,champ->ipc, pc_dest);
	write_in_ram(champ, pc_dest);
	return (1);
}
