/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:04:16 by mapandel          #+#    #+#             */
/*   Updated: 2018/03/07 17:27:15 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		update_map(t_data *data)
{
	t_node		*node;
	int			line;

	node = data->map;
	line = 1;
	while (1)
	{
		if (!(node->id % 64))
			ft_printf("\033[%d;3H", line++ + 2);
		if (node->player == 1)
			ft_putstr(" \033[32m");
		else if (node->player == 2)
			ft_putstr(" \033[34m");
		else if (node->player == 3)
			ft_putstr(" \033[31m");
		else if (node->player == 4)
			ft_putstr(" \033[36m");
		else
			ft_putstr(" \033[90m00");
		if (node->player != -1)
			ft_putstr(ft_strtolower(node->content));
		if ((node = node->next) && node == data->map)
			break ;
	}
	ft_putstr("\033[0m");
}

static void		init_legend_2(t_data *data)
{
	ft_printf("\033[%d;200H", (data->nb_champion - 1) * 4 + 16);
	ft_putstr("Live breakdown for current period :");
	ft_printf("\033[%d;200H\033[90m", (data->nb_champion - 1) * 4 + 17);
	ft_putstr("[--------------------------------------------------]");
	ft_printf("\033[%d;200H\033[0;97m", (data->nb_champion - 1) * 4 + 19);
	ft_putstr("Live breakdown for last period :");
	ft_printf("\033[%d;200H\033[90m", (data->nb_champion - 1) * 4 + 20);
	ft_putstr("[--------------------------------------------------]");
	ft_printf("\033[%d;200H\033[0;97m", (data->nb_champion - 1) * 4 + 22);
	ft_putstr("CYCLE_TO_DIE :");
	ft_printf("\033[%d;200HCYCLE_DELTA : %d",
		(data->nb_champion - 1) * 4 + 24, CYCLE_DELTA);
	ft_printf("\033[%d;200HNBR_LIVE : %d",
		(data->nb_champion - 1) * 4 + 26, NBR_LIVE);
	ft_printf("\033[%d;200HMAX_CHECKS : %d",
		(data->nb_champion - 1) * 4 + 28, MAX_CHECKS);
	ft_putstr("\033[62;200HKeys :\033[63;202HQ     - Quit");
	ft_putstr("\033[64;202HSpace - Pause / Resume");
	ft_putstr("\033[65;202HA     - Speed up");
	ft_putstr("\033[66;202HD     - Speed down");
}

static void		init_legend(t_data *data)
{
	t_champion	*tmp;
	int			i;

	tmp = data->champions;
	i = 0;
	ft_putstr("\033[0;97m\033[5;200HSpeed :");
	ft_putstr("\033[8;200HCycle :");
	ft_putstr("\033[10;200HProcesses :");
	while (i < data->nb_champion)
	{
		ft_printf("\033[%d;200HPlayer -%d : ", i * 4 + 12, i + 1);
		if (tmp->number == 1)
			ft_putstr("\033[1;32m");
		else if (tmp->number == 2)
			ft_putstr("\033[1;34m");
		else if (tmp->number == 3)
			ft_putstr("\033[1;31m");
		else if (tmp->number == 4)
			ft_putstr("\033[1;36m");
		ft_putstr(tmp->name);
		ft_printf("\033[0;97m\033[%d;202HLast live :", i * 4 + 13);
		ft_printf("\033[%d;202HLives in current period :", i++ * 4 + 14);
		tmp = tmp->next;
	}
	init_legend_2(data);
}

static void		init_display(t_data *data)
{
	int		i;

	ft_putstr("\033[2J\e[?25l");
	ft_putstr("\033[H");
	ft_putstr("\033[100m");
	i = 0;
	while (i++ < 254)
		ft_printf("\033[0;%dH \033[68;%dH ", i, i);
	i = 0;
	while (i++ < 68)
		ft_printf("\033[%d;0H \033[%d;197H \033[%d;254H ", i, i, i);
	ft_putstr("\033[0m");
	init_legend(data);
}

void			display_map(t_data *data)
{
	static int		init = 0;

	if (!init && (init = 1))
		init_display(data);
	update_map(data);
	update_legend(data);
}
