/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_label.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:52:53 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/20 16:23:00 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			search_label(t_data *data)
{
	int			line;
	int			count;
	int			flag;

	count = -1;
	while (data->labels[++count] != NULL)
	{
		line = -1;
		flag = 0;
		while (data->tab[++line] != NULL)
			if (ft_strcmp(data->tab[line][0], data->labels[count]) == 0)
				++flag;
		if (flag == 0)
		{
			ft_putstr_fd(RED, 2);
			ft_putstr_fd("Error Label: ", 2);
			data->labels[count][ft_strlen(data->labels[count]) - 1] = '\0';
			ft_putstr_fd(data->labels[count], 2);
			asm_error(" is missing", 1, data, NULL);
		}
	}
}
