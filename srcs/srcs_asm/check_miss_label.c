/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_miss_label.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:57:37 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/20 22:25:17 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		same_label(t_data *data, char *name)
{
	int			count;
	int			flag;

	flag = 0;
	count = -1;
	while (data->labels[++count] != NULL)
		if (ft_strcmp(name, data->labels[count]) == 0)
			++flag;
	return (flag);
}

static void		new_tab_labels(t_data *data, char *name)
{
	if ((data->labels = malloc(2 * sizeof(char *))) == NULL)
		asm_error("Error malloc", 1, data, name);
	if ((data->labels[0] = malloc((ft_strlen(name) + 1) * sizeof(char)))
		== NULL)
		asm_error("Error malloc", 1, data, name);
	data->labels[0] = ft_strcpy(data->labels[0], name);
	data->labels[1] = NULL;
}

static void		realloc_labels(t_data *data, char *name, int count)
{
	char		**tmp;

	if (same_label(data, name) > 0)
		return ;
	while (data->labels[count] != NULL)
		++count;
	if ((tmp = malloc((count + 2) * sizeof(char *))) == NULL)
		asm_error("Error malloc", 1, data, name);
	count = -1;
	while (data->labels[++count] != NULL)
	{
		if ((tmp[count] = malloc((ft_strlen(data->labels[count]) + 1)
			* sizeof(char))) == NULL)
			asm_error("Error malloc", 1, data, name);
		tmp[count] = ft_strcpy(tmp[count], data->labels[count]);
	}
	if ((tmp[count] = malloc((ft_strlen(name) + 1) * sizeof(char))) == NULL)
		asm_error("Error malloc", 1, data, name);
	tmp[count] = ft_strcpy(tmp[count], name);
	tmp[count + 1] = NULL;
	ft_word_tab_free(data->labels);
	data->labels = tmp;
}

static void		take_labels(t_data *data, int line, int word, int count)
{
	char		*name;

	name = name_label(data, line, word, count + 1);
	if (data->labels == NULL)
		new_tab_labels(data, name);
	else
		realloc_labels(data, name, 0);
	free(name);
}

void			check_miss_label(t_data *data)
{
	int			line;
	int			word;
	int			count;

	line = -1;
	while (data->tab[++line] != NULL)
	{
		word = 0;
		if (data->tab[line][word][ft_strlen(data->tab[line][word]) - 1]
			== LABEL_CHAR)
			++word;
		if (data->tab[line][word] == NULL)
			continue ;
		++word;
		count = -1;
		while (data->tab[line][word][++count] != '\0')
			if (data->tab[line][word][count + 1] == LABEL_CHAR)
				take_labels(data, line, word, count);
	}
	if (data->labels != NULL)
		search_label(data);
}
