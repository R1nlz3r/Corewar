/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:25:07 by dwald             #+#    #+#             */
/*   Updated: 2018/04/20 18:08:24 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_xor(int player, t_champion *champ, t_data *data)
{
	bool	error;

	error = false;
	if ((champ->argstype[0] > 3 || champ->argstype[0] < 1)
	|| (champ->argstype[1] > 3 || champ->argstype[1] < 1)
	|| (champ->argstype[2] > 3 || champ->argstype[2] < 1))
		error = true;
	else if (champ->argstype[2] != REG_CODE)
		error = true;
	if (error == true)
	{
		if ((data->verbose & 32) == 32)
			ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", player);
		return (-2);
	}
	else
		return (0);
}

static	void	verbose_xor(t_data *data, t_champion *champ, int *parameter)
{
	char	color[7];

	if ((data->verbose & 4) == 4)
	{
		color_champion(champ->number, color);
		ft_printf("%sPlayer #%i | xor %d ^ %d = (%d) -> r%d carry = %i\n"RESET,
		color, champ->number, parameter[0], parameter[1],
		champ->reg[champ->args[2]], champ->args[2], champ->carry);
	}
	return ;
}

/*
** Apply an ^ (bit-to-bit XOR) over the first two arguments and store the result
** in a registry, which is the third argument. Modifies the carry.
*/

int				corewar_xor(t_data *data, t_champion *champ)
{
	int		parameter[2];

	parameter[0] = champ->argstype[0];
	parameter[1] = champ->argstype[1];
	if (data->debug)
		dump_state("xor", data, champ);
	if (check_error_xor(champ->number, champ, data) == -1)
		return (-1);
	if (parameter[0] == REG_CODE)
		parameter[0] = champ->reg[champ->args[0]];
	else if (parameter[0] == DIR_CODE)
		parameter[0] = champ->args[0];
	else if (parameter[0] == IND_CODE)
		parameter[0] = get_mem_32bits(champ, idx_address(champ->args[0]));
	if (parameter[1] == REG_CODE)
		parameter[1] = champ->reg[champ->args[1]];
	else if (parameter[1] == DIR_CODE)
		parameter[1] = champ->args[1];
	else if (parameter[1] == IND_CODE)
		parameter[1] = get_mem_32bits(champ, idx_address(champ->args[1]));
	champ->reg[champ->args[2]] = parameter[0] ^ parameter[1];
	champ->carry = (champ->reg[champ->args[2]] == 0) ? 1 : 0;
	verbose_xor(data, champ, parameter);
	return (1);
}
