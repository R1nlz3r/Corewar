/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_auxiliary_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:13:30 by dwald             #+#    #+#             */
/*   Updated: 2018/03/26 15:03:15 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		mem_mod(int n)
{
	if (n < 0)
		return (MEM_SIZE + n % MEM_SIZE);
	else
		return (n % MEM_SIZE);
}

t_node			*find_pc_node(t_champion *champ, short pc_dest)
{
	t_node	*node;

	node = champ->oldpc;
//	ft_printf(GREEN"pc_dest = %d "RESET, pc_dest);
	while (node->id != pc_dest)
		node = node->next;
//	ft_printf(GREEN"node->id = %d\n"RESET, node->id);
	return (node);
}

int				find_indirect_value(t_champion *champ, int index)
{
	short	pc_dest;
	t_node	*node;

	// Display tests
//	ft_printf(GREEN"champ->ipc = %d "RESET, champ->ipc);
	ft_printf(GREEN"champ->oldpc->id = %d "RESET, champ->oldpc->id);
//ft_printf(GREEN"champ->args[%d] = %d\n"RESET,champ->ipc,index,champ->args[index]);
	//end of tests
	pc_dest = mem_mod(champ->oldpc->id + index);
	ft_printf(GREEN"pc_dest = %d "RESET, pc_dest);
	node = find_pc_node(champ, pc_dest);
	ft_printf(GREEN"node->id = %d "RESET, node->id);
	return (node->contentn);
}	

static	t_node	*write_in_pc_node(t_node *pc, char ram_value)
{
	pc->contentn = ram_value;
	number_to_hex_str(pc->contentn, (unsigned char(*)[])&(pc->content));
	pc = pc->next;
	return (pc);
}

/*
** This function finds position in RAM (PC) and changes its content based on
** register content using appopriate bit mask: each PC has a memory of 8 bits
** (1 byte) displayed in hex. Regiter value is represented on 4 bytes, so its
** value rewrites on 4 nodes in RAM.
**		FF 			FF			FF			FF
**  1111 1111	1111 1111	1111 1111	1111 1111  => 32 bits => 4 bytes
*/

int			write_in_ram(t_champion *champ, short pc_dest)
{
	t_node	*pc;
	int		ram_value;
	int		pc_origin;

	ram_value = 0;
	pc = find_pc_node(champ, pc_dest);
	pc_origin = pc->id;
//	ft_printf(RED"sti pc = %d\n"RESET, pc->id);
	ram_value = champ->reg[champ->args[0]];
	ram_value = ram_value & 0xFF000000;
	ram_value = ram_value >> 24;
	pc = write_in_pc_node(pc, (char)ram_value);
	ram_value = champ->reg[champ->args[0]];
	ram_value = ram_value & 0x00FF0000;
	ram_value = ram_value >> 16;
	pc = write_in_pc_node(pc, (char)ram_value);
	ram_value = champ->reg[champ->args[0]];
	ram_value = ram_value & 0x0000FF00;
	ram_value = ram_value >> 8;
	pc = write_in_pc_node(pc, (char)ram_value);
	ram_value = champ->reg[champ->args[0]];
	ram_value = ram_value & 0x000000FF;
	pc = write_in_pc_node(pc, (char)ram_value);
	return (pc_origin);
}
