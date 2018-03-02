/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:32:14 by dwald             #+#    #+#             */
/*   Updated: 2018/02/26 15:08:07 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Take a random argument and a registry. Load the value of the first argument
** in the registry. Change the carry.
*/

/* Transfert direct RAM > Registre. Charge le premier parametre dans le registre passé en second parametre. Si la valeur du premier parametre est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.*/

int		corewar_ld(t_data *data, t_champion *champ)
{
	t_node	*tmp;
	short	pc_dest;

	(void)data;
	tmp = champ->pc;
	if ((champ->argsType[0] != T_DIR && champ->argsType[0] != T_IND)
	|| champ->argsType[1] != T_REG)
		return (-1);
	if (champ->argsType[0] == T_DIR)
		champ->reg[champ->args[1]] = champ->args[0];
	else if (champ->argsType[0] == T_IND)
	{
		pc_dest = champ->ipc + (champ->args[0] % IDX_MOD); // remove % for lld 
		while (champ->ipc < pc_dest--)
			tmp = tmp->next;
		champ->reg[champ->args[1]] = (int)tmp->contentn;
	}
	champ->carry = (champ->args[0] == 0) ? 1 : 0;
	return (1);
}
