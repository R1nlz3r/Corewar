/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:40:32 by cfrouin           #+#    #+#             */
/*   Updated: 2018/04/21 09:16:38 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		display(t_data *data)
{
	int		i;

	if (data->graph == 1
		&& data->speed > 0 && !(data->cycle % data->speed))
		display_map(data);
	else if (data->graph == 1 && data->speed < 0)
	{
		i = data->speed;
		while (i++)
		{
			if (i < data->speed && data->speed < 0)
				i = data->speed;
			else if (data->speed > 0)
				break ;
			display_map(data);
			key_hub(data);
		}
	}
}

static int		vm_loop(t_data *data)
{
	if (data->graph == 1)
		key_hub(data);
	if (data->pause == 1 && data->graph == 1)
		display(data);
	if (data->pause != 1)
	{
		if ((data->verbose & 2) == 2)
			ft_printf(GREEN"CYCLE %d\n"RESET, data->cycle);
		prepare_next_op(data);
		if (do_next_op(data) == -1)
			return (-1);
		if (data->dump != -1 &&
			(data->dump == 0 || data->cycle % data->dump == 0))
			dump(data);
		data->cycle++;
		display(data);
		if (check_live(data) == 1)
			return (1);
	}
	return (0);
}

int				vm_start(t_data *data)
{
	int			ret;

	if (data->graph == 1)
		display_map(data);
	while (1)
	{
		ret = vm_loop(data);
		if (ret == -1)
			return (-1);
		else if (ret == 1)
			return (1);
	}
	return (1);
}
