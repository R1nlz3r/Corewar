/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:20:48 by dwald             #+#    #+#             */
/*   Updated: 2018/02/28 15:39:40 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Use 2 indexes and 1 registry, adding the first two, treating that like
** an address, reading a value and putting it in 3rd. Modifies carry.
*/

int		corewar_ldi(t_data *data, t_champion *champ)
{
	t_node	*tmp;
	short	pc_dest;
	int		parameter[2];

	ft_printf("LDI called at cycle %d\n", data->cycle);
	ft_printf("arg type %d args[0] = %d\n", champ->argsType[0], champ->args[0]);
	ft_printf("arg type %d args[1] = %d\n", champ->argsType[1], champ->args[1]);
	ft_printf("arg type %d args[2] = %d\n", champ->argsType[2], champ->args[2]);
	(void)data;
	tmp = champ->pc;
	if ((champ->argsType[1] != T_DIR && champ->argsType[1] != T_REG)
	|| champ->argsType[2] != T_REG)
		return (-1);
//1st param
	if (champ->argsType[0] == T_REG)
		parameter[0] = champ->reg[champ->args[1]];
	else if (champ->argsType[0] == T_DIR)
		parameter[0] = champ->args[0];
	else if (champ->argsType[0] == T_IND)
	{
		pc_dest = champ->ipc + (champ->args[0] % IDX_MOD); //remove %  for lldi
		while (champ->ipc > pc_dest--)
			tmp = tmp->next;
		parameter[1] = (int)tmp->contentn;
	}
//  2nd param
	if (champ->argsType[1] == T_REG)
		parameter[1] = champ->reg[champ->args[1]];
	else if (champ->argsType[1] == T_DIR)
		parameter[1] = champ->args[1];
//get final address and stock its value in reg[param2]
	pc_dest = parameter[0] + parameter[1];
	champ->carry = (pc_dest == 0) ? 1 : 0;
	tmp = champ->pc;
	while (champ->ipc > pc_dest--)
		tmp = tmp->next;
	champ->reg[champ->args[2]] = (int)tmp->contentn;
	return (1);
}
