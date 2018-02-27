/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:50:26 by kda-silv          #+#    #+#             */
/*   Updated: 2018/02/26 17:51:24 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		chack_label(char **tab, t_data *data, int count_word)
{

}

void			instructions(char *line, t_data *data)
{
	int			count_word;
	bool		flag;
	char		**tab;

	count_word = -1;
	flag = 0;
	bad_char(line, data);
	(void)tab;
	if ((tab = ft_word_tab) == NULL)
		asm_error("Error Malloc", 1, data, NULL);
	while (tab[++count_word] == NULL)
	{
		if (tab[count_word][ft_strlen(tab[count_word]) - 1] == ':')
			count_word = check_label(tab, data, count_word);
	}
	ft_word_tab_free(tab);*/
}
