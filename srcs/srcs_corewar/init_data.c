/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:26:10 by cyrillef          #+#    #+#             */
/*   Updated: 2018/04/21 11:45:46 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			new_champion(t_data *data, char *filename, int number)
{
	t_champion		*tmp;
	t_champion		*new;

	tmp = data->champions;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((new = malloc(sizeof(t_champion))) == NULL)
		return (-1);
	new->prev = NULL;
	new->next = NULL;
	new->alive = true;
	if ((new->filename = ft_strdup(filename)) == NULL)
	{
		free(new);
		return (-1);
	}
	new->carry = 0;
	new->number = number;
	new->reg[1] = -number;
	if (data->champions == NULL)
		data->champions = new;
	else
		tmp->next = new;
	new->prev = tmp;
	return (1);
}

static int			get_new_number(t_data *data)
{
	unsigned int	nbr;
	int				flag;
	t_champion		*tmp;

	nbr = 1;
	flag = 1;
	while (flag)
	{
		flag = 0;
		tmp = data->champions;
		while (tmp)
		{
			if (tmp->number == nbr)
			{
				flag = 1;
				nbr++;
			}
			tmp = tmp->next;
		}
	}
	return (nbr);
}

int					prepare_champion(t_data *data, char *filename,
									int number, bool isfork)
{
	t_champion		*tmp;

	if (number == -512)
		number = get_new_number(data);
	tmp = data->champions;
	while (tmp)
	{
		if ((isfork == false) && tmp->number == (unsigned int)number)
			return (-1);
		tmp = tmp->next;
	}
	if (new_champion(data, filename, number) == -1)
	{
		ft_printf(RED"NEW CHAMPION FAILED\n"RESET);
		return (-1);
	}
	if (isfork == false)
		data->nb_player++;
	data->nb_champion++;
	return (1);
}

t_data				*init_data(int ac, char **av)
{
	t_data			*data;

	if (ac == 1)
		usage();
	if ((data = malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->verbose = 0;
	data->debug = 0;
	data->map = NULL;
	data->dump = -1;
	data->champions = NULL;
	data->nb_player = 0;
	data->nb_champion = 0;
	data->cycle = 1;
	data->cycletodie = CYCLE_TO_DIE;
	data->live = 0;
	data->speed = 1;
	if (manage_args(data, ac, av) == -1)
	{
		free(data);
		return (NULL);
	}
	data->pause = ((data->graph == 1) ? 1 : 0);
	data->map = NULL;
	return (data);
}
