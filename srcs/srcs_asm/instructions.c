/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:50:26 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/01 18:16:36 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_label(char **tab, int count_word, int count)
{
	char		*tmp;
	int			flag;
	int			count2;

	if (count_word != 0)
		return (-1);
	tmp = LABEL_CHARS;
	--count;
	while (tab[count_word][++count] != '\0' || tab[count_word][count] != ','
		|| tab[count_word][count] != ':')
	{
		flag = 0;
		count2 = -1;
		while (tmp[++count2] != '\0')
			if (tmp[count2] == tab[count_word][count])
				++flag;
		if (flag == 0)
			return (-1);
	}
	return (1);
}

void			instructions(char *line, t_data *data)
{
	int			count_word;
	char		**tab;

	count_word = -1;
	bad_char(line, data);
	if ((tab = ft_word_tab(line)) == NULL)
		asm_error("Error Malloc", 1, data, NULL);
	while (tab[++count_word] != NULL)
	{
		if (tab[count_word][ft_strlen(tab[count_word]) - 1] == ':')
			if (check_label(tab, count_word, 0) == -1)
			{
				asm_error("", 0, data, NULL);
				asm_error("Bad Label", 1, data, line);
			}
	}
	ft_word_tab_free(tab);
}
