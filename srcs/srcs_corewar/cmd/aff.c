/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:21:27 by dwald             #+#    #+#             */
/*   Updated: 2018/02/28 16:16:24 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Aff takes a register and displays the character the ASCII code of which is
** contained in the register. (a modulo 256 is applied to this ascii code,
** the character is displayed on the standard output). If register char
** representation is 'nul' then carry is modified to 1, otherwise 0.
*/

int		corewar_aff(t_data *data, t_champion *champ)
{
	int	character;

	(void)data;
	character = 0;
	if (champ->argsType[0] != REG_CODE)
		return (-1);
	if ((char)(champ->reg[champ->args[0]]) == 0)
		champ->carry = 1;
	else
	{
		champ->carry = 0;
		character = (int)champ->reg[champ->args[0]] % 256;
//ambiguity: modulo of variable cast in char or modulo of an int?
	}
	ft_printf("champion %d: aff %c\n",
	champ->number, (char)(champ->reg[champ->args[0]]));
	return (1);
}
