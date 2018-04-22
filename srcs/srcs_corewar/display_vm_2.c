/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_vm_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:28:05 by mapandel          #+#    #+#             */
/*   Updated: 2018/04/20 22:38:43 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	update_livebreakdown(t_data *data)
{
	int		sum;
	int		i;
	int		j;

	sum = 0;
	ft_printf("\033[%d;201H\033[90m", (data->nb_player - 1) * 3 + 17 + (i = 0));
	while (i++ < data->nb_player)
		sum += get_sum_livenbr(data, i);
	if (!(i = 0) && !sum)
		ft_putstr("--------------------------------------------------");
	if (!sum)
		return ;
	while (i++ < data->nb_player)
	{
		if (!(j = 0) && i == 1)
			ft_putstr("\033[1;32m");
		else if (i == 2)
			ft_putstr("\033[1;34m");
		else if (i == 3)
			ft_putstr("\033[1;31m");
		else if (i == 4)
			ft_putstr("\033[1;36m");
		while (j++ < (get_sum_livenbr(data, i) * 50) / sum)
			ft_putchar('-');
	}
}

void		update_legend(t_data *data)
{
	t_champion	*tmp;
	int			i;

	tmp = data->champions;
	i = 0;
	if (data->pause)
		ft_putstr("\033[0;97m\033[3;200H** PAUSED ** ");
	else
		ft_putstr("\033[0;97m\033[3;200H** RUNNING **");
	ft_printf("\033[5;208H%dx%-10", data->speed);
	ft_putstr("\033[8;208H");
	ft_putnbr(data->cycle);
	while (i < data->nb_player)
	{
		ft_printf("\033[%d;228H%7d", i * 3 + 13, get_sum_livenbr(data, i + 1));
		++i;
		tmp = tmp->next;
	}
	update_livebreakdown(data);
	ft_printf("\033[0;97m\033[%d;215H%-37d", (data->nb_player - 1) * 3 + 22,
		data->cycletodie);
}

static void	update_map_2(t_data *data, t_node *node)
{
	number_to_hex_str(node->contentn, (unsigned char(*)[])&(node->content));
	if (!(data->stealth))
		ft_putstr(node->content);
	else
		ft_putstr("ff");
}

void		update_map(t_data *data)
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
			ft_putstr(" \033[90m");
		update_map_2(data, node);
		if ((node = node->next) && node == data->map)
			break ;
	}
	ft_putstr("\033[0m");
}
