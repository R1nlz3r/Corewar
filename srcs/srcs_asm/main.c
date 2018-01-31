/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:53 by cyrillef          #+#    #+#             */
/*   Updated: 2018/01/31 14:43:22 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_file(t_data *data, int fd, char **av)
{
	if (av[1][ft_strlen(av[1]) - 1] != 's'
		|| av[1][ft_strlen(av[1]) - 2] != '.')
		asm_error("usage: ./asm \"file_name.s\"", 1, data, NULL);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		asm_error("usage: ./asm \"file_name.s\"", 1, data, NULL);
	return (fd);
}

int				main(int ac, char **av)
{
	int			fd;
	t_data		data;

	if (ac != 2)
		asm_error("usage: ./asm \"file_name.s\"", 1, &data, NULL);
	fd = 0;
	fd = check_file(&data, fd, av);
	data.header.magic = COREWAR_EXEC_MAGIC;
	data.name = 0;
	data.comment = 0;
	parsing_champ(fd, &data);
	close(fd);
	printf("|%s|\n", data.header.prog_name);
	printf("|%s|\n", data.header.comment);
	do_cor(&data, av[1]);
	return (0);
}
