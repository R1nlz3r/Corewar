/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 15:23:20 by cyrillef          #+#    #+#             */
/*   Updated: 2017/12/06 17:25:59 by cyrillefrouin    ###   ########.fr       */
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

static const char		g_hex_tab[] =
{
	'0', '1', '2', '3', '4', '5', '6', '7',
	'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
};

typedef struct			s_champion
{
	unsigned int		magic;
	int					number;
	char				*filename;
	char				name[PROG_NAME_LENGTH + 1];
	unsigned int		size;
	char				comment[COMMENT_LENGTH + 1];
	char				code[1024];

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
}						t_data;

/*
** args.c
*/

t_data					*init_data(int ac, char **av);

/*
** read_champion.c
*/

int						read_champions(t_data *data);

/*
** init_map.c
*/

int						init_map(t_data *data);

/*
** error.c
*/

void					corewar_error(char *str);

/*
** number_to_hex_str.c
*/

void					number_to_hex_str(unsigned char n,
											unsigned char (*str)[]);

#endif
