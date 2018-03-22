/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_next_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:53:03 by cyrillef          #+#    #+#             */
/*   Updated: 2018/03/22 11:47:50 by cyrillefrouin    ###   ########.fr       */
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
		champion->argsType[0] = champion->op.param_types[0];
		return ;
	}
	node = champion->pc->next;
	byte = node->contentn;
	while (i++ < 4)
		byte = byte >> 2;
	i = champion->op.nb_params - 1;
	while (i >= 0)
	{
		champion->argsType[i] = byte & 0b11;
		byte = byte >> 2;
		i--;
	}
}

static void		get_one_param(t_champion *champion, int argsize, int n, int *pos)
{
	int			i;
	int			nb;
	t_node		*node;

	// i = 0;
	// if (len == DIR && g_op_tab[player->next_op].has_idx == 1)
	// 	len = 2;
	// tmp = T_LAB - len;
	// while (i < len)
	// {
	// 	arg = ((player->pc) + *index + 1 + g_op_tab[player->next_op].has_pcode);
	// 	player->op_args[arg_nbr][tmp] = ft_hex2intdec(arg->hex);
	// 	(*index)++;
	// 	tmp++;
	// 	i++;
	// }
	i = -1;
	nb = 0;
	node = champion->pc;
	while (++i < *pos)
		node = node->next;
	if (champion->argsType[n] == DIR_CODE && champion->op.has_idx == 0)
		argsize = 4;
	i = -1;
	while (++i < argsize)
	{
		nb += (node->contentn << ((argsize - (i + 1)) * 8));
		ft_printf("%s %d/%d : %d\n", node->content, i, argsize, nb);
		node = node->next;
	}
	*pos += i;
	champion->args[n] = nb;
}

static void		get_params(t_champion *champion)
{
	int			i;
	int			pos;
	int			argsize;

	i = 0;
	pos = 2;
	if (champion->op.nb_params == 1 && champion->op.param_types[0] == 2)
		pos = 1;
	while (i < champion->op.nb_params)
	{
		if (champion->argsType[i] == REG_CODE)
			argsize = REG_SIZE;
		else if (champion->argsType[i] == DIR_CODE)
			argsize = DIR_SIZE;
		else if (champion->argsType[i] == IND_CODE)
			argsize = IND_SIZE;
		get_one_param(champion, argsize, i, &pos);
		i++;
	}
	if (champion->op.opcode == 1)
	{
		pos = 4;
	}
	else if (champion->op.opcode == 9)
	{
		pos = 3;
	}
	champion->ipc += pos;
	i = 0;
	while (i++ < pos)
		champion->pc = champion->pc->next;
}

int				do_next_op(t_data *data)
{
	t_champion	*champion;

	champion = data->champions;
	while (champion->next != NULL)
		champion = champion->next;
	while (champion != NULL)
	{
		ft_printf(GREEN"%d - pc : %d\n"RESET, data->cycle, champion->pc->id);
		if (champion->nextOp == 0)
		{
			champion->oldpc = champion->pc;
			champion->oldipc = champion->ipc;
			get_params_type(champion);
			get_params(champion);
			champion->op.func(data, champion);
		}
		champion = champion->prev;
	}
	return (1);
}
