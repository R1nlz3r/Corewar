/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:59:41 by kda-silv          #+#    #+#             */
/*   Updated: 2018/01/31 15:26:07 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		skip_space(int count, char *line)
{
	while (line[count] == ' ' || line[count] == '\t')
		++count;
	return (count);
}
static void		header_too_long(char *cmd, char *line, t_data *data, int count2)
{
	if (cmd == NAME_CMD_STRING && count2 > (PROG_NAME_LENGTH - 1))
	{
		asm_error("yolo", 0, data, NULL);
		asm_error("Champion name too long (max length 128)", 1, data, line);
	}

	if (cmd == COMMENT_CMD_STRING && count2 > (COMMENT_LENGTH - 1))
	{
		asm_error("yolo", 0, data, NULL);
		asm_error("Champion comment too long (max length 2048)", 1, data, line);
	}
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
	if (line[(count = skip_space(count + 1, line))] != '\"')
		header_error(cmd, 1, data, line);
	++count;
	while (line[count] != '\"')
	{
		header_too_long(cmd, line, data, count2);
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

void			header(char *line, t_data *data)
{
	if (ft_strstr(line, NAME_CMD_STRING))
	{
		if (data->name == 1)
		{
			asm_error("yolo", 0, data, NULL);
			asm_error("2 name in the file", 1, data, line);
		}
		fill_header(line, NAME_CMD_STRING, data->header.prog_name, data);
		data->name = 1;
	}
	if (ft_strstr(line, COMMENT_CMD_STRING))
	{
		if (data->comment == 1)
		{
			asm_error("yolo", 0, data, NULL);
			asm_error("2 comment in the file", 1, data, line);
		}
		fill_header(line, COMMENT_CMD_STRING, data->header.comment, data);
		data->comment = 1;
	}
}
