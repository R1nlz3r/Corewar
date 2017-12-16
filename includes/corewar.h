/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:23:20 by cyrillef          #+#    #+#             */
/*   Updated: 2017/12/16 16:35:31 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# include "libft.h"
# include "op.h"

extern char				g_hex_tab[];

typedef struct			s_process
{
	unsigned int		id;
	unsigned int		player;
	unsigned int		pos;
	char				carry;
	unsigned int		timeleft;
	unsigned int		lastlive;

	struct s_process	*next;
	struct s_process	*prev;
}						t_process;

typedef struct			s_champion
{
	unsigned int		magic;
	int					lo;
	int					live;
	unsigned int		number;
	char				*filename;
	char				name[PROG_NAME_LENGTH + 1];
	unsigned int		size;
	char				comment[COMMENT_LENGTH + 1];
	char				code[1024];
	t_process			*processes;

	struct s_champion	*prev;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_node
{
	int					id;
	int					player;
	char				content[3];
	int					contentn;

	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef struct			s_data
{
	int					dump;
	t_champion			*champions;
	int					nb_champion;
	t_node				*map;
	unsigned int		live;
	unsigned int		cycle;
	unsigned int		cyclec;
	unsigned int		cycletodie;
	unsigned int		lastlive;
}						t_data;

/*
** args.c
** Manage different arguments
*/

t_data					*init_data(int ac, char **av);

/*
** read_champion.c
** Read champions files and create each player
*/

int						read_champions(t_data *data);

/*
** init_map.c
** Initialize map and print the code in memory
*/

int						init_map(t_data *data);

/*
** init_processes.c
** Initialize each player's process
*/

int						init_processes(t_data *data);

/*
** error.c
** Throw error and free data
*/

void					free_data(t_data *data);
void					corewar_error(t_data *data, char *str);

/*
** number_to_hex_str.c
** Hexadecimal conversion stuff
*/

int						str_hex_to_number(char str[3]);
void					number_to_hex_str(unsigned char n,
											unsigned char (*str)[]);

/*
** vm.c
** Start the VM after everything has been initialized
*/

int						vm_start(t_data *data);

/*
** vm_check_live.c
** Check if champions executed "live" since last checkup and
** kill them if it is needed
*/

int						vm_check_live(t_data *data);

#endif
