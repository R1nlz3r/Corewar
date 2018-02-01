/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 14:57:35 by dwald             #+#    #+#             */
/*   Updated: 2018/02/01 14:57:37 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int					corewar_live(t_data *data, t_champion *champ)
{
	ft_putendl_fd("Player ", 1);
	ft_putendl_fd(champ->name, 1);
	ft_putendl_fd(" was reported alive\n", 1);
	champ->live = 1;
	data->live++;
	data->lastlive = champ->number;
	return (1);
}
