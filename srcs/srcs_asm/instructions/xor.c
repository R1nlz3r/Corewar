/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:56:52 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/13 17:21:39 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		good_args(t_data *data, char *line)
{
	int			count;

	count = -1;
	while (++count < 3)
		if (count == 0)
		{
			if (data->args[count] == -1)
				asm_error("And: Need 3 Arguments", 2, data, line);
		}
		else if (count == 1)
		{
			if (data->args[count] == -1)
				asm_error("And: Need 3 Arguments", 2, data, line);
		}
		else
		{
			if (data->args[count] != REG)
				asm_error("And: Not REGISTRE Argument", 2, data, line);
		}
}

void			xor(t_data *data, char *line, char **tab, int count_word)
{
	if (tab[count_word] == NULL)
		asm_error("And: Argument missed", 2, data, line);
	if (tab[count_word][0] == 'r' || tab[count_word][0] == DIRECT_CHAR
		|| tab[count_word][0] == '-'
		|| (tab[count_word][0] >= '0' && tab[count_word][0] <= '9'))
		check_args(tab, count_word, data, line);
	else
		asm_error("And: Bad Arguments", 2, data, line);
	good_args(data, line);
}
