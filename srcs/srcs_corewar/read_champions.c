/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:34:50 by cyrillef          #+#    #+#             */
/*   Updated: 2018/02/20 16:22:13 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void			read_file(t_data *data, int fd, t_champion *champion)
{
	int				index;
	char			buff[1];
	unsigned char	tmp_hex[3];
	t_header		tmp;

	if (read(fd, &tmp, sizeof(t_header)) <= 0)
		corewar_error(data, "Error when reading champion's header.\n");
	ft_strcpy(champion->name, tmp.prog_name);
	ft_strcpy(champion->comment, tmp.comment);
	index = 0;
	bzero(buff, 1);
	bzero(tmp_hex, 3);
	bzero(champion->code, 1024);
	while (read(fd, buff, 1) > 0)
	{
		number_to_hex_str(buff[0], &tmp_hex);
		tmp_hex[2] = ' ';
		ft_strncpy((char *)&champion->code[index], (char*)tmp_hex, 3);
		index += 3;
		bzero(buff, 1);
		bzero(tmp_hex, 3);
	}
	champion->size = ft_strlen((char*)champion->code) / 3;
}

static int			read_champion(t_data *data, t_champion *champion)
{
	int				fd;
	int				i;

	if ((fd = open(champion->filename, O_RDONLY)) == -1)
		corewar_error(data, "Can't open champion.\n");
	i = 1;
	while (i < REG_NUMBER)
		champion->reg[i++] = 0;
	read_file(data, fd, champion);
	if (champion->size > CHAMP_MAX_SIZE)
	{
		free(champion);
		corewar_error(data, "Champion is too big.\n");
	}
	close(fd);
	return (1);
}

int					read_champions(t_data *data)
{
	t_champion		*node;
	int				i;

	node = data->champions;
	i = 0;
	while (node)
	{
		i++;
		if (i > MAX_PLAYERS)
			return (-1);
		if (read_champion(data, node) != 1)
			return (-1);
		node = node->next;
	}
	return (1);
}
