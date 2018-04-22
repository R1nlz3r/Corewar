/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:03:12 by dwald             #+#    #+#             */
/*   Updated: 2018/04/20 20:50:05 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Create a new process that will inherit the different states of its father,
** except its PC, which will be put at (PC + (1st parameter % IDX_MOD)).
*/

static	void	verbose_fork(t_data *data, t_champion *champ, t_champion *child)
{
	char	color[7];

	if ((data->verbose & 4) == 4)
	{
		color_champion(champ->number, color);
		ft_printf("%sPlayer #%i | fork %d (%d)\n"RESET, color, champ->number,
		get_address(champ->args[0]), child->pc->id);
	}
	return ;
}

static	void	copy_champ(t_champion *child, t_champion *parent, int pc_dest)
{
	int i;

	i = -1;
	child->carry = parent->carry;
	child->pc = find_pc_node(parent, pc_dest);
	child->alive = parent->alive;
	child->nextop = -1;
	child->size = parent->size;
	ft_strncpy(child->name, parent->name, PROG_NAME_LENGTH);
	ft_strncpy((char*)child->code, (const char*)parent->code, MEM_SIZE);
	ft_strncpy(child->comment, parent->comment, COMMENT_LENGTH + 1);
	while (++i <= REG_NUMBER + 1)
		child->reg[i] = parent->reg[i];
	return ;
}

int				corewar_fork(t_data *data, t_champion *champ)
{
	short		pc_dest;
	t_champion	*child;

	if (data->debug)
		dump_state("fork", data, champ);
	if (champ->argstype[0] != DIR_CODE)
	{
		if ((data->verbose & 32) == 32)
			ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-2);
	}
	pc_dest = mem_mod(champ->oldpc->id + idx_address(champ->args[0]));
	if (prepare_champion(data, champ->filename, champ->number, true) == -1)
		return (-1);
	child = data->champions;
	while (child->next != NULL)
		child = child->next;
	copy_champ(child, champ, pc_dest);
	verbose_fork(data, champ, child);
	return (1);
}
