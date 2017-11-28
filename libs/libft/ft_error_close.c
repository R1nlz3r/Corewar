/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 16:09:10 by kda-silv          #+#    #+#             */
/*   Updated: 2017/02/01 16:36:43 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_error_close_void(int fd)
{
	close(fd);
	return (NULL);
}

int			ft_error_close_int(int fd)
{
	close(fd);
	return (0);
}

void		*ft_error_close_str_void(char const *str, int fd)
{
	close(fd);
	ft_putendl(str);
	return (NULL);
}

int			ft_error_close_str_int(char const *str, int fd)
{
	close(fd);
	ft_putendl(str);
	return (0);
}
