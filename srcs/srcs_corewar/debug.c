/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 17:13:29 by cfrouin           #+#    #+#             */
/*   Updated: 2018/04/20 20:46:31 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			error(char *msg)
{
	ft_printf(RED);
	ft_printf(msg);
	ft_printf(RESET);
}

void			dump_state(char *msg, t_data *data, t_champion *champ)
{
	int			i;

	ft_printf(RED);
	if (msg != NULL)
		ft_printf("%s\n", msg);
	if (data != NULL)
		ft_printf("Cycle %d\n", data->cycle);
	if (champ != NULL)
	{
		ft_printf(PURPLE"------------DUMP CHAMPION------------\n");
		ft_printf("op %s %d\n", champ->op.name, champ->op.opcode);
		ft_printf("pc %x / %d\n", champ->pc->id, champ->pc->id);
		if (champ->oldpc != NULL)
			ft_printf("old_pc %d\n", champ->oldpc->id);
		i = -1;
		while (++i < 3)
			ft_printf("arg type %d args[%d] = %d\n", champ->argstype[i], i,
			champ->args[i]);
		ft_printf("REGS : ");
		i = 0;
		while (++i < 17)
			ft_printf("%d ", champ->reg[i]);
		ft_printf("\n-----------------------------\n"RESET);
	}
	ft_printf(RESET);
}
