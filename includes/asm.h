/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:31:04 by cyrillef          #+#    #+#             */
/*   Updated: 2017/12/07 19:18:46 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"
#include "op.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** structure
*/

typedef	struct		s_data
{
	t_header		header;
	int				line;
}					t_data;

/*
** parsing_champ.c
*/
void			parsing_champ(int fd, t_data *data);

/*
** error.c
*/
void			header_error(char *cmd, int id, t_data *data);
void			asm_error(char *error, int flag, t_data *data);

#endif
