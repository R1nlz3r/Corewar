/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:07:14 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/17 18:12:04 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	size_args(t_data *data, int line, int word, int size)
{
	int		count;
	int		tmp;

	count = -1;
	while (data->tab[line][word][++count] != '\0')
	{
		if (count == 0 || data->tab[line][word][count - 1] == SEPARATOR_CHAR)
		{
			tmp = ft_atoi(data->tab[line][word] + count + 1);
			if (data->tab[line][word][count] == 'r')
				++size;
			else if (data->tab[line][word][count] == DIRECT_CHAR)
				size += size_direct(data, line, word);
			else
				size += 2;
		}
	}
	return (size);
}

int			size_function(t_data *data, int line)
{
	int				size;
	int				word;

	size = 1;
	word = 0;
	if (data->tab[line][word][ft_strlen(data->tab[line][word]) - 1]
		== LABEL_CHAR)
		++word;
	if (data->tab[line][word] == NULL)
		return (0);
	if (ft_strcmp(data->tab[line][word], "live") != 0
		&& ft_strcmp(data->tab[line][word], "fork") != 0
		&& ft_strcmp(data->tab[line][word], "zjmp") != 0
		&& ft_strcmp(data->tab[line][word], "lfork") != 0)
		++size;
	++word;
	return (size_args(data, line, word, size));
}
