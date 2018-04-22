/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:15:38 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:35:37 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putendl_fd(char const *s, int fd)
{
	if (s != NULL)
	{
		if (write(fd, s, ft_strlen((char *)(uintptr_t)s)) == -1)
			return (-1);
		return ((int)write(fd, "\n", 1));
	}
	return (1);
}
