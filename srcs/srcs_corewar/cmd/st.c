/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:53:45 by dwald             #+#    #+#             */
/*   Updated: 2018/02/13 14:34:14 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Takes a registry and a registry or an indirect and store the value of
** the registry toward a second argument. For example, st r1, 42 store
** the value of r1 at the address (PC + (42 % IDX_MOD))
** If the first parameter is zero, carry changes to 1, otherwise carry is 0.
*/

int		corewar_st(t_data *data, t_champion *champ)
{
	t_node	*tmp;
	short	pc_dest;

	tmp = champ->pc;
	if (champ->argsType[0] != T_REG || (champ->argsType[1] != T_IND
	&& champ->argsType[1] != T_REG))
		return (-1);
	if (champ->argsType[1] == T_REG)
		champ->reg[champ->args[1]] = champ->reg[champ->args[0]];
	else if (champ->argsType[1] == T_IND)
	{
		pc_dest = champ->ipc + (champ->args[0] % IDX_MOD);
		while (champ->ipc > pc_dest--)
			tmp = tmp->next;
		tmp->contentn = champ->reg[champ->args[1]];
		number_to_hex_str(tmp->contentn,(unsigned char(*)[]) &(tmp->content));
	}
	champ->carry = (champ->args[0] == 0) ? 1 : 0;
	return (1);
}
