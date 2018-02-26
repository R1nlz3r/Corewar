/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_hex_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:55:38 by cyrillef          #+#    #+#             */
/*   Updated: 2018/02/26 17:42:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int		get_index_tab(const char tab[], char c)
{
	int			i;

	i = 0;
	while (tab[i] && tab[i] != c)
		i++;
	if (tab[i] == c)
		return (i);
	return (-1);
}

int				str_hex_to_number(char str[3])
{
	int			nbr;
	int			i;

	nbr = 0;
	i = get_index_tab(g_hex_tab, str[0]);
	nbr = 16 * i;
	i = get_index_tab(g_hex_tab, str[1]);
	nbr += i;
	return (nbr);
}

void			number_to_hex_str(int n, unsigned char (*str)[])
{
	if (n < 0)
		n = 256 + n;
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
