/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:47:26 by dwald             #+#    #+#             */
/*   Updated: 2018/02/26 15:10:00 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_sub(t_data *data, t_champion *champ)
{
	(void)data;
	if (champ->argsType[0] != REG_CODE || champ->argsType[1] != REG_CODE
	|| champ->argsType[2] != REG_CODE)
		return (-1);
	champ->reg[champ->args[2]] = champ->reg[champ->args[0]]
	- champ->reg[champ->args[1]];
	champ->carry = (champ->reg[champ->args[2]] == 0) ? 1 : 0;
	return (1);
}
