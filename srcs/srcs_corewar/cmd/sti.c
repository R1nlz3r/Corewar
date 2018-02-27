/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:27:32 by dwald             #+#    #+#             */
/*   Updated: 2018/02/26 17:05:48 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Take a registry and two indexes (potentially registries) add the two indexes
** and use this result as an address where the value of the first parameter
** will be copied. Modifies carry.
*/

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_MAGENTA		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_HIGHLIGHT	"\033[1m"
# define PF_UNDERLINE	"\033[4m"
# define PF_BLINK		"\033[5m"
# define PF_EOC			"\033[0m"

int		corewar_sti(t_data *data, t_champion *champ)
{
	t_node	*tmp;
	short	pc_dest;
	int		parameter[2];

	ft_printf(PF_YELLOW"****HELLO******\n");
	ft_printf(PF_GREEN"\n*****arg type %d args[0] = %d*****\n"PF_EOC, champ->argsType[0], champ->args[0]);
	ft_printf(PF_YELLOW"\n*****arg type %d r[%d] = %d*****\n"PF_EOC, champ->argsType[0], champ->args[0], champ->reg[champ->args[0]]);
	ft_printf(PF_YELLOW"\nchampion register reg[%d] = %x\n"PF_EOC, 0, champ->reg[0]);
	(void)data;
	tmp = champ->pc;
	if (champ->argsType[0] != T_REG || (champ->argsType[2] != T_DIR
	&& champ->argsType[2] != T_REG))
		return (-1);
//  2nd param
	if (champ->argsType[1] == T_REG)
		parameter[0] = champ->reg[champ->args[1]];
	else if (champ->argsType[1] == T_IND)
	{
		pc_dest = champ->ipc + (champ->args[0] % IDX_MOD);
		while (champ->ipc > pc_dest--)
			tmp = tmp->next;
		parameter[0] = tmp->contentn;
	}
	else if (champ->argsType[1] == T_DIR)
		parameter[0] = champ->args[1];
//	3rd param
	if (champ->argsType[2] == T_REG)
		parameter[1] = champ->reg[champ->args[2]];
	else if (champ->argsType[2] == T_DIR)
		parameter[1] = champ->args[2];
//get final address and stock there reg[param1]
	ft_printf(PF_YELLOW"\n*****carry = %d*****\n"PF_EOC,champ->carry);
	pc_dest = parameter[0] + parameter[1];
	champ->carry = (pc_dest == 0) ? 1 : 0;
	tmp = champ->pc;
	ft_printf(PF_YELLOW"\n*****sti pc = %d*****\n"PF_EOC, tmp->id);
	ft_printf(PF_RED"\n*****carry = %d*****\n"PF_EOC,champ->carry);
	while (champ->ipc > pc_dest--)
		tmp = tmp->next;
	ft_printf(PF_RED"****HELLO******\n");
	ft_printf(PF_RED"\n*****sti pc = %d*****\n"PF_EOC, tmp->id);
	tmp->contentn = champ->reg[champ->args[0]];
	number_to_hex_str(tmp->contentn, (unsigned char(*)[])&(tmp->content)); //wrong param format
	return (1);
}
