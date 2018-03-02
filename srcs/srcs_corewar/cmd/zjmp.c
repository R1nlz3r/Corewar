/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:46:06 by dwald             #+#    #+#             */
/*   Updated: 2018/02/26 15:12:19 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_zjmp(t_data *data, t_champion *champ)
{
	short	pc_dest;
	t_node	*tmp;

	(void)data;
	tmp = champ->pc;
	if (champ->argsType[0] != T_DIR)
		return (-1);
	if (champ->carry == 1)
	{
		pc_dest = champ->args[0] + champ->ipc;
		while (champ->ipc < pc_dest--)
			tmp = tmp->next;
//assigning new node pointer (memory emplacement in VM's RAM)
		champ->pc = tmp;
//changing PC accordingly
		champ->ipc = champ->args[0] + champ->ipc;
	}
	return (1);
}
