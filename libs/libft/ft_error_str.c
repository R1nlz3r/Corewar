/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 15:43:17 by kda-silv          #+#    #+#             */
/*   Updated: 2017/10/04 17:38:06 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_error_str_void(char const *str)
{
	ft_putendl(str);
	return (NULL);
}

int			ft_error_str_int(char const *str)
{
	ft_putendl(str);
	return (-1);
}
