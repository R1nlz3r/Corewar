/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_hex_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:55:38 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/28 13:51:11 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	number_to_hex_str(unsigned char n, unsigned char (*str)[])
{
	if (n < 16)
	{
		(*str)[0] = '0';
		(*str)[1] = g_hex_tab[n];
	}
	else
	{
		(*str)[0] = g_hex_tab[(n / 16) % 16];
		(*str)[1] = g_hex_tab[n % 16];
	}
}
