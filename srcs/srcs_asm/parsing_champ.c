/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:53:06 by kda-silv          #+#    #+#             */
/*   Updated: 2017/11/29 18:59:27 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		fill_header(char *line, t_data *data)
{
	int			count;

	count = -1;
	if (ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)) == 0)
	{
		while (++count < (int)ft_strlen(NAME_CMD_STRING))
			data->header.prog_name[count] = line[count];
		data->header.prog_name[count] = '\0';
		printf("%s\n", data->header.prog_name);
	}
	return (1);
}

void			parsing_champ(int fd, t_data *data)
{
	char		*line;
	int			error;

	line = NULL;
	while ((error = get_next_line(fd, &line)))
	{
		if (error == -1)
			asm_error("error gnl");
		if (ft_strstr(line, NAME_CMD_STRING)
			|| ft_strstr(line, COMMENT_CMD_STRING))
			fill_header(line, data);

	}
}
