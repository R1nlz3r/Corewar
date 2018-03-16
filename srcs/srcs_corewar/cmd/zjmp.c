/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:46:06 by dwald             #+#    #+#             */
/*   Updated: 2018/03/16 16:29:25 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		corewar_zjmp(t_data *data, t_champion *champ)
{
	short	pc_dest;
	t_node	*tmp;

	(void)data;
	tmp = champ->pc;
	// Display tests
	if (data->debug)
		dump_state("ZJUMP", data, champ);
	// End of tests
	if (champ->argsType[0] != DIR_CODE)
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-1);
	}
	if (champ->carry == 1)
	{
		pc_dest = champ->args[0] + champ->ipc;
		while (champ->ipc < pc_dest--)
			tmp = tmp->next;
//assigning new node pointer (memory emplacement in VM's RAM)
		champ->pc = tmp;
//changing PC accordingly
		champ->ipc = champ->args[0] + champ->ipc;
		printf("champ->ipc = %d", champ->ipc);
	}
	return (1);
}
