/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:59:24 by cfrouin           #+#    #+#             */
/*   Updated: 2018/02/08 17:49:50 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Apply an ^ (bit-to-bit XOR) over the first two arguments and store the result
** in a registry, which is the third argument. Modifies the carry.
*/

int		corewar_xor(t_data *data, t_champion *champ)
{
	if (champ->argsType[0] != T_REG || champ->argsType[1] != T_REG
	|| champ->argsType[2] != T_REG)
		return (-1);
	champ->reg[champ->args[2]] = champ->reg[champ->args[0]]
	^ champ->reg[champ->args[1]];
	champ->carry = (champ->reg[champ->args[2]] == 0) ? 1 : 0;
	return (1);
}
