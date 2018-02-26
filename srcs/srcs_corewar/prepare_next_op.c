/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_next_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 13:31:15 by cyrillef          #+#    #+#             */
/*   Updated: 2018/02/20 18:01:10 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_next_op(t_champion *champion, t_data *data)
{
	int			opn;
	int			i;

	i = 0;
	opn = champion->pc->contentn;
	while (i < 16)
	{
		if (g_op_tab[i].opcode == opn)
		{
			champion->op = g_op_tab[i];
			ft_printf("nb_cycles %d\n", (champion->op.nb_cycles));
ft_printf("\nchampion register reg[%d] = %o\n", 0, champion->reg[0]);
ft_printf("\nchampion register reg[%d] = %o\n", 0, champion->reg[1]);
			(g_op_tab[i].func)(data, champion);
			return (champion->op.nb_cycles);
		}
		i++;
	}
	return (-1);
}

int				prepare_next_op(t_data *data)
{
	t_champion	*champion;

	champion = data->champions;
	while (champion->next != NULL)
		champion = champion->next;
	while (champion != NULL)
	{
		if (champion->nextOp <= 0)
		{
			champion->nextOp = get_next_op(champion, data);
		}
		else
			champion->nextOp--;
		champion = champion->prev;
	}
	return (1);
}
