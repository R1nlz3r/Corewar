/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:27:32 by dwald             #+#    #+#             */
/*   Updated: 2018/04/20 18:08:16 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_sti(int param[], t_champion *champ, t_data *data)
{
	bool	error;

	param[0] = champ->argstype[0];
	param[1] = champ->argstype[1];
	param[2] = champ->argstype[2];
	error = false;
	if ((param[0] > 3 || param[0] < 1) || (param[1] > 3 || param[1] < 1)
	|| (param[2] > 3 || param[2] < 1))
		error = true;
	else if (param[0] != REG_CODE || (param[2] != DIR_CODE
	&& param[2] != REG_CODE))
		error = true;
	if (error == true)
	{
		if ((data->verbose & 32) == 32)
			ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-2);
	}
	else
		return (0);
}

/*
** Note: final address indicated as "with pc and mod" is always positive
*/

static	void	verbose_sti(t_data *data, t_champion *champ, int *parameter,
				int pc_dest)
{
	char	color[7];

	if ((data->verbose & 4) == 4)
	{
		color_champion(champ->number, color);
		ft_printf("%sPlayer #%i | sti r%i %i %i\n",
		color, champ->number, champ->args[0], parameter[0], parameter[1]);
		ft_printf("          | -> store to %i + %i = %i (with pc and mod %i)\n"\
		RESET, parameter[0], parameter[1], parameter[0] + parameter[1],\
		pc_dest);
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
	if (check_error_sti((int(*))&parameter, champ, data) == -1)
		return (-1);
	if (parameter[1] == REG_CODE)
		parameter[0] = champ->reg[champ->args[1]];
	else if (parameter[1] == IND_CODE)
		parameter[0] = get_mem_32bits(champ, idx_address(champ->args[1]));
	else if (parameter[1] == DIR_CODE)
		parameter[0] = get_address(champ->args[1]);
	if (parameter[2] == REG_CODE)
		parameter[1] = get_address(champ->reg[champ->args[2]]);
	else if (parameter[2] == DIR_CODE)
		parameter[1] = get_address(champ->args[2]);
	pc_dest = mem_mod(champ->oldpc->id
	+ (parameter[0] + parameter[1]) % IDX_MOD);
	write_in_ram(champ, pc_dest);
	verbose_sti(data, champ, parameter, pc_dest);
	return (1);
}
