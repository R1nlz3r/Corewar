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

void		instructions(char *line, t_data *data)
{
	int			count;
	bool		flag;

	count = -1;
	flag = 0;
	printf("%s\n", line);
	bad_char(line, data);
}
