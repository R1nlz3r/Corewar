/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:54:35 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/18 16:48:28 by kda-silv         ###   ########.fr       */
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
			if (data->args[count] != DIR && data->args[count] != INDIR)
				asm_error("Ld: Not DIRECT or INDIRECT Argument", 2, data, line);
		}
		else if (count == 1)
		{
			if (data->args[count] != REG)
				asm_error("Ld: Not REGISTRE Argument", 2, data, line);
		}
		else
		{
			if (data->args[count] != -1)
				asm_error("Ld: Need 2 Arguments", 2, data, line);
		}
}

void			ld(t_data *data, char *line, char **tab, int count_word)
{
	if (tab[count_word] == NULL)
		asm_error("Ld: Argument missed", 2, data, line);
	if (tab[count_word][0] == 'r' || tab[count_word][0] == DIRECT_CHAR
		|| tab[count_word][0] == LABEL_CHAR || tab[count_word][0] == '-'
		|| (tab[count_word][0] >= '0' && tab[count_word][0] <= '9'))
		check_args(tab, count_word, data, line);
	else
		asm_error("Ld: Bad Arguments", 2, data, line);
	good_args(data, line);
}
