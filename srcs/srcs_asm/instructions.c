/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:50:26 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/02 18:59:57 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_label(char **tab, int count_word, int count, int mode)
{
	char		*tmp;
	int			flag;
	int			count2;

	if (mode == 0 && count_word != 0)
		return (-1);
	tmp = LABEL_CHARS;
	while (tab[count_word][++count] != '\0'
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

static void		arguments(char **tab, int count_word, t_data *data, char *line)
{
	int			count;

	count = 0;
	while (tab[count_word][count] != '\0')
	{
		if (tab[count_word][count] == 'r')
		{
			++count;
			printf("%d\n", atoi((tab[count_word] + count)));
			if (atoi((tab[count_word] + count)) < 0
				|| atoi((tab[count_word] + count)) > REG_NUMBER)
				asm_error("Bad registre", 2, data, line);
			while (tab[count_word][count] >= '0'
				&& tab[count_word][count] <= '9')
				++count;
			if (tab[count_word][count] != '\0'
				&& tab[count_word][count] != SEPARATOR_CHAR)
				asm_error("Bad registre", 2, data, line);
			if (tab[count_word][count] == SEPARATOR_CHAR)
				++count;
		}
		if (tab[count_word][count] == DIRECT_CHAR)
		{
			++count;
			if (tab[count_word][count] == LABEL_CHAR)
			{
				if (check_label(tab, count_word, ++count, 1) == -1)
					asm_error("Bad Label", 2, data, line);
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
						asm_error("Bad registre", 2, data, line);
			}
		}
		++count;
	}
}

static void		error_label(char **tab, t_data *data, char *line)
{
	int			count;

	count = 0;
	while (tab[0][count] != '\0' && tab[0][count] != LABEL_CHAR)
		++count;
	if (tab[0][count] == LABEL_CHAR && count > 0 && tab[0][count - 1] != '%'
		&& tab[0][count + 1] != '\0')
		asm_error("Bad Label", 2, data, line);
}

void			instructions(char *line, t_data *data)
{
	int			count_word;
	char		**tab;

	count_word = -1;
	bad_char(line, data);
	if ((tab = ft_word_tab(line)) == NULL)
		asm_error("Error Malloc", 1, data, NULL);
	error_label(tab, data, line);
	while (tab[++count_word] != NULL)
	{
		if (tab[count_word][ft_strlen(tab[count_word]) - 1] == LABEL_CHAR)
			if (check_label(tab, count_word, 0, 0) == -1)
				asm_error("Bad Label", 2, data, line);
		if (tab[count_word][0] == 'r' || tab[count_word][0] == DIRECT_CHAR)
			arguments(tab, count_word, data, line);
	}
	ft_word_tab_free(tab);
}
