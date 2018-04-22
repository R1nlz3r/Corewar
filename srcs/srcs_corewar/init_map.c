/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:12:24 by cyrillef          #+#    #+#             */
/*   Updated: 2018/04/20 19:34:27 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				write_player(t_data *data, t_champion *champion, size_t pos)
{
	t_node		*map;
	size_t		i;

	i = 0;
	map = data->map;
	while (i++ < pos)
		map = map->next;
	champion->pc = map;
	i = 0;
	while (i < champion->size)
	{
		map->player = champion->number;
		map->content[0] = champion->code[(i * 3)];
		map->content[1] = champion->code[(i * 3) + 1];
		map->content[2] = 0;
		map->contentn = str_hex_to_number(map->content);
		i++;
		map = map->next;
	}
	return (1);
}

static void		add_node(t_data *data, t_node *new, t_node *node)
{
	if (data->map == NULL)
	{
		new->prev = new;
		new->next = new;
		data->map = new;
	}
	else
	{
		new->prev = node;
		new->next = data->map;
		data->map->prev = new;
		node->next = new;
	}
}

static int		create_map(t_data *data)
{
	int			i;
	t_node		*new;
	t_node		*node;

	i = 0;
	new = NULL;
	node = NULL;
	if (data->map != NULL)
		node = data->map;
	while (i < MEM_SIZE)
	{
		if ((new = malloc(sizeof(t_node))) == NULL)
			return (-1);
		new->player = -1;
		if (node != NULL)
		{
			node->next = NULL;
			node->prev = NULL;
		}
		new->id = i;
		add_node(data, new, node);
		node = new;
		i++;
	}
	return (1);
}

int				init_map(t_data *data)
{
	int			i;
	t_champion	*tmp;

	i = 0;
	if (create_map(data) == -1)
		return (-1);
	tmp = data->champions;
	while (i < data->nb_champion)
	{
		if (write_player(data, tmp, (MEM_SIZE / data->nb_champion) * i) == -1)
			return (-1);
		ft_printf("%d - %s player entered the game\n", tmp->number, tmp->name);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
