/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:17:31 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:31:13 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		resultat;
	int		count;
	int		flag;

	if (str == NULL)
		return (-1);
	resultat = 0;
	count = 0;
	flag = 1;
	while (str[count] == '\f' || str[count] == '\n' || str[count] == '\r'
		|| str[count] == '\t' || str[count] == '\v' || str[count] == ' ')
		++count;
	if (str[count] == '-' || str[count] == '+')
		if (str[count++] == '-')
			flag = -1;
	while (str[count] != '\0')
	{
		if (str[count] < '0' || str[count] > '9')
			return (resultat * flag);
		resultat = (resultat * 10) + (str[count] - '0');
		++count;
	}
	return (resultat * flag);
}
