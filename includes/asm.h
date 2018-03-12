/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:31:04 by cyrillef          #+#    #+#             */
/*   Updated: 2018/03/09 18:45:39 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>

# define GOOD_CHAR "abcdefghijklmnopqrstuvwxyz_0123456789:,% \t#-"
# define FC "live ld st add sub and or xor zjmp ldi sti fork lld lldi lfork aff"
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
	void			(*functions[16])(struct s_data *, char *, char**, int);
	int				args[3];
}					t_data;

/*
** do_cor.c
*/
void				do_cor(t_data *data, char *source);

/*
** parsing_champ.c
*/
void				parsing_champ(int fd, t_data *data);

/*
** header.c
*/
void				header(char *line, t_data *data);

/*
** check_core.c
*/
int					check_core(char *line, t_data *data, int count_word);
int					check_label(char **tab, int count_word
						, int count, int mode);

/*
** check_args.c
*/
void				check_args(char **tab, int count_word
						, t_data *data, char *line);

/*
** error.c
*/
void				bad_char(char *line, t_data *data);
void				header_error(char *cmd, int id, t_data *data, char *str);
void				asm_error(char *error, int flag, t_data *data, char *str);

/*
**instructions
*/

void				live(t_data *data, char *line, char **tab, int count_word);
void				ld(t_data *data, char *line, char **tab, int count_word);
void				st(t_data *data, char *line, char **tab, int count_word);
void				add(t_data *data, char *line, char **tab, int count_word);
void				sub(t_data *data, char *line, char **tab, int count_word);
void				and(t_data *data, char *line, char **tab, int count_word);
void				or(t_data *data, char *line, char **tab, int count_word);
void				xor(t_data *data, char *line, char **tab, int count_word);
void				zjmp(t_data *data, char *line, char **tab, int count_word);
void				ldi(t_data *data, char *line, char **tab, int count_word);
void				sti(t_data *data, char *line, char **tab, int count_word);
void				fork_asm(t_data *data, char *line, char **tab
						, int count_word);
void				lld(t_data *data, char *line, char **tab, int count_word);
void				lldi(t_data *data, char *line, char **tab, int count_word);
void				lfork(t_data *data, char *line, char **tab, int count_word);
void				aff(t_data *data, char *line, char **tab, int count_word);

#endif
