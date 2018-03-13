/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:55:08 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/13 17:23:07 by kda-silv         ###   ########.fr       */
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
			if (data->args[count] != REG)
				asm_error("St: Not REGISTRE Argument", 2, data, line);
		}
		else if (count == 1)
		{
			if (data->args[count] != REG && data->args[count] != INDIR)
				asm_error("St: Not REGISTRE or INDIRECT Argument"
					, 2, data, line);
		}
		else
		{
			if (data->args[count] != -1)
				asm_error("St: Only 2 Arguments", 2, data, line);
		}
}

void			st(t_data *data, char *line, char **tab, int count_word)
{
	if (tab[count_word] == NULL)
		asm_error("St: Argument missed", 2, data, line);
	if (tab[count_word][0] == 'r' || tab[count_word][0] == DIRECT_CHAR
		|| tab[count_word][0] == '-'
		|| (tab[count_word][0] >= '0' && tab[count_word][0] <= '9'))
		check_args(tab, count_word, data, line);
	else
		asm_error("St: Bad Arguments", 2, data, line);
	good_args(data, line);
}
