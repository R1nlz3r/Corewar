/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_hex_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:55:38 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/24 16:35:18 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	number_to_hex_str(unsigned char n, unsigned char (*str)[])
{
	if (n < 16)
	{
		(*str)[0] = '0';
		(*str)[1] = hex_tab[n];
	}
	else
	{
		(*str)[0] = hex_tab[(n / 16) % 16];
		(*str)[1] = hex_tab[n % 16];
	}
}
