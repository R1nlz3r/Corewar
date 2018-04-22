/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:59:50 by cfrouin           #+#    #+#             */
/*   Updated: 2018/04/20 19:00:29 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_lldi(int param[], t_champion *champ, t_data *data)
{
	bool	error;

	param[0] = champ->argstype[0];
	param[1] = champ->argstype[1];
	param[2] = champ->argstype[2];
	error = false;
	if ((param[0] > 3 || param[0] < 1) || (param[1] > 3 || param[1] < 1)
	|| (param[2] > 3 || param[2] < 1))
		error = true;
	else if ((param[1] != DIR_CODE && param[1] != REG_CODE)
	|| param[2] != REG_CODE)
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

static	void	verbose_lldi(t_data *data, t_champion *champ, int *parameter,
				int pc_dest)
{
	char	color[7];

	if ((data->verbose & 4) == 4)
	{
		color_champion(champ->number, color);
		ft_printf("%sPlayer #%i | lldi %i %i r%i\n",\
		color, champ->number, parameter[0], parameter[1], champ->args[2]);
		ft_printf("          | -> load from %i + %i = %i (with pc %i) \
into r%i value %i (hex %x)\n"RESET, parameter[0], parameter[1],\
		parameter[0] + parameter[1], champ->oldpc->id + pc_dest, champ->args[2],
		parameter[3], (unsigned int)parameter[3]);
	}
	return ;
}

int				corewar_lldi(t_data *data, t_champion *champ)
{
	short	pc_dest;
	int		parameter[4];

	if (data->debug)
		dump_state("lldi", data, champ);
	if (check_error_lldi((int(*))&parameter, champ, data) == -1)
		return (-1);
	if (parameter[0] == REG_CODE)
		parameter[0] = get_address(champ->reg[champ->args[0]]);
	else if (parameter[0] == IND_CODE)
		parameter[0] = get_mem_32bits(champ, idx_address(champ->args[0]));
	else if (parameter[0] == DIR_CODE)
		parameter[0] = get_address(champ->args[0]);
	if (parameter[1] == REG_CODE)
		parameter[1] = get_address(champ->reg[champ->args[1]]);
	else if (parameter[1] == DIR_CODE)
		parameter[1] = get_address(champ->args[1]);
	pc_dest = mem_mod(parameter[0] + parameter[1]);
	parameter[3] = get_mem_32bits(champ, pc_dest);
	champ->reg[champ->args[2]] = parameter[3];
	verbose_lldi(data, champ, parameter, pc_dest);
	return (1);
}
