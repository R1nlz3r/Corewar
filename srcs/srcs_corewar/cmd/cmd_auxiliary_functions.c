/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_auxiliary_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <dwald@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:13:30 by dwald             #+#    #+#             */
/*   Updated: 2018/04/21 09:38:05 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_node			*find_pc_node(t_champion *champ, short pc_dest)
{
	t_node	*node;

	node = champ->oldpc;
	while (node->id != pc_dest)
		node = node->next;
	return (node);
}

/*
**	Reads 32 bits of memory, resulting string interprets as
**  hex number, converts it in integer and returns this number (in decimal).
*/

int				get_mem_32bits(t_champion *champ, int index)
{
	short	pc_dest;
	t_node	*node;
	int		i;
	char	hex_val[9];

	i = 0;
	ft_bzero(hex_val, 9);
	node = champ->oldpc;
	pc_dest = champ->oldpc->id + index;
	while (pc_dest < 0)
		pc_dest = pc_dest + MEM_SIZE;
	while (i < 4)
	{
		while (node->id != (pc_dest + i) % MEM_SIZE)
			node = node->next;
		ft_strcat(hex_val, node->content);
		i++;
	}
	i = ft_atoi_base(hex_val, 16);
	return (i);
}

static	t_node	*write_in_pc_node(t_node *pc, char ram_value, int number)
{
	pc->contentn = ram_value;
	number_to_hex_str(pc->contentn, (unsigned char(*)[])&(pc->content));
	pc->player = number;
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

void			write_in_ram(t_champion *champ, short pc_dest)
{
	t_node	*pc;
	int		ram_value;

	ram_value = 0;
	pc = find_pc_node(champ, pc_dest);
	ram_value = champ->reg[champ->args[0]];
	ram_value = ram_value & 0xFF000000;
	ram_value = ram_value >> 24;
	pc = write_in_pc_node(pc, (char)ram_value, champ->number);
	ram_value = champ->reg[champ->args[0]];
	ram_value = ram_value & 0x00FF0000;
	ram_value = ram_value >> 16;
	pc = write_in_pc_node(pc, (char)ram_value, champ->number);
	ram_value = champ->reg[champ->args[0]];
	ram_value = ram_value & 0x0000FF00;
	ram_value = ram_value >> 8;
	pc = write_in_pc_node(pc, (char)ram_value, champ->number);
	ram_value = champ->reg[champ->args[0]];
	ram_value = ram_value & 0x000000FF;
	pc = write_in_pc_node(pc, (char)ram_value, champ->number);
	return ;
}
