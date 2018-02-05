/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:32:14 by dwald             #+#    #+#             */
/*   Updated: 2018/02/05 15:54:16 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Take a random argument and a registry. Load the value of the first argument
** in the registry. Its opcode is 10 in binary and it will change the carry.
*/

/* Transfert direct RAM > Registre. Charge le premier parametre dans le registre passé en second parametre. Si la valeur du premier parametre est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.*/

int		corewar_ld(t_data *data, t_champion *champ)
{
	t_node	tmp;

	tmp = champ->pc;
	if ((champ->argType[0] != T_DIR && champ->argType[0] != T_IND)
	|| champ->argType[1] != T_REG)
		return (-1);
	if (champ->argType[0] == T_DIR)
		champ->reg[args[1]] = champ->args[0];
	else if (champs->argType[0] == T_IND)
	{
		while (tmp->ipc != champs->arg[0])
			tmp = tmp->next;
		champ->reg[args[1]] = ; ///???
	}
	champ->carry = (champ->args[0] == 0) ? 1 : 0;
	return (1);
}
