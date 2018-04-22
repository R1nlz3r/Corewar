/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:13:40 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/20 22:24:51 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char				*name_label(t_data *data, int line, int word, int count)
{
	int				len;
	int				tmp;
	int				count2;
	char			*name;

	len = 0;
	tmp = count;
	while (data->tab[line][word][tmp] != '\0'
		&& data->tab[line][word][tmp] != SEPARATOR_CHAR)
	{
		++len;
		++tmp;
	}
	if ((name = malloc((len + 1) * sizeof(char))) == NULL)
		asm_error("Error malloc", 1, data, data->file_cor);
	count2 = 0;
	while (data->tab[line][word][++count] != '\0'
		&& data->tab[line][word][count] != SEPARATOR_CHAR)
	{
		name[count2] = data->tab[line][word][count];
		++count2;
	}
	name[count2] = LABEL_CHAR;
	name[count2 + 1] = '\0';
	return (name);
}

static int			take_label_line(t_data *data, char *name)
{
	int				line_label;

	line_label = 0;
	while (data->tab[line_label] != NULL)
	{
		if (ft_strcmp(name, data->tab[line_label][0]) == 0)
			break ;
		++line_label;
	}
	if (data->tab[line_label][1] == NULL && data->tab[line_label + 1] == NULL)
		--line_label;
	if (data->tab[line_label][1] == NULL && data->tab[line_label + 1] != NULL)
		++line_label;
	return (line_label);
}

static int			label_line_under(int line, int line_label, t_data *data
						, char *name)
{
	int				size;

	size = 0;
	if (line > 0)
		--line;
	while (line >= line_label)
	{
		size -= size_function(data, line);
		if (ft_strcmp(name, data->tab[line][0]) == 0)
		{
			free(name);
			return (size);
		}
		--line;
	}
	free(name);
	return (size);
}

static int			label_line_upper(int line, int line_label, t_data *data
						, char *name)
{
	int				size;

	size = 0;
	while (data->tab[line] != NULL && line <= line_label)
	{
		if (ft_strcmp(name, data->tab[line][0]) == 0)
		{
			free(name);
			return (size);
		}
		size += size_function(data, line);
		++line;
	}
	free(name);
	return (size);
}

int					write_label(t_data *data, int line, int word, int count)
{
	char			*name;
	int				line_label;

	name = name_label(data, line, word, count);
	line_label = take_label_line(data, name);
	if (line == line_label)
	{
		free(name);
		return (0);
	}
	if (line > line_label)
		return (label_line_under(line, line_label, data, name));
	if (line < line_label)
		return (label_line_upper(line, line_label, data, name));
	free(name);
	return (0);
}
