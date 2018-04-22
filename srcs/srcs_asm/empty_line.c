/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 14:48:22 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/19 14:49:31 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				empty_line(char *line)
{
	int			count;
	int			count2;

	count = -1;
	count2 = 0;
	while (line[++count] != '\0')
	{
		if (line[count] == COMMENT_CHAR)
			return (count2);
		if (line[count] != ' ' && line[count] != '\t'
			&& line[count] != '\n')
			++count2;
	}
	return (count2);
}
