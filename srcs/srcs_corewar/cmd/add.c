/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:57:25 by dwald             #+#    #+#             */
/*   Updated: 2018/04/20 19:17:31 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Take three registries, add the first two, and place the result in the third,
** right before modifying the carry.
** REG_CODE param[2] = REG_CODE param[0] + REG_CODE param[1]
*/

static	void	verbose_add(t_data *data, t_champion *champ)
{
	char	color[7];

	if ((data->verbose & 4) == 4)
	{
		color_champion(champ->number, color);
		ft_printf("%sPlayer #%i | add r%d + r%d = (%d) -> r%d, carry = %d\n"
		RESET, color, champ->number, champ->args[0], champ->args[1],
		champ->reg[champ->args[2]], champ->args[2], champ->carry);
	}
	return ;
}

int				corewar_add(t_data *data, t_champion *champ)
{
	if (data->debug)
		dump_state("add", data, champ);
	if (champ->argstype[0] != REG_CODE || champ->argstype[1] != REG_CODE
	|| champ->argstype[2] != REG_CODE)
	{
		if ((data->verbose & 32) == 32)
			ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-2);
	}
	champ->reg[champ->args[2]] = champ->reg[champ->args[0]]
	+ champ->reg[champ->args[1]];
	champ->carry = (champ->reg[champ->args[2]] == 0) ? 1 : 0;
	verbose_add(data, champ);
	return (1);
}
