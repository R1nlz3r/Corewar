/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:53:45 by dwald             #+#    #+#             */
/*   Updated: 2018/03/12 13:03:21 by dwald            ###   ########.fr       */
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
	int		parameter[2];
	bool	flag_indirect;

	// Display tests
	ft_printf("ST called at cycle %d\n", data->cycle);
	ft_printf(GREEN"pc %d\n"RESET, champ->pc->id);
	for (int i = 0; i < 3; i++)
		ft_printf(GREEN"arg type %d args[%d] = %d\n"RESET, champ->argsType[i], i, champ->args[i]);
	//end of tests
	(void)data;
	tmp = champ->pc;
/*	if (champ->argsType[0] != T_REG || (champ->argsType[1] != T_IND
	&& champ->argsType[1] != T_REG))
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's %s parameter \
with no valid argument type\n", champ->number);
		return (-1);
	}*/
	ft_printf(RED"HERE\n"RESET);
	if (champ->argsType[1] == T_REG)
	{
		champ->reg[champ->args[1]] = champ->reg[champ->args[0]];
		parameter[0] = champ->reg[champ->args[1]];
		flag_indirect = false;
	}
	else if (champ->argsType[1] == T_IND)
	{
		pc_dest = mem_mod(champ->ipc + (champ->args[0] % IDX_MOD));
		parameter[0] = champ->ipc + champ->args[0];
		flag_indirect = true;
		while (champ->ipc < pc_dest--)
			tmp = tmp->next;
		tmp->contentn = champ->reg[champ->args[1]];
		number_to_hex_str(tmp->contentn,(unsigned char(*)[]) &(tmp->content));
		pc_dest = mem_mod(champ->ipc + (champ->args[0] % IDX_MOD));
	}
	if (verbose_operations(data) == 1)
	{
		ft_printf(CYAN"Player #%i | st r%i %i\n\
	  | -> store register %i value %i to %i\n"RESET,
		champ->number, champ->argsType[0], parameter[0], champ->argsType[0],
		champ->reg[champ->args[0]], parameter[0]);
		if (flag_indirect == true)
			ft_printf(CYAN"(T_IND value with pc and mod %i)\n"RESET, pc_dest);

/*		ft_printf(CYAN"Player #%i | st r%i %i %i\n\
	  | -> store to %i + %i = %i (with pc and mod %i) register value %i\n"RESET,
		champ->number, champ->args[0], parameter[0], parameter[1], parameter[0],
		parameter[1], parameter[0] + parameter[1], pc_dest,
		champ->reg[champ->args[0]]);*/
	}
	return (1);
}
