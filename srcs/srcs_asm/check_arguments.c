/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:27:25 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/21 12:14:12 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		count_arg(t_data *data, int type)
{
	if (data->nbr_arg > 2)
		asm_error("Too Many Arguments", 2, data, data->line);
	else
		data->args[data->nbr_arg] = type;
	++data->nbr_arg;
}

static int		registre(char **tab, int count_word, t_data *data, int count)
{
	if (!(tab[count_word][count] >= '0'
		&& tab[count_word][count] <= '9'))
		asm_error("Bad Registre", 2, data, data->line);
	if (ft_atoi((tab[count_word] + count)) < 0
		|| ft_atoi((tab[count_word] + count)) > REG_NUMBER)
		asm_error("Bad Registre", 2, data, data->line);
	while (tab[count_word][count] >= '0'
		&& tab[count_word][count] <= '9')
		++count;
	if (tab[count_word][count] != '\0'
		&& tab[count_word][count] != SEPARATOR_CHAR)
		asm_error("Bad Registre", 2, data, data->line);
	if (tab[count_word][count] == SEPARATOR_CHAR)
		++count;
	count_arg(data, REG);
	return (count);
}

static int		direct(char **tab, int count_word, t_data *data, int count)
{
	if (tab[count_word][count] == LABEL_CHAR)
	{
		if (check_label(tab, count_word, ++count, 1) == -1)
			asm_error("Bad Label", 2, data, data->line);
		while (tab[count_word][count] != '\0'
			&& tab[count_word][count] != SEPARATOR_CHAR)
			++count;
	}
	else
	{
		if (tab[count_word][count] == '-')
			++count;
		--count;
		while (tab[count_word][++count] != '\0'
			&& tab[count_word][count] != SEPARATOR_CHAR)
			if (tab[count_word][count] < '0'
				&& tab[count_word][count] > '9')
				asm_error("Bad DIRECT Argument", 2, data, data->line);
	}
	if (tab[count_word][count] != '\0')
		++count;
	count_arg(data, DIR);
	return (count);
}

static int		indirect(char **tab, int count_word, t_data *data, int count)
{
	if (tab[count_word][count] == LABEL_CHAR)
	{
		if (check_label(tab, count_word, ++count, 1) == -1)
			asm_error("Bad Label", 2, data, data->line);
		while (tab[count_word][count] != '\0'
			&& tab[count_word][count] != SEPARATOR_CHAR)
			++count;
	}
	else
		while (tab[count_word][++count] != '\0'
			&& tab[count_word][count] != SEPARATOR_CHAR)
			if (!(tab[count_word][count] >= '0'
				&& tab[count_word][count] <= '9'))
				asm_error("Bad INDIRECT Argument", 2, data, data->line);
	if (tab[count_word][count] != '\0')
		++count;
	count_arg(data, INDIR);
	return (count);
}

void			check_args(char **tab, int count_word, t_data *data, char *line)
{
	int			count;

	count = 0;
	while (tab[count_word][count] != '\0')
	{
		if (tab[count_word][count] == 'r')
			count = registre(tab, count_word, data, (count + 1));
		if (tab[count_word][count] == '\0')
			break ;
		if (tab[count_word][count] == DIRECT_CHAR)
			count = direct(tab, count_word, data, (count + 1));
		if (tab[count_word][count] == '\0')
			break ;
		if (tab[count_word][count] == '-'
			|| tab[count_word][count] == LABEL_CHAR
			|| (tab[count_word][count] >= '0' && tab[count_word][count] <= '9'))
			count = indirect(tab, count_word, data, count);
	}
	if (tab[count_word + 1] != NULL && tab[count_word + 1][0] != COMMENT_CHAR)
		asm_error("One Instruction By Line", 2, data, line);
}
