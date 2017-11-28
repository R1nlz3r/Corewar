/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:44:50 by kda-silv          #+#    #+#             */
/*   Updated: 2017/10/04 21:06:29 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_buff(const int fd, char **buff, char **line)
{
	int				len;

	if (*buff != NULL)
		free(*buff);
	if ((*buff = ft_strnew(BUFF_SIZE + 1)) == NULL)
		return (-1);
	len = (int)read(fd, *buff, BUFF_SIZE);
	if (len != 0)
		if ((*line = ft_realloc_str(*line, BUFF_SIZE)) == NULL)
			return (-1);
	return (len);
}

static char			*update_buff(char *buff)
{
	int				count;
	int				count2;

	count = 0;
	while (buff[count] != '\0' && buff[count] != '\n')
		++count;
	if (buff[count] == '\n')
	{
		count2 = 0;
		++count;
		while (buff[count] != '\0')
		{
			buff[count2] = buff[count];
			++count;
			++count2;
		}
		buff[count2] = buff[count];
	}
	if (ft_strlen(buff) == 0)
	{
		free(buff);
		buff = NULL;
	}
	return (buff);
}

static int			start_gnl(char **line, char **buff, int len, int fd)
{
	if ((*line = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	if (*buff == NULL)
		if ((len = get_buff(fd, buff, line)) == -1)
			return (-1);
	return (len);
}

int					get_next_line(const int fd, char **line)
{
	static char		*buff = NULL;
	int				len;

	len = 1;
	if ((len = start_gnl(line, &buff, len, fd)) == -1)
		return (-1);
	while (len != 0)
	{
		if (ft_strlcat(*line, buff, ft_strlen_char(buff, '\n')
			+ ft_strlen(*line) + 1) == 0)
			return (-1);
		if (buff[ft_strlen_char(buff, '\n')] == '\0')
		{
			if ((len = get_buff(fd, &buff, line)) == -1)
				return (-1);
		}
		else
			break ;
	}
	if (len == 0)
		return (0);
	buff = update_buff(buff);
	return (len);
}
