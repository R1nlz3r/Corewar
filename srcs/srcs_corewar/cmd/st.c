/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:53:45 by dwald             #+#    #+#             */
/*   Updated: 2018/04/20 20:49:47 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_st(int param[], int player,
								t_champion *champ, t_data *data)
{
	bool	error;

	param[0] = champ->argstype[0];
	param[1] = champ->argstype[1];
	error = false;
	if ((param[0] > 3 || param[0] < 1) || (param[1] > 3 || param[1] < 1))
		error = true;
	else if (param[0] != REG_CODE || (param[1] != IND_CODE
	&& param[1] != REG_CODE))
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

static	void	verbose_st(t_data *data, t_champion *champ, int *parameter,
				int pc_dest)
{
	char	color[7];

	if ((data->verbose & 4) == 4)
	{
		color_champion(champ->number, color);
		ft_printf("%sPlayer #%i | st r%i %i\n",
		color, champ->number, champ->args[0], parameter[0]);
		ft_printf("	  | -> store r%i value (%i) to ",
		champ->args[0], champ->reg[champ->args[0]]);
		if (champ->argstype[1] == REG_CODE)
			ft_printf("r%i\n"RESET, parameter[0]);
		else if (champ->argstype[1] == IND_CODE)
			ft_printf("%i (value found at pc and mod %i)\n"RESET,
			parameter[0], pc_dest);
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
	short	pc_dest;
	int		parameter[3];

	pc_dest = -1;
	if (data->debug)
		dump_state("st", data, champ);
	if (check_error_st((int(*))&parameter, champ->number, champ, data) == -1)
		return (-1);
	if (parameter[1] == REG_CODE)
	{
		champ->reg[champ->args[1]] = champ->reg[champ->args[0]];
		parameter[0] = champ->args[1];
	}
	else if (parameter[1] == IND_CODE)
	{
		pc_dest = mem_mod(champ->oldpc->id + idx_address(champ->args[1]));
		parameter[0] = idx_address(champ->args[1]);
		write_in_ram(champ, pc_dest);
	}
	verbose_st(data, champ, parameter, pc_dest);
	return (1);
}
