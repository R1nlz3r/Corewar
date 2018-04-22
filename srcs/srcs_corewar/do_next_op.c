/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_next_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:53:03 by cyrillef          #+#    #+#             */
/*   Updated: 2018/04/21 09:34:07 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		check_regs(t_champion *champ)
{
	int			i;

	i = 0;
	while (i < champ->op.nb_params)
	{
		if (champ->op.param_types[i] == REG_CODE)
		{
			if (champ->args[i] <= 0 || champ->args[i] > 16)
				return (-1);
		}
		i++;
	}
	return (1);
}

static void		verbose_adv(t_data *data, t_champion *champion)
{
	int			diff;
	int			i;
	t_node		*tmp;

	diff = champion->pc->id - champion->oldpc->id;
	if ((data->verbose & 16) == 16)
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x) ",
			diff, champion->oldpc->id, champion->pc->id);
		i = -1;
		tmp = champion->oldpc;
		while (++i < diff)
		{
			ft_printf("%s ", tmp->content);
			tmp = tmp->next;
		}
		ft_printf("\n");
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
		if (champion->nextop == 0)
		{
			champion->oldpc = champion->pc;
			get_params(champion);
			verbose_adv(data, champion);
			if (check_regs(champion) == -1)
			{
				champion = champion->prev;
				continue ;
			}
			if (champion->op.func(data, champion) == -1)
				return (-1);
			if (data->debug)
				dump_state(NULL, data, champion);
		}
		champion = champion->prev;
	}
	return (1);
}
