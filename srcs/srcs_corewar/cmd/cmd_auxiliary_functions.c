/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_auxiliary_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:13:30 by dwald             #+#    #+#             */
/*   Updated: 2018/04/06 11:55:50 by dwald            ###   ########.fr       */
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
	
	return (0);
}


/*
**	Reads 32 bits of memory, resulting string interprets as
**  hex number, converts it in integer and returns this number. 
*/

/*int				find_indirect_value(t_champion *champ, int index)
{
	short	pc_dest;
	t_node	*node;
	int		i;
	char	hex_val[50];

	// Display tests
//	ft_printf(GREEN"champ->ipc = %d "RESET, champ->ipc);
//ft_printf(GREEN"champ->args[%d] = %d\n"RESET,champ->ipc,index,champ->args[index]);
	//end of tests
	i = 0;
	ft_bzero(hex_val, 50);
	node = champ->oldpc;
	pc_dest = champ->oldpc->id + index % IDX_MOD;
	while (pc_dest < 0)
		pc_dest = pc_dest + MEM_SIZE;
	ft_printf(GREEN"pc_dest = %d\n"RESET, pc_dest);
	while (i < 4)
	{
		while (node->id != (pc_dest + i) % MEM_SIZE)
			node = node->next;
		ft_printf(GREEN"node->id = %d content hexa string = %s num_int: %i\n"RESET, node->id, node->content, node->contentn);
			ft_strcpy(hex_val, ft_itoa((int)node->contentn));
		i++;
	}
//	hex_val[4] = '\0';
	ft_printf(GREEN"hex_val = %s\n"RESET, hex_val);
	ft_printf("val = %s\n", hex_val);
//	i = ft_atoi_base(hex_val, 16); 
//	ft_printf(GREEN"i = %d\n"RESET, i);
	return (i);
}*/	

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
