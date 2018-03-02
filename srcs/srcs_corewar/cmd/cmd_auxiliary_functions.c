/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_auxiliary_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:13:30 by dwald             #+#    #+#             */
/*   Updated: 2018/03/02 16:48:48 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


t_node		*find_pc_node(t_champion *champ, short pc_dest)
{
	t_node	*node;
	
	node = champ->pc;
	while (champ->ipc < pc_dest--)
		node = node->next;
	return (node);
}
/*
int			write_in_ram(t_node *pc);
{
}
*/
