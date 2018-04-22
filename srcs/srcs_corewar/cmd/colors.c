/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:21:17 by dwald             #+#    #+#             */
/*   Updated: 2018/04/19 17:28:15 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	*color_champion(int id, char *s)
{
	ft_bzero(s, 7);
	if (id == 1)
		s = ft_strcpy(s, "\033[32m");
	else if (id == 2)
		s = ft_strcpy(s, "\033[34m");
	else if (id == 3)
		s = ft_strcpy(s, "\033[31m");
	else if (id == 4)
		s = ft_strcpy(s, "\033[36m");
	else
		s = ft_strcpy(s, "\033[90m");
	return (s);
}
