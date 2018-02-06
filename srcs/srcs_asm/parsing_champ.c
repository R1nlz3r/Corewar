/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:53:06 by kda-silv          #+#    #+#             */
/*   Updated: 2018/01/31 19:13:12 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static bool		cmp_label_chars(char c)
{
	int			count;
	bool		flag;
	char		*tmp;

	flag = 1;
	count = -1;
	tmp = LABEL_CHARS;
	while (tmp[++count] != '\0')
		if (c == tmp[count])
			flag = 0;
	return (flag);
}

static void		label(char *line, t_data *data)
{
	int			count;
	bool		flag;

	count = -1;
	flag = 0;
	while (line[++count] != '\0')
	{
		if (flag == 1 && line[count] == ':'
			&& count > 0 && line[count - 1] != '%')
		{
			asm_error("yolo", 0, data, NULL);
			asm_error("Bad name of label", 1, data, line);
		}
		if (cmp_label_chars(line[count]) == 1)
			flag = 1;
	}
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
			label(line, data);
		free(line);
	}
	if (data->name == 0)
		asm_error("Syntaxe error: need a program name", 1, data, NULL);
	if (data->comment == 0)
		asm_error("Syntaxe error: need a comment", 1, data, NULL);
}
