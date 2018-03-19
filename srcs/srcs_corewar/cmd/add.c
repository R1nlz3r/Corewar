/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:57:25 by dwald             #+#    #+#             */
/*   Updated: 2018/03/19 15:58:46 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Take three registries, add the first two, and place the result in the third,
** right before modifying the carry.
** REG_CODE param[2] = REG_CODE param[0] + REG_CODE param[1]
*/

int		corewar_add(t_data *data, t_champion *champ) //chekced, should be OK
{
	// Display tests
	if (data->debug)
		dump_state("ADD", data, champ);
	//end of tests
	(void)data;
	if (champ->argsType[0] != REG_CODE || champ->argsType[1] != REG_CODE
	|| champ->argsType[2] != REG_CODE)
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-1);
	}
	champ->reg[champ->args[2]] = champ->reg[champ->args[0]]
	+ champ->reg[champ->args[1]];
	champ->carry = (champ->args[0] == 0) ? 1 : 0;
	if (verbose_operations(data) == 1)
		ft_printf(CYAN"Player #%i | add r%d + r%d = (%d) -> r%d, carry = %d\n"
		RESET, champ->number, champ->args[0], champ->args[1],
		champ->reg[champ->args[2]], champ->args[2], champ->carry);
	return (1);
}
