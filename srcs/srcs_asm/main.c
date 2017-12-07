/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:53 by cyrillef          #+#    #+#             */
/*   Updated: 2017/12/07 19:33:00 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				main(int ac, char **av)
{
	int			fd;
	t_data		data;

	if (ac != 2)
		asm_error("usage: ./asm \"file_name\"", 1, &data);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		asm_error("usage: ./asm \"file_name\"", 1, &data);
	parsing_champ(fd, &data);
	printf("|%s|\n", data.header.prog_name);
	printf("|%s|\n", data.header.comment);
	return (0);
}
