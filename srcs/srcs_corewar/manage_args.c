/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 19:11:40 by cfrouin           #+#    #+#             */
/*   Updated: 2018/04/21 12:27:53 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int			manage_args3(t_data *data, char **av, int *i)
{
	if (ft_strcmp(av[*i], "-debug") == 0)
	{
		data->debug = 1;
		return (1);
	}
	else if (ft_strcmp(av[*i], "-stealth") == 0)
	{
		data->stealth = 1;
		return (1);
	}
	else if (prepare_champion(data, av[*i], -512, 0) == -1)
		return (-1);
	return (1);
}

static int			manage_args2(t_data *data, int ac, char **av, int *i)
{
	if (ft_strcmp(av[*i], "-n") == 0)
	{
		if (*i + 2 >= ac || !ft_isnumber(av[*i + 1]))
			return (-1);
		if (prepare_champion(data, av[*i + 2], ft_atoi(av[*i + 1]), 0) == -1)
			return (-1);
		*i += 2;
		return (1);
	}
	else if (ft_strcmp(av[*i], "-v") == 0)
	{
		if (*i + 1 >= ac || !ft_isnumber(av[*i + 1]))
			return (-1);
		data->verbose = ft_atoi(av[*i + 1]);
		*i += 1;
		return (1);
	}
	else if (ft_strcmp(av[*i], "-g") == 0)
	{
		data->graph = 1;
		return (1);
	}
	if (manage_args3(data, av, i) == 1)
		return (1);
	return (-1);
}

int					manage_args(t_data *data, int ac, char **av)
{
	int				i;

	i = 0;
	data->stealth = 0;
	data->graph = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-dump") == 0)
		{
			if (i + 1 >= ac || !ft_isnumber(av[i + 1]))
				return (-1);
			data->dump = ft_atoi(av[i++ + 1]);
			continue ;
		}
		if (manage_args2(data, ac, av, &i) == 1)
			continue ;
		return (-1);
	}
	if (data->graph == 1 && data->dump != -1)
		return (-1);
	return (1);
}
