/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_next_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:53:03 by cyrillef          #+#    #+#             */
/*   Updated: 2018/02/07 10:57:58 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		get_params_type(t_champion *champion)
{
	t_node		*node;
	char		byte;
	int			i;

	i = champion->op.nb_params - 1;
	node = champion->pc->next;
	byte = node->contentn;
	while (i >= 0)
	{
		byte = byte >> 2;
		champion->argsType[i] = byte & 0b11;
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
	if (n == DIR_SIZE && champion->op.has_idx == 1)
		argsize = 2;
	i = -1;
	while (++i < argsize)
	{
		nb += (node->contentn << ((argsize - (i + 1)) * 8));
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
	pos = 0;
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
}

int				do_next_op(t_data *data)
{
	t_champion	*champion;

	champion = data->champions;
	while (champion->next != NULL)
		champion = champion->next;
	while (champion != NULL)
	{
		get_params_type(champion);
		get_params(champion);
		champion = champion->prev;
	}
	return (1);
}
