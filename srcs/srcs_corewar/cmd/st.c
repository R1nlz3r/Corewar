/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:53:45 by dwald             #+#    #+#             */
/*   Updated: 2018/03/21 15:46:38 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_st(int param[], int player, t_champion *champ)
{
	bool	error;

	param[0] = champ->argsType[0];
	param[1] = champ->argsType[1];
	param[2] = champ->argsType[2];
	error = false;
	if ((param[0] > 3 || param[0] < 1) || (param[1] > 3 || param[1] < 1)
	|| (param[2] > 3 || param[2] < 1))
		error = true;
	else if (param[0] != REG_CODE || (param[1] != IND_CODE
	&& param[1] != REG_CODE))
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

static	void	verbose_st(t_data *data, t_champion *champ, int *parameter,
				int pc_dest)
{
	if (verbose_operations(data) == 1) //check the printf args if 100 % correct
	{
		ft_printf(CYAN"Player #%i | st r%i %i\n		\
| -> store register %i value %i to %i\n"RESET,
		champ->number, champ->argsType[0], parameter[0], champ->argsType[0],
		champ->reg[champ->args[0]], parameter[0]);
		if (champ->argsType[1] == IND_CODE)
			ft_printf(CYAN"(IND_CODE value with pc and mod %i)\n"RESET,
			pc_dest);
	}
	return ;
}

/*
** Takes a registry and a registry or an indirect and store the value of
** the registry toward a second argument. For example, st r1, 42 store
** the value of r1 at the address (PC + (42 % IDX_MOD))
*/

int				corewar_st(t_data *data, t_champion *champ)
{
	t_node	*tmp;
	short	pc_dest;
	int		parameter[3];

	pc_dest = -1;
	if (data->debug)
		dump_state("ST", data, champ);
	tmp = champ->pc;
	if (check_error_st((int(*))&parameter, champ->number, champ) == -1)
		return (-1);
	if (parameter[1] == REG_CODE)
	{
		champ->reg[champ->args[1]] = champ->reg[champ->args[0]];
		parameter[0] = champ->reg[champ->args[1]];
	}
	else if (parameter[1] == IND_CODE)
	{
		pc_dest = mem_mod(champ->ipc + (champ->args[0] % IDX_MOD));
		parameter[0] = champ->ipc + champ->args[0];
		while (champ->ipc < pc_dest--)
			tmp = tmp->next;
		tmp->contentn = champ->reg[champ->args[1]];
		number_to_hex_str(tmp->contentn, (unsigned char(*)[]) &(tmp->content));
		pc_dest = mem_mod(champ->ipc + (champ->args[0] % IDX_MOD));
	}
	verbose_st(data, champ, parameter, pc_dest);
	return (1);
}
