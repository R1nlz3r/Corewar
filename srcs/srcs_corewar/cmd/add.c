/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:57:25 by dwald             #+#    #+#             */
/*   Updated: 2018/02/26 15:05:00 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Take three registries, add the first two, and place the result in the third,
** right before modifying the carry.
** T_REG param[2] = T_REG param[0] + T_REG param[1]
*/

int		corewar_add(t_data *data, t_champion *champ)
{
	(void)data;
	if (champ->argsType[0] != T_REG || champ->argsType[1] != T_REG
	|| champ->argsType[2] != T_REG)
		return (-1);
	champ->reg[champ->args[0]] = champ->reg[champ->args[1]]
	+ champ->reg[champ->args[2]];
	champ->carry = (champ->args[0] == 0) ? 1 : 0;
	return (1);
}
