/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:23:20 by cyrillef          #+#    #+#             */
/*   Updated: 2018/04/22 16:58:19 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <termios.h>

# include "libft.h"
# include "op.h"

extern char				g_hex_tab[];
extern t_op				g_op_tab[];

typedef struct			s_node
{
	int					id;
	int					player;
	char				content[3];
	short				contentn;

	struct s_node		*next;
	struct s_node		*prev;
}						t_node;

typedef struct			s_champion
{
	bool				carry;
	int					lastlive;
	int					livenbr;
	t_node				*oldpc;
	int					oldipc;
	t_node				*pc;
	int					ipc;
	char				name[PROG_NAME_LENGTH + 1];
	bool				alive;
	unsigned int		number;
	int					nextop;
	t_op				op;
	char				*filename;
	unsigned int		size;
	unsigned char		code[MEM_SIZE];
	char				comment[COMMENT_LENGTH + 1];
	char				reg[REG_NUMBER + 2];
	char				argstype[3];
	int					args[3];

	struct s_champion	*prev;
	struct s_champion	*next;
}						t_champion;

typedef struct			s_data
{
	int					stealth;
	int					verbose;
	int					debug;
	int					dump;
	int					graph;
	t_champion			*champions;
	int					nb_player;
	int					nb_champion;
	t_node				*map;
	unsigned int		live;
	unsigned int		maxcheck;
	unsigned int		cycle;
	unsigned int		cycletodie;
	unsigned int		lastlive;
	bool				pause;
	int					speed;
	bool				aff;
}						t_data;

/*
** debug.c
** Contains all debug functions
*/

void					error(char *msg);
void					dump_state(char *msg, t_data *data, t_champion *champ);

/*
** dump.c
** Manage the -dump arg
*/

void					dump(t_data *data);

/*
** args.c
** Manage different arguments
*/

t_data					*init_data(int ac, char **av);

/*
** sort_champs.c
*/

void					sort_champions(t_data *data);

/*
** check_live.c
** Check living champions after CYCLE_TO_DIE and kill the ones that didn't live
*/

int						check_live(t_data *data);

/*
** get_params.c
** Retrieve parameters for each operation
*/

void					get_params(t_champion *champion);

/*
** read_champion.c
** Read champions files and create each player
*/

int						read_champions(t_data *data);
int						prepare_champion(t_data *data, char *filename,
						int number, bool isfork);

/*
** manage_args.c
** Check program args and change the data struct accordingly
*/

int						manage_args(t_data *data, int ac, char **av);

/*
** init_map.c
** Initialize map and print the code in memory
*/

int						init_map(t_data *data);

/*
** error.c
** Throw error and free data
*/

void					free_data(t_data *data);
void					usage(void);
void					corewar_error(t_data *data, char *str);

/*
** number_to_hex_str.c
** Hexadecimal conversion stuff
*/

int						str_hex_to_number(char str[3]);
void					number_to_hex_str(int n,
											unsigned char (*str)[]);

/*
** do_next_op.c
*/

int						do_next_op(t_data *data);

/*
** prepare_next_op.c
*/

int						prepare_next_op(t_data *data);

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

/*
** display_vm.c
** display_vm_2.c
** Display nodes and stats of the vm
*/

void					display_map(t_data *data);
void					update_legend(t_data *data);
void					update_map(t_data *data);
int						get_sum_livenbr(t_data *data, unsigned int id);

/*
** tty.c
** Change settings of tty and get keys
*/

void					key_hub(t_data *data);
void					set_mode(int want_key);

/*
** Commands
*/

int						corewar_add(t_data *data, t_champion *champ);
int						corewar_aff(t_data *data, t_champion *champ);
int						corewar_and(t_data *data, t_champion *champ);
int						corewar_fork(t_data *data, t_champion *champ);
int						corewar_ld(t_data *data, t_champion *champ);
int						corewar_ldi(t_data *data, t_champion *champ);
int						corewar_lfork(t_data *data, t_champion *champ);
int						corewar_live(t_data *data, t_champion *champ);
int						corewar_lld(t_data *data, t_champion *champ);
int						corewar_lldi(t_data *data, t_champion *champ);
int						corewar_or(t_data *data, t_champion *champ);
int						corewar_st(t_data *data, t_champion *champ);
int						corewar_sti(t_data *data, t_champion *champ);
int						corewar_sub(t_data *data, t_champion *champ);
int						corewar_xor(t_data *data, t_champion *champ);
int						corewar_zjmp(t_data *data, t_champion *champ);
int						corewar_ljmp(t_data *data, t_champion *champ);
t_node					*find_pc_node(t_champion *champ, short pc_dest);
void					write_in_ram(t_champion*champ, short pc_dest);
int						get_mem_32bits(t_champion *champ, int index);
int						ft_atoi_base(const char *str, int base);
int						mem_mod(int n);
int						get_address(int val);
int						mem_address(int val);
int						idx_address(int val);
char					*color_champion(int id, char *s);

#endif
