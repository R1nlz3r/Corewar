/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:59:24 by cfrouin           #+#    #+#             */
/*   Updated: 2018/03/16 14:10:55 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_xor(int param1, int param2, int param3, int player)
{
	bool	error;

	error = false;
	if ((param1 > 3 || param1 < 1) || (param2 > 3 || param2 < 1) 
	|| (param3 > 3 || param3 < 1))
		error = true;
	else if (param3 != REG_CODE)
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
** Apply an ^ (bit-to-bit XOR) over the first two arguments and store the result
** in a registry, which is the third argument. Modifies the carry.
*/

int		corewar_xor(t_data *data, t_champion *champ)
{
	int		parameter[2];

	// Display tests
	if (data->debug)
		dump_state("OR", data, champ);
	//end of tests

	parameter[0] = champ->argsType[0];
	parameter[1] = champ->argsType[1];
	(void)data;
	if (check_error_xor(parameter[0], parameter[1], champ->argsType[2],
	champ->number) == -1)
		return (-1);
	if (parameter[0] == REG_CODE)
		parameter[0] = champ->reg[champ->args[0]];
	else if (parameter[0] == DIR_CODE)
		parameter[0] = champ->args[0];
	else if (parameter[0] == IND_CODE)
	{
		ft_printf(RED"Looking for indirect value\n"RESET);
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
//	ft_printf("champ->carry = %d\n",  champ->carry);
	return (1);
}
