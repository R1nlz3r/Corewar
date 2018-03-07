/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:31:04 by cyrillef          #+#    #+#             */
/*   Updated: 2018/03/07 20:09:44 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"
#include "op.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

# define GOOD_CHAR "abcdefghijklmnopqrstuvwxyz_0123456789:,% \t#-"
# define REG 0
# define INDIR 1
# define DIR 2

/*
** structure
*/

typedef	struct		s_data
{
	t_header		header;
	bool			name;
	bool			comment;
	int				line;
	int				check_cmd;
	int				args[3];
}					t_data;

/*
** do_cor.c
*/
void			do_cor(t_data *data, char *source);

/*
** parsing_champ.c
*/
void				parsing_champ(int fd, t_data *data);

/*
** header.c
*/
void			header(char *line, t_data *data);

/*
** instructions.c
*/
int				instructions(char *line, t_data *data);

/*
** error.c
*/
void			bad_char(char *line, t_data *data);
void			header_error(char *cmd, int id, t_data *data, char *str);
void			asm_error(char *error, int flag, t_data *data, char *str);

#endif
