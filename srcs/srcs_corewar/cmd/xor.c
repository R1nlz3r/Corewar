/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:25:07 by dwald             #+#    #+#             */
/*   Updated: 2018/03/22 11:10:53 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_xor(int player, t_champion *champ)
{
	bool	error;

	error = false;
	if ((champ->argsType[0] > 3 || champ->argsType[0] < 1)
	|| (champ->argsType[1] > 3 || champ->argsType[1] < 1)
	|| (champ->argsType[2] > 3 || champ->argsType[2] < 1))
		error = true;
	else if (champ->argsType[2] != REG_CODE)
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

static	void	verbose_xor(t_data *data, t_champion *champ, int *parameter)
{
	if (verbose_operations(data) == 1)
		ft_printf(CYAN"Player #%i | xor %d ^ %d = (%d) -> r%d carry = %i\n"
		RESET, champ->number, parameter[0], parameter[1],
		champ->reg[champ->args[2]], champ->args[2], champ->carry);
	return ;
}

/*
** Apply an ^ (bit-to-bit XOR) over the first two arguments and store the result
** in a registry, which is the third argument. Modifies the carry.
*/

int				corewar_xor(t_data *data, t_champion *champ) //checked shoud be OK
{
	int		parameter[2];

	parameter[0] = champ->argsType[0];
	parameter[1] = champ->argsType[1];
	if (data->debug)
		dump_state("XOR", data, champ);
	if (check_error_xor(champ->number, champ) == -1)
		return (-1);
	if (parameter[0] == REG_CODE)
		parameter[0] = champ->reg[champ->args[0]];
	else if (parameter[0] == DIR_CODE)
		parameter[0] = champ->args[0];
	else if (parameter[0] == IND_CODE)
	{
		ft_printf(RED"Looking for indirect value\n"RESET);
//	tmp = find_pc_node(champ, mem_mod(champ->ipc + champ->args[0] % IDX_MOD);
//	parameter[0] = tmp->contentn;
	}
	if (parameter[1] == REG_CODE)
		parameter[1] = champ->reg[champ->args[1]];
	else if (parameter[1] == DIR_CODE)
		parameter[1] = champ->args[1];
	else if (parameter[1] == IND_CODE)
	{
		ft_printf(RED"Looking for indirect value\n"RESET);
	}
	champ->reg[champ->args[2]] = parameter[0] ^ parameter[1];
	champ->carry = (champ->reg[champ->args[2]] == 0) ? 1 : 0;
	verbose_xor(data, champ, parameter);
	return (1);
}
