/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:47:26 by dwald             #+#    #+#             */
/*   Updated: 2018/02/06 15:43:41 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_sub(t_data *data, t_champion *champ)
{
	if (champ->argsType[0] != T_REG || champ->argsType[1] != T_REG
	|| champ->argsType[2] != T_REG)
		return (-1);
	champ->args[2] = champ->args[0] - champ->args[1];
	champ->carry = (champ->args[2] == 0) ? 1 : 0;
	return (1);
}
