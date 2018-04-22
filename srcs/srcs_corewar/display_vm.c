/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_vm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 20:04:16 by mapandel          #+#    #+#             */
/*   Updated: 2018/04/20 22:38:44 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				get_sum_livenbr(t_data *data, unsigned int id)
{
	t_champion	*tmp;
	int			sum;
	int			i;

	tmp = data->champions;
	sum = 0;
	i = 0;
	while (i++ < data->nb_champion)
	{
		if (tmp->number == id)
			sum += tmp->livenbr;
		tmp = tmp->next;
	}
	return (sum);
}

static void		init_legend_2(t_data *data)
{
	ft_printf("\033[%d;200H", (data->nb_player - 1) * 3 + 16);
	ft_putstr("Live breakdown for current period :");
	ft_printf("\033[%d;200H\033[90m", (data->nb_player - 1) * 3 + 17);
	ft_putstr("\033[90m[--------------------------------------------------]");
	ft_printf("\033[%d;200H\033[0;97m", (data->nb_player - 1) * 3 + 22);
	ft_putstr("CYCLE_TO_DIE :");
	ft_printf("\033[%d;200HCYCLE_DELTA : %d",
		(data->nb_player - 1) * 3 + 24, CYCLE_DELTA);
	ft_printf("\033[%d;200HNBR_LIVE : %d",
		(data->nb_player - 1) * 3 + 26, NBR_LIVE);
	ft_printf("\033[%d;200HMAX_CHECKS : %d",
		(data->nb_player - 1) * 3 + 28, MAX_CHECKS);
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
	while (i < data->nb_player)
	{
		ft_printf("\033[%d;200HPlayer -%d : ", i * 3 + 12, tmp->number);
		if (tmp->number == 1)
			ft_putstr("\033[1;32m");
		else if (tmp->number == 2)
			ft_putstr("\033[1;34m");
		else if (tmp->number == 3)
			ft_putstr("\033[1;31m");
		else if (tmp->number == 4)
			ft_putstr("\033[1;36m");
		ft_putstr(tmp->name);
		ft_putstr("\033[0;97m");
		ft_printf("\033[%d;202HLives in current period :", i++ * 3 + 13);
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
