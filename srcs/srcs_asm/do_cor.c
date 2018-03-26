/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:49:10 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/26 14:53:27 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		create_file(t_data *data, char *source)
{
	int			fd;
	int			count;

	count = (int)ft_strlen(source) + 2;
	if ((data->file_cor = ft_memalloc(count * sizeof(char))) == NULL)
		asm_error("Error malloc", 1, data, NULL);
	if ((data->file_cor = ft_strcat(data->file_cor, source)) == NULL)
		asm_error("Error malloc", 1, data, data->file_cor);
	data->file_cor[count - 3] = 'c';
	data->file_cor[count - 2] = 'o';
	data->file_cor[count - 1] = 'r';
	data->file_cor[count] = '\0';
	if ((fd = open(data->file_cor, O_RDWR | O_CREAT | O_TRUNC, 0755)) == -1)
		asm_error("Error creat file", 1, data, data->file_cor);
	return (fd);
}

void			do_cor(t_data *data, char *source)
{
	int			fd;

	fd = create_file(data, source);
	write(fd, &data->header, sizeof(t_header));
}
