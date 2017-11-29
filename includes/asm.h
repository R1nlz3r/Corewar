/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:31:04 by cyrillef          #+#    #+#             */
/*   Updated: 2017/11/29 18:45:21 by kda-silv         ###   ########.fr       */
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
}					t_data;

/*
** parsing_champ.c
*/
void			parsing_champ(int fd, t_data *data);

/*
** error.c
*/
void			asm_error(char *error);

#endif
