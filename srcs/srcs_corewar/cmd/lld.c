/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:59:56 by cfrouin           #+#    #+#             */
/*   Updated: 2018/04/20 18:11:21 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int		check_error_lld(int param[], t_champion *champ, t_data *data)
{
	bool	error;

	param[0] = champ->argstype[0];
	param[1] = champ->argstype[1];
	error = false;
	if ((param[0] > 3 || param[0] < 1) || (param[1] > 3 || param[1] < 1))
		error = true;
	else if ((param[0] != DIR_CODE && param[0] != IND_CODE)
	|| param[1] != REG_CODE)
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

static	void	verbose_lld(t_data *data, t_champion *champ, int val)
{
	char	color[7];

	if ((data->verbose & 4) == 4)
	{
		color_champion(champ->number, color);
		ft_printf("%sPlayer #%i | lld %i (hex %x) -> r%i\n"RESET, color,
		champ->number, val, (unsigned int)val, champ->args[1]);
	}
	return ;
}

int				corewar_lld(t_data *data, t_champion *champ)
{
	int		parameter[2];
	int		val;

	val = 0;
	if (data->debug)
		dump_state("lld", data, champ);
	if (check_error_lld((int(*))&parameter, champ, data) == -1)
		return (-1);
	if (parameter[0] == DIR_CODE)
	{
		champ->reg[champ->args[1]] = champ->args[0];
		val = champ->args[0];
	}
	else if (parameter[0] == IND_CODE)
	{
		val = get_mem_32bits(champ, mem_address(champ->args[0]));
		champ->reg[champ->args[1]] = val;
	}
	champ->carry = (champ->reg[champ->args[1]] == 0) ? 1 : 0;
	verbose_lld(data, champ, val);
	return (1);
}
