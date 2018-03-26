/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:27:32 by dwald             #+#    #+#             */
/*   Updated: 2018/03/26 14:56:19 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_sti(int param[], t_champion *champ)
{
	bool	error;

	param[0] = champ->argsType[0];
	param[1] = champ->argsType[1];
	param[2] = champ->argsType[2];
	error = false;
	if ((param[0] > 3 || param[0] < 1) || (param[1] > 3 || param[1] < 1) 
	|| (param[2] > 3 || param[2] < 1))
		error = true;
	else if (param[0] != REG_CODE || (param[2] != DIR_CODE
	&& param[2] != REG_CODE))
		error = true;
	if (error == true)
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-1);
	}
	else
		return (0);
}

static	void	verbose_sti(t_data *data, t_champion *champ, int *parameter,
				int pc_dest)
{
	if (verbose_operations(data) == 1)
	{
		ft_printf(CYAN"Player #%i | sti r%i %i %i\n",
		champ->number, champ->args[0], parameter[0], parameter[1]);
		ft_printf("          | -> store to %i + %i = %i (with pc and mod %i) \
register value %i\n"RESET, parameter[0], parameter[1],
		parameter[0] + parameter[1], pc_dest, champ->reg[champ->args[0]]);
	}
	return ;
}

/*
** Take a registry and two indexes (potentially registries) add the two indexes
** and use this result as an address where the value of the first parameter
** will be copied.
*/

int				corewar_sti(t_data *data, t_champion *champ)
{
	short	pc_dest;
	int		parameter[3];

	if (data->debug)
		dump_state("STI", data, champ);
	if (check_error_sti((int(*))&parameter, champ) == -1)
		return (-1);
//  2nd param
	if (parameter[1] == REG_CODE)
		parameter[0] = champ->reg[champ->args[1]];
	else if (parameter[1] == IND_CODE)
	{
		ft_printf(RED"Looking for indirect value\n"RESET);
		parameter[0] = find_indirect_value(champ, champ->args[1] % IDX_MOD);
//	ft_printf("param[0] %d\n", parameter[0]);
	}
	else if (parameter[1] == DIR_CODE)
		parameter[0] = champ->args[1];
//	3rd param
	if (parameter[2] == REG_CODE)
		parameter[1] = champ->reg[champ->args[2]];
	else if (parameter[2] == DIR_CODE)
		parameter[1] = champ->args[2];
//	get final address and stock there reg[param1]
ft_printf(YELLOW"parameter[0] = %d param[1] = %d\n"RESET,parameter[0],parameter[1]);
	pc_dest = mem_mod((parameter[0] + parameter[1]) % IDX_MOD);
	ft_printf(YELLOW"champ ipc = %d pc_dest = %d\n"RESET,champ->pc->id, pc_dest);
	pc_dest = write_in_ram(champ, pc_dest);
//	write_in_ram(champ, pc_dest, parameter[2]); possible adaptation
	verbose_sti(data, champ, parameter, pc_dest);
	return (1);
}
