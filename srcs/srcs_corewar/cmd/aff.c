/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:21:27 by dwald             #+#    #+#             */
/*   Updated: 2018/04/20 18:07:05 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Aff takes a register and displays the character the ASCII code of which is
** contained in the register. (a modulo 256 is applied to this ascii code,
** the character is displayed on the standard output).
*/

static	void	verbose_aff(t_data *data, t_champion *champ, char *color)
{
	if ((data->verbose & 4) == 4)
	{
		ft_printf("%schampion %d: aff %c\n"RESET,
		color, champ->number, (char)(champ->reg[champ->args[0]]));
	}
	return ;
}

int				corewar_aff(t_data *data, t_champion *champ)
{
	int		character;
	char	color[7];

	character = 0;
	if (data->debug)
		dump_state("aff", data, champ);
	if (champ->argstype[0] != REG_CODE)
	{
		if ((data->verbose & 32) == 32)
			ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-2);
	}
	character = (int)champ->reg[champ->args[0]] % 256;
	color_champion(champ->number, color);
	verbose_aff(data, champ, color);
	if (data->aff)
		ft_printf("%s%c"RESET, color, (char)(champ->reg[champ->args[0]]));
	return (1);
}
