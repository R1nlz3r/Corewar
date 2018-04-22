/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 17:32:43 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/20 21:09:26 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					size_direct(t_data *data, int line, int word)
{
	if (ft_strcmp("live", data->tab[line][word - 1]) == 0
		|| ft_strcmp("ld", data->tab[line][word - 1]) == 0
		|| ft_strcmp("and", data->tab[line][word - 1]) == 0
		|| ft_strcmp("or", data->tab[line][word - 1]) == 0)
		return (4);
	else if (ft_strcmp("xor", data->tab[line][word - 1]) == 0
		|| ft_strcmp("lld", data->tab[line][word - 1]) == 0)
		return (4);
	else
		return (2);
}

static void			write_2octet(t_data *data, int line, int word, int count)
{
	int				nbr;
	int				tmp;

	if (data->tab[line][word][count] == LABEL_CHAR)
		nbr = write_label(data, line, word, count);
	else
		nbr = ft_atoi(data->tab[line][word] + count);
	tmp = nbr >> 8;
	write(data->fd, &tmp, 1);
	write(data->fd, &nbr, 1);
}

static void			write_direct(t_data *data, int line, int word, int count)
{
	int				nbr;
	int				tmp1;
	int				tmp2;
	int				tmp3;
	int				size;

	size = size_direct(data, line, word);
	if (size == 2)
	{
		write_2octet(data, line, word, count);
		return ;
	}
	if (data->tab[line][word][count] == LABEL_CHAR)
		nbr = write_label(data, line, word, count);
	else
		nbr = ft_atoi(data->tab[line][word] + count);
	tmp1 = nbr >> 8;
	tmp2 = nbr >> 16;
	tmp3 = nbr >> 24;
	write(data->fd, &tmp3, 1);
	write(data->fd, &tmp2, 1);
	write(data->fd, &tmp1, 1);
	write(data->fd, &nbr, 1);
}

static void			do_param(t_data *data, int line, int word)
{
	int				count;
	int				tmp;

	count = -1;
	while (data->tab[line][word][++count] != '\0')
		if (count == 0 || data->tab[line][word][count - 1] == SEPARATOR_CHAR)
		{
			tmp = ft_atoi(data->tab[line][word] + count + 1);
			if (data->tab[line][word][count] == 'r')
				write(data->fd, &tmp, 1);
			else if (data->tab[line][word][count] == DIRECT_CHAR)
				write_direct(data, line, word, (count + 1));
			else
				write_2octet(data, line, word, count);
		}
}

void				do_function(t_data *data, int line)
{
	int				word;
	int				count2;

	word = 0;
	if (data->tab[line][word][ft_strlen(data->tab[line][word]) - 1]
		== LABEL_CHAR)
		++word;
	if (data->tab[line][word] == NULL)
		return ;
	count2 = -1;
	while (++count2 <= 16)
		if (ft_strcmp(g_op_tab[count2].name, data->tab[line][word]) == 0)
		{
			++count2;
			write(data->fd, &count2, 1);
			--count2;
			break ;
		}
	if (ft_strcmp(g_op_tab[count2].name, "live") != 0
		&& ft_strcmp(g_op_tab[count2].name, "fork") != 0
		&& ft_strcmp(g_op_tab[count2].name, "zjmp") != 0
		&& ft_strcmp(g_op_tab[count2].name, "lfork") != 0)
		type_param(data, line, word + 1);
	do_param(data, line, word + 1);
}
