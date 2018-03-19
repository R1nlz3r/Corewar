/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:03:12 by dwald             #+#    #+#             */
/*   Updated: 2018/03/19 13:03:08 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Create a new process that will inherit the different states of its father,
** except its PC, which will be put at (PC + (1st parameter % IDX_MOD)).
*/

/*Genere un nouveau processus a l'adresse passée en parametre par copie du processus appelant. Le nouveau processus garde donc l'etat de tout les registres et du carry, seul le PC differe ( sauf dans le cas d'un fork %0 ).*/

static	void	copy_champion(t_champion *child, t_champion *parent, int pc_dest)
{
	int i;

	i = -1;
	child->lastLive = parent->lastLive;
	child->carry = parent->carry;
//	child->liveNbr;
	child->ipc = pc_dest;
	child->pc = find_pc_node(parent, pc_dest);
	ft_strncpy(child->name, parent->name, COMMENT_LENGTH + 1);
	child->wait = parent->wait;
	child->alive = parent->alive;
	child->number = parent->number;
	child->nextOp = parent->nextOp;
//	child->op = parent->op;
	child->size = parent->size;
//	child->code = strncpy(child->code, parent->code, MEM_SIZE);
	ft_strncpy(child->comment,parent->comment,COMMENT_LENGTH + 1);
	while (++i <= REG_NUMBER + 1)
		child->reg[i] = parent->reg[i];
	i = -1;
	while (++i <= 3)
		child->argsType[i] = parent->argsType[i];
	return ;
}

int			corewar_fork(t_data *data, t_champion *champ)
{
	short		pc_dest;
	t_champion	*parent;
	t_champion	*child;
	
	if (champ->argsType[0] != DIR_CODE)
	{
		//change to ft_dprintf
		ft_printf("ERROR: Process %i tries to read instruction's parameter \
with no valid argument type\n", champ->number);
		return (-1);
	}
	pc_dest = mem_mod(champ->ipc + (champ->args[0] % IDX_MOD)); //remove % for lfork
	if (prepare_champion(data, champ->filename, champ->number, true) == -1)
		return (-1);
	//copy_champion
	parent = champ;
	while (parent)
		parent = parent->next;
	child = parent;
	parent = champ;
	copy_champion(child, parent, pc_dest);
	return (1);
}
