/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:50:54 by cyrillef          #+#    #+#             */
/*   Updated: 2018/04/20 22:28:04 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		multiple_separator(t_data *data, char *line)
{
	int			count;
	int			flag;

	count = -1;
	flag = 0;
	while (line[++count] != '\0')
	{
		if (line[count] != SEPARATOR_CHAR)
			flag = 0;
		if (line[count] == SEPARATOR_CHAR)
			++flag;
		if (flag > 1)
			asm_error("Multiple SEPARATOR_CHAR", 1, data, line);
	}
}

void			bad_char(char *line, t_data *data)
{
	int			count;
	int			count2;
	int			flag;
	char		*tmp;

	count = -1;
	tmp = GOOD_CHAR;
	while (line[++count] != '\0')
	{
		if (line[count] == COMMENT_CHAR)
			break ;
		flag = 0;
		count2 = -1;
		while (tmp[++count2] != '\0')
			if (tmp[count2] == line[count])
				++flag;
		if (flag == 0)
			asm_error("Bad char in instruction", 2, data, line);
	}
	multiple_separator(data, line);
}

void			header_error(char *cmd, int id, t_data *data, char *str)
{
	if (id == 0)
	{
		asm_error("", 0, data, NULL);
		ft_putstr_fd(cmd, 2);
		asm_error(" must be at the beginning of the line", 1, data, str);
	}
	if (id == 1)
	{
		asm_error("", 0, data, NULL);
		ft_putstr_fd("syntaxe muste be: ", 2);
		ft_putstr_fd(cmd, 2);
		asm_error(" \"text\"", 1, data, str);
	}
}

static void		asm_error_next(t_data *data, char *str)
{
	int			count;

	if (str != NULL)
		free(str);
	if (data->fd != -1)
		close(data->fd);
	count = -1;
	if (data->tab != NULL)
	{
		while (data->tab[++count] != NULL)
			ft_word_tab_free(data->tab[count]);
		free(data->tab);
	}
	if (data->labels != NULL)
		ft_word_tab_free(data->labels);
}

void			asm_error(char *error, int flag, t_data *data, char *str)
{
	char		*line;

	ft_putstr_fd(RED, 2);
	if (flag == 0 || flag == 2)
	{
		ft_putstr_fd("Syntaxe error[L", 2);
		line = ft_itoa(data->nbr_line);
		ft_putstr_fd(line, 2);
		free(line);
		ft_putstr_fd("]: ", 2);
		if (flag == 0)
			return ;
	}
	asm_error_next(data, str);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	exit(EXIT_FAILURE);
}
