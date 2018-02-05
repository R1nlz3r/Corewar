/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:53:45 by dwald             #+#    #+#             */
/*   Updated: 2018/02/05 17:00:03 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Takes a registry and a registry or an indirect and store the value of 
** the registry toward a second argument. For example, st r1, 42 store 
** the value of r1 at the address (PC + (42 % IDX_MOD))
*/

/*
** Transfert direct Registre > RAM / Registre. Charge le contenu du registre passé en premier parametre dans le second parametre. Si la valeur du premier parametre est egale a zero, alors le carry passe a l'etat un, sinon a l'etat zero.
*/

int		corewar_st(t_data *data, t_champion *champ)
{
	t_node	tmp;

	tmp = champ->pc;
	if (champ->argType[0] != T_REG || (champ->argType[1] != T_IND
	&& champ->argType[1] != T_REG))
		return (-1);
	if (champ->argType[1] == T_REG)
		champ->reg[args[1]] = champ->reg[args[0]];
	else if (champs->argType[1] == T_IND)
	{
		while (tmp->ipc != (champs->arg[0] + (42 % IDX_MOD)))
			tmp = tmp->next;
		tmp->contentn ///??? = champ->reg[args[1]];
	}
	champ->carry = (champ->args[0] == 0) ? 1 : 0;
	return (1);
}
