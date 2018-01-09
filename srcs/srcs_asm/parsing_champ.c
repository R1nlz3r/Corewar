/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:53:06 by kda-silv          #+#    #+#             */
/*   Updated: 2018/01/09 13:37:56 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		skip_space(int count, char *line)
{
	while (line[count] == ' ' || line[count] == '\t')
		++count;
		return (count);
}

static int		fill_header(char *line, char *cmd, char *source, t_data *data)
{
	int			count;
	int			count2;
	int			tmp;

	count = (int)ft_strlen(cmd);
	if ((tmp = strncmp(cmd, (line + skip_space(0, line)), count)) != 0)
		header_error(cmd, 0, data, line);
	count2 = 0;
	count = skip_space(count + 1, line);
	if (line[count] != '\"')
		header_error(cmd, 1, data, line);
	++count;
	while (line[count] != '\"')
	{
		if ((cmd == NAME_CMD_STRING && count2 > (PROG_NAME_LENGTH - 1))
			|| (cmd == COMMENT_CMD_STRING && count2 > (COMMENT_LENGTH - 1)))
			{
				asm_error("yolo", 0, data, NULL);
				asm_error("\"text\" too long", 1, data, NULL);
			}
		source[count2] = line[count];
		++count;
		++count2;
	}
	if (line[count] != '\"')
		header_error(cmd, 1, data, line);
	count = skip_space((count + 1), line);
	if (line[count] != '\0')
		header_error(cmd, 1, data, line);
	source[count2] = '\0';
	return (1);
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
		if (ft_strstr(line, NAME_CMD_STRING))
			fill_header(line, NAME_CMD_STRING, data->header.prog_name, data);
		if (ft_strstr(line, COMMENT_CMD_STRING))
			fill_header(line, COMMENT_CMD_STRING, data->header.comment, data);
		free(line);
	}
	if (data->header.prog_name[0] == '\0')
		asm_error("Syntaxe error: need a program name", 1, data, NULL);
	if (data->header.comment[0] == '\0')
		asm_error("Syntaxe error: need a comment", 1, data, NULL);
}
