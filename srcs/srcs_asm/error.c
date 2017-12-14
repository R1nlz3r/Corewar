/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:50:54 by cyrillef          #+#    #+#             */
/*   Updated: 2017/12/13 18:50:04 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			header_error(char *cmd, int id, t_data *data)
{
	if (id == 0)
	{
		asm_error("tmp", 0, data);
		ft_putstr_fd(cmd, 2);
		asm_error(" must be at the beginning of the line", 1, data);
	}
	if (id == 1)
	{
		asm_error("tmp", 0, data);
		ft_putstr_fd("syntaxe muste be: ", 2);
		ft_putstr_fd(cmd, 2);
		asm_error(" \"text\"", 1, data);
	}
}

void			asm_error(char *error, int flag, t_data *data)
{
	char		*line;

	ft_putstr_fd(RED, 2);
	if (flag == 0)
	{
		ft_putstr_fd("Syntaxe error[L", 2);
		line = ft_itoa(data->line);
		ft_putstr_fd(line, 2);
		free(line);
		ft_putstr_fd("]: ", 2);
		return ;
	}
	ft_putstr_fd(error, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	exit(EXIT_FAILURE);
}
