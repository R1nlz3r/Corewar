/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:43:56 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/24 15:44:09 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		free_champions(t_champion *list)
{
	t_champion	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp->filename);
		free(tmp);
	}
}

static void		free_map(t_node *list)
{
	t_node		*tmp;

	list->prev->next = NULL;
	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void			corewar_error(t_data *data, char *error)
{
	if (data != NULL)
	{
		free_champions(data->champions);
		free_map(data->map);
	}
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd(RESET, 2);
	exit(EXIT_FAILURE);
}
