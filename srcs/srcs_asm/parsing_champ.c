/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:53:06 by kda-silv          #+#    #+#             */
/*   Updated: 2017/12/07 19:41:17 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		fill_header(char *line, char *cmd, char *source, t_data *data)
{
	int			count;
	int			count2;

	count = (int)ft_strlen(cmd);
	if (strncmp(cmd, line, count) != 0)
		header_error(cmd, 0, data);
	count2 = 0;
	while ((line[count] == ' ' || line[count] == '\t') && line[count] != '\0')
		++count;
	if (line[count] != '\"')
		header_error(cmd, 1, data);
	while (line[count] != '\"')
	{
		//if (count2 >)
		source[count2] = line[count];
		++count;
		++count2;
	}
	if (line[count] == '\"' && line[count + 1] != '\0')
		header_error(cmd, 1, data);
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
			asm_error("error gnl", 1, data);
		++data->line;
		if (ft_strstr(line, NAME_CMD_STRING))
			fill_header(line, NAME_CMD_STRING, data->header.prog_name, data);
		if (ft_strstr(line, COMMENT_CMD_STRING))
			fill_header(line, COMMENT_CMD_STRING, data->header.comment, data);
		free(line);
	}
}
