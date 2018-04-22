/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:19:53 by cyrillef          #+#    #+#             */
/*   Updated: 2018/04/21 11:08:01 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_file(t_data *data, char **av)
{
	int			fd;

	if (av[1][ft_strlen(av[1]) - 1] != 's'
		|| av[1][ft_strlen(av[1]) - 2] != '.')
		asm_error("usage: ./asm \"file_name.s\"", 1, data, NULL);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		asm_error("usage: ./asm \"file_name.s\"", 1, data, NULL);
	return (fd);
}

static void		delete_data(t_data data)
{
	int			count;

	count = -1;
	if (data.file_cor != NULL)
		free(data.file_cor);
	if (data.tab != NULL)
	{
		while (data.tab[++count] != NULL)
			ft_word_tab_free(data.tab[count]);
		free(data.tab);
	}
	if (data.labels != NULL)
		ft_word_tab_free(data.labels);
}

int				main(int ac, char **av)
{
	t_data		data;

	data.header.magic = COREWAR_EXEC_MAGIC;
	data.name = 0;
	data.comment = 0;
	data.tab = NULL;
	data.labels = NULL;
	data.nbr_line = 0;
	data.check_cmd = 0;
	if (ac != 2)
		asm_error("usage: ./asm \"file_name.s\"", 1, &data, NULL);
	data.fd = -1;
	data.fd = check_file(&data, av);
	parsing_champ(data.fd, &data, 0, NULL);
	close(data.fd);
	do_cor(&data, av[1]);
	ft_putstr_fd(GREEN, 1);
	ft_putstr_fd(data.file_cor, 1);
	ft_putstr_fd(" has been created !\n", 1);
	ft_putstr_fd(RESET, 1);
	delete_data(data);
	return (0);
}
