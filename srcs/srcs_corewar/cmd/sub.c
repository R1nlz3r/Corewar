/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 15:47:26 by dwald             #+#    #+#             */
/*   Updated: 2018/02/01 15:54:19 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_sub(t_data *data, t_champion *champ)
{
	
	if (champ->argsType[0] != 1 || champ->argstType[1] != 1
	|| champ->argsType[2] != 1)
		return (-1);
	champ->args[3] = champ->args[1] - champ->args[2];
	champ->carry = (champ->args[3] == 0) ? 1 : 0;
	return (1);
}
