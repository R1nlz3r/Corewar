/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:53:06 by kda-silv          #+#    #+#             */
/*   Updated: 2018/01/31 16:02:18 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		core(char *line, t_data *data)
{
	(void) line;
	(void) data;
}

void			parsing_champ(int fd, t_data *data)
{
	char		*line;
	int			error;

	line = NULL;
	data->line = 0;
	while ((error = get_next_line(fd, &line)))
	{
		if (error == -1)
			asm_error("Error gnl", 1, data, NULL);
		++data->line;
		header(line, data);
		if (data->name == 1 && data->comment == 1)
			core(line, data);
		free(line);
	}
	if (data->name == 0)
		asm_error("Syntaxe error: need a program name", 1, data, NULL);
	if (data->comment == 0)
		asm_error("Syntaxe error: need a comment", 1, data, NULL);
}
