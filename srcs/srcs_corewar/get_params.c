/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 20:04:07 by cfrouin           #+#    #+#             */
/*   Updated: 2018/04/20 20:13:52 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_params_type(t_champion *champion)
{
	t_node		*node;
	char		byte;
	int			i;

	i = champion->op.nb_params;
	if (i == 1)
	{
		champion->argstype[0] = champion->op.param_types[0];
		return ;
	}
	node = champion->pc->next;
	byte = node->contentn;
	while (i++ < 4)
		byte = byte >> 2;
	i = champion->op.nb_params - 1;
	while (i >= 0)
	{
		champion->argstype[i] = byte & 0b11;
		byte = byte >> 2;
		i--;
	}
}

static void		get_one_param(t_champion *champion,
								int argsize, int n, int *pos)
{
	int			i;
	int			nb;
	t_node		*node;

	i = -1;
	nb = 0;
	node = champion->pc;
	while (++i < *pos)
		node = node->next;
	if (champion->argstype[n] == DIR_CODE && champion->op.has_idx == 0)
		argsize = 4;
	i = -1;
	while (++i < argsize)
	{
		nb += (node->contentn << ((argsize - (i + 1)) * 8));
		node = node->next;
	}
	*pos += i;
	champion->args[n] = nb;
}

void			get_params(t_champion *champion)
{
	t_pos		var;
	int			argsize;

	get_params_type(champion);
	var.x = -1;
	var.y = 2;
	if (champion->op.nb_params == 1 && champion->op.param_types[0] == 2)
		var.y = 1;
	while (++var.x < champion->op.nb_params)
	{
		argsize = 0;
		if (champion->argstype[var.x] == REG_CODE)
			argsize = REG_SIZE;
		else if (champion->argstype[var.x] == DIR_CODE)
			argsize = DIR_SIZE;
		else if (champion->argstype[var.x] == IND_CODE)
			argsize = IND_SIZE;
		get_one_param(champion, argsize, var.x, &var.y);
	}
	if (((var.x = -1) == -1) && champion->op.opcode == 1)
		var.y = 5;
	else if (champion->op.opcode == 9 || champion->op.opcode == 12)
		var.y = 3;
	while (++var.x < var.y)
		champion->pc = champion->pc->next;
}
