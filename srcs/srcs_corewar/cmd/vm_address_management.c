/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_address_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 10:12:54 by dwald             #+#    #+#             */
/*   Updated: 2018/04/20 15:15:08 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** cast the address in short interval and applies restriction if needed
*/

int		mem_mod(int n)
{
	if (n < 0)
		return (MEM_SIZE + n % MEM_SIZE);
	else
		return (n % MEM_SIZE);
}

int		get_address(int val)
{
	if (val >= ADDRESS_MAX / 2)
		val -= ADDRESS_MAX;
	return (val);
}

int		mem_address(int val)
{
	if (val >= ADDRESS_MAX / 2)
		val -= ADDRESS_MAX;
	val %= MEM_SIZE;
	return (val);
}

int		idx_address(int val)
{
	if (val >= ADDRESS_MAX / 2)
		val -= ADDRESS_MAX;
	val %= IDX_MOD;
	return (val);
}
