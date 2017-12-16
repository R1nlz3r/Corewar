/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:49:10 by kda-silv          #+#    #+#             */
/*   Updated: 2017/12/15 17:53:28 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		create_file(t_data *data, char *source)
{
	int			fd;
	int			count;
	char		*file_cor;

	count = (int)ft_strlen(source) + 2;
	if ((file_cor = ft_memalloc(count * sizeof(char))) == NULL)
		asm_error("Error malloc", 1, data, NULL);
	if ((file_cor = ft_strcat(file_cor, source)) == NULL)
		asm_error("Error malloc", 1, data, file_cor);
	file_cor[count - 3] = 'c';
	file_cor[count - 2] = 'o';
	file_cor[count - 1] = 'r';
	file_cor[count] = '\0';
	if ((fd = open(file_cor, O_RDWR | O_CREAT | O_TRUNC, 0755)) == -1)
		asm_error("Error creat file", 1, data, file_cor);
	free(file_cor);
	return (fd);
}

void			do_cor(t_data *data, char *source)
{
	int			fd;

	fd = create_file(data, source);
	write(fd, &data->header, sizeof(t_header));
}
