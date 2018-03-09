/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 16:27:25 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/09 18:34:10 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			check_args(char **tab, int count_word, t_data *data, char *line)
{
	int			count;
	int			count2;

	count = 0;
	count2 = 0;
	while (tab[count_word][count] != '\0')
	{
		if (tab[count_word][count] == 'r')
		{
			++count;
			if (!(tab[count_word][count] >= '0'
				&& tab[count_word][count] <= '9'))
				asm_error("Bad registre", 2, data, line);
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
			if (count2 > 2)
				asm_error("Too Many Arguments", 2, data, line);
			else
				data->args[count2] = REG;
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
			if (count2 > 2)
				asm_error("Too Many Arguments", 2, data, line);
			else
				data->args[count2] = DIR;
			if (tab[count_word][count] == '\0')
				break ;
		}
		if (tab[count_word][count] == '-' || (tab[count_word][count] >= '0'
			&& tab[count_word][count] <= '9'))
		{
			while (tab[count_word][++count] != '\0'
				&& tab[count_word][count] != SEPARATOR_CHAR)
				if (!(tab[count_word][count] >= '0'
					&& tab[count_word][count] <= '9'))
					asm_error("Bad registre", 2, data, line);
			if (count2 > 2)
				asm_error("Too Many Arguments", 2, data, line);
			else
				data->args[count2] = INDIR;
		}
		++count;
	}
}
