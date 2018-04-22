/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_champ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:53:06 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/20 22:41:46 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		char_size(t_data *data, char *str, int line, int count)
{
	int			len;
	char		*str_line;

	len = 0;
	while (str[count] != '\0' && str[count] != SEPARATOR_CHAR)
	{
		if (str[count] != '-')
			++len;
		++count;
	}
	if (len > 10)
	{
		ft_putstr_fd(RED, 2);
		ft_putstr_fd("Syntaxe error[L", 2);
		str_line = ft_itoa(line);
		ft_putstr_fd(str_line, 2);
		free(str_line);
		asm_error("]: NBR too long (10 char max)", 1, data, NULL);
	}
}

static void		check_size_nbr(t_data *data, int line, int word, int count)
{
	while (data->tab[++line] != NULL)
	{
		if (data->tab[line][1] == NULL)
			continue ;
		if (data->tab[line][0][ft_strlen(data->tab[line][0]) - 1] == LABEL_CHAR)
			word = 2;
		else
			word = 1;
		while (data->tab[line][word][++count] != '\0')
		{
			if (data->tab[line][word][count] == DIRECT_CHAR
				&& data->tab[line][word][count + 1] != LABEL_CHAR)
				char_size(data, data->tab[line][word], line, count + 1);
			if (data->tab[line][word][count] == 'r')
				char_size(data, data->tab[line][word], line, count + 1);
			if (data->tab[line][word][count] == '-'
				|| (data->tab[line][word][count] >= '0'
				&& data->tab[line][word][count] <= '9'))
				if (count == 0 || (count > 0
					&& data->tab[line][word][count - 1] == SEPARATOR_CHAR))
					char_size(data, data->tab[line][word], line, count);
		}
	}
}

static void		take_prog_size(t_data *data)
{
	int			line;

	line = -1;
	while (data->tab[++line] != NULL)
		data->header.prog_size += size_function(data, line);
}

static void		last_check(t_data *data)
{
	if (data->name == 0)
		asm_error("Syntaxe error: need a program name", 1, data, NULL);
	if (data->comment == 0)
		asm_error("Syntaxe error: need a comment", 1, data, NULL);
	if (data->check_cmd == 0)
		asm_error("Syntaxe error: no instructions", 1, data, NULL);
	check_size_nbr(data, -1, 0, -1);
	check_miss_label(data);
	take_prog_size(data);
}

void			parsing_champ(int fd, t_data *data, int error, char *line)
{
	if (REG_NUMBER > 255)
		asm_error("Error REG_NUMBER > 255", 1, data, NULL);
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
		}
		free(line);
		line = NULL;
	}
	if (line != NULL)
		free(line);
	last_check(data);
}
