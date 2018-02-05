/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:46:06 by dwald             #+#    #+#             */
/*   Updated: 2018/02/05 12:19:55 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_zjmp(t_data *data, t_champion *champ)
{
	short	dest_address;
	t_node	tmp;

	tmp = champ->pc;
	if (champ->argsType[0] != 2)
		return (-1);
	if (champ->carry == 1)
	{
		dest_address = champ->args[0] + ipc;
		while (tmp->ipc != dest_address)
			tmp = tmp->next;
		champ->pc = tmp;
	}
	return (1);
}
