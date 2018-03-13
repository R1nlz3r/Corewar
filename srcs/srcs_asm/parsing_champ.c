/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:53:06 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/13 17:35:04 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		last_check(t_data *data)
{
	if (data->check_cmd == 0)
		asm_error("Syntaxe error: no instructions", 1, data, NULL);
	if (data->name == 0)
		asm_error("Syntaxe error: need a program name", 1, data, NULL);
	if (data->comment == 0)
		asm_error("Syntaxe error: need a comment", 1, data, NULL);
}

void			parsing_champ(int fd, t_data *data)
{
	char		*line;
	int			error;

	line = NULL;
	data->nbr_line = 0;
	data->check_cmd = 0;
	while ((error = get_next_line(fd, &line)))
	{
		if (error == -1)
			asm_error("Error gnl", 1, data, NULL);
		data->line = line;
		++data->nbr_line;
		if (line[0] != COMMENT_CHAR)
		{
			if (data->name != 1 || data->comment != 1)
				header(line, data);
			if (!ft_strstr(line, NAME_CMD_STRING)
				&& !ft_strstr(line, COMMENT_CMD_STRING) && line[0] != 0)
				if (check_core(line, data, 0) == 1)
					++data->check_cmd;
			free(line);
		}
	}
	last_check(data);
}
