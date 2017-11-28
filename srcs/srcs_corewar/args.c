/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:26:10 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/28 13:48:50 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		new_champion(t_data *data, char *filename, int number)
{
	t_champion	*tmp;
	t_champion	*new;

	tmp = data->champions;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if ((new = malloc(sizeof(t_champion))) == NULL)
		return (-1);
	if ((new->filename = strdup(filename)) == NULL)
	{
		free(new);
		return (-1);
	}
	new->number = number;
	if (data->champions == NULL)
		data->champions = new;
	else
		tmp->next = new;
	return (1);
}

static int		get_new_number(t_data *data)
{
	int			nbr;
	int			flag;
	t_champion	*tmp;

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

static int		prepare_champion(t_data *data, char *filename, int number)
{
	t_champion	*tmp;

	if (number == -512)
		number = get_new_number(data);
	tmp = data->champions;
	while (tmp)
	{
		if (tmp->number == number)
			return (-1);
		tmp = tmp->next;
	}
	if (new_champion(data, filename, number) == -1)
		return (-1);
	return (1);
}

static int		manage_args(t_data *data, int ac, char **av)
{
	int			i;

	i = 0;
	while (++i < ac)
	{
		if (strcmp(av[i], "-dump") == 0)
		{
			if (i + 1 >= ac || !ft_isnumber(av[i + 1]))
				return (-1);
			data->dump = ft_atoi(av[i + 1]);
			i++;
		}
		else if (strcmp(av[i], "-n") == 0)
		{
			if (i + 2 >= ac || !ft_isnumber(av[i + 1]))
				return (-1);
			if (prepare_champion(data, av[i + 2], ft_atoi(av[i + 1])) == -1)
				return (-1);
			i += 2;
		}
		else if (prepare_champion(data, av[i], -512) == -1)
			return (-1);
	}
	return (1);
}

t_data			*init_data(int ac, char **av)
{
	t_data		*data;

	if ((data = malloc(sizeof(t_data))) == NULL)
		return (NULL);
	data->champions = NULL;
	if (manage_args(data, ac, av) == -1)
	{
		free(data);
		return (NULL);
	}
	return (data);
}
