/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:27:32 by dwald             #+#    #+#             */
/*   Updated: 2018/02/06 15:42:30 by dwald            ###   ########.fr       */
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
	int		pc_dest;
	int		parameter[2];

	tmp = champ->pc;
	if (champ->argsType[0] != T_REG || (champ->argsType[2] != T_DIR
	&& champ->argsType[2] != T_REG))
		return (-1);
//  2nd param
	if (champ->argsType[1] == T_REG)
		parameter[0] = champ->reg[champ->args[1]];
	else if (champ->argsType[1] == T_IND)
	{
		pc_dest = champ->ipc + (champ->args[0] % IDX_MOD);
		while (champ->ipc > pc_dest--)
			tmp = tmp->next;
		parameter[0] = tmp->contentn;
	}
	else if (champ->argsType[1] == T_DIR)
		parameter[0] = champ->args[1];
//	3rd param
	if (champ->argsType[2] == T_REG)
		parameter[1] = champ->reg[champ->args[2]];
	else if (champ->argsType[2] == T_DIR)
		parameter[1] = champ->args[2];
	pc_dest = parameter[0] + parameter[1]; //get final address
	champ->carry = (pc_dest == 0) ? 1 : 0;
	tmp = champ->pc;
	while (champ->ipc > pc_dest--)
		tmp = tmp->next;
	tmp->contentn = champ->reg[champ->args[0]];
	number_to_hex_str(tmp->contentn, tmp->content); //wrong param format
	return (1);
}
