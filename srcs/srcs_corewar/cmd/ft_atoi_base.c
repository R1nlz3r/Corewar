/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:59:10 by dwald             #+#    #+#             */
/*   Updated: 2018/04/13 12:40:35 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static	int			test_base(const char c)
{
	int				nb;

	if (c >= '0' && c <= '9')
		nb = c - '0';
	else if (c >= 'a' && c <= 'z')
		nb = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		nb = c - 'A' + 10;
	else
		nb = -1;
	return (nb);
}

int					ft_atoi_base(const char *str, int base)
{
	int				i;
	unsigned int	result;
	int				negative;
	int				digit;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		negative = (str[i] == '-') ? -1 : 1;
		i++;
	}
	digit = test_base(str[i]);
	while (digit >= 0 && digit < base)
	{
		result = result * base + digit;
		i++;
		digit = test_base(str[i]);
	}
	return (result * negative);
}
