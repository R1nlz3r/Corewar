/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:50:26 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/13 13:53:38 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				check_label(char **tab, int count_word, int count, int mode)
{
	char		*tmp;
	int			flag;
	int			count2;

	if (mode == 0 && count_word != 0)
		return (-1);
	tmp = LABEL_CHARS;
	while (tab[count_word][count] != '\0'
		&& tab[count_word][count] != SEPARATOR_CHAR
		&& tab[count_word][count] != LABEL_CHAR)
	{
		flag = 0;
		count2 = -1;
		while (tmp[++count2] != '\0')
			if (tmp[count2] == tab[count_word][count])
				++flag;
		if (flag == 0)
			return (-1);
		++count;
	}
	if (mode == 1 && tab[count_word][count] != '\0'
		&& tab[count_word][count] != SEPARATOR_CHAR)
		return (-1);
	return (1);
}

static t_data	*init_instructions(t_data *data)
{
	data->functions[0] = &live;
	data->functions[1] = &ld;
	data->functions[2] = &st;
	data->functions[3] = &add;
	data->functions[4] = &sub;
	data->functions[5] = &and;
	data->functions[6] = &or;
	data->functions[7] = &xor;
	data->functions[8] = &zjmp;
	data->functions[9] = &ldi;
	data->functions[10] = &sti;
	data->functions[11] = &fork_asm;
	data->functions[12] = &lld;
	data->functions[13] = &lldi;
	data->functions[14] = &lfork;
	data->functions[15] = &aff;
	return (data);
}

static void		check_instruction(char **tab, int count_word, t_data *data
					, char *line)
{
	char		**instructions;
	int			flag;
	int			count;

	if ((instructions = ft_word_tab(FC)) == NULL)
		asm_error("Error Malloc", 1, data, line);
	data = init_instructions(data);
	flag = 0;
	count = -1;
	data->args[0] = -1;
	data->args[1] = -1;
	data->args[2] = -1;
	while (instructions[++count] != NULL)
		if (ft_strcmp(tab[count_word], instructions[count]) == 0)
		{
			++flag;
			data->functions[count](data, line, tab, (count_word + 1));
			break ;
		}
	if (flag == 0)
		asm_error("Instruction Missed", 2, data, line);
}

static int		error_start_line(char **tab, t_data *data, char *line)
{
	int			count;

	count = 0;
	if (tab[0] == NULL)
		return (0);
	while (tab[0][count] != '\0' && tab[0][count] != LABEL_CHAR)
		++count;
	if (tab[0][count] == LABEL_CHAR && count > 0 && tab[0][count - 1] == '%'
		&& tab[0][count + 1] != '\0')
		asm_error("Bad Label", 2, data, line);
	return (1);
}

int				check_core(char *line, t_data *data, int count_word)
{
	char		**tab;

	bad_char(line, data);
	if ((tab = ft_word_tab(line)) == NULL)
		asm_error("Error Malloc", 1, data, line);
	if (error_start_line(tab, data, line) == 0)
		return (0);
	if (tab[count_word][ft_strlen(tab[count_word]) - 1] == LABEL_CHAR)
	{
		if (check_label(tab, count_word, 0, 0) == -1)
			asm_error("Bad Label", 2, data, line);
		else
			++count_word;
	}
	check_instruction(tab, count_word, data, line);
	if (tab[count_word + 2] != NULL && tab[count_word + 2][0] != COMMENT_CHAR)
		asm_error("One instruction by line", 2, data, line);
	ft_word_tab_free(tab);
	return (1);
}
