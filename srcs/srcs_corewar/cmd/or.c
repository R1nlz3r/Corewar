/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:59:46 by cfrouin           #+#    #+#             */
/*   Updated: 2018/02/26 15:09:11 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Apply an | (bit-to-bit OR) over the first two arguments and store the result
** in a registry, which is the third argument. Modifies the carry.
*/

int		corewar_or(t_data *data, t_champion *champ)
{
	(void)data;
	if (champ->argsType[0] != REG_CODE || champ->argsType[1] != REG_CODE
	|| champ->argsType[2] != REG_CODE)
		return (-1);
	champ->reg[champ->args[2]] = champ->reg[champ->args[0]]
	| champ->reg[champ->args[1]];
	champ->carry = (champ->reg[champ->args[2]] == 0) ? 1 : 0;
	return (1);
}
