/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:46:06 by dwald             #+#    #+#             */
/*   Updated: 2018/02/06 15:51:12 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_zjmp(t_data *data, t_champion *champ)
{
	short	pc_dest;
	t_node	*tmp;

	tmp = champ->pc;
	if (champ->argsType[0] != T_DIR)
		return (-1);
	if (champ->carry == 1)
	{
		pc_dest = champ->args[0] + champ->ipc;
		while (champ->ipc > pc_dest--)
			tmp = tmp->next;
		champ->pc = tmp;							//assigning new node pointer
		champ->ipc = champ->args[0] + champ->ipc;	//changing PC accordingly
	}
	return (1);
}
