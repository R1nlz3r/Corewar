/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:13:29 by cfrouin           #+#    #+#             */
/*   Updated: 2018/03/13 17:25:15 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			dump_state(char *str, t_data *data, t_champion *champ)
{
	ft_printf(RED);
	if (str != NULL)
		ft_printf("%s\n", str);
	if (data != NULL)
		ft_printf("Cycle %d\n", data->cycle);
	if (champ != NULL)
	{
		ft_printf("pc %d\n", champ->pc->id);
		for (int i = 0; i < 3; i++)
			ft_printf("arg type %d args[%d] = %d\n", champ->argsType[i], i, champ->args[i]);
	}
	ft_printf(RESET);
}
