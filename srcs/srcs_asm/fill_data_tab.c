/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:42:24 by kda-silv          #+#    #+#             */
/*   Updated: 2018/04/20 22:38:10 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		**copy_tab(t_data *data, char *line, char **dest, char **tab)
{
	int			count;

	count = 0;
	while (tab[count] != NULL)
		++count;
	if ((dest = malloc((count + 1) * sizeof(char *))) == NULL)
		asm_error("Error Malloc", 2, data, line);
	count = 0;
	while (tab[count] != NULL)
	{
		if ((dest[count] = malloc(((ft_strlen(tab[count]) + 1) * sizeof(char))))
			== NULL)
			asm_error("Error Malloc", 2, data, line);
		dest[count] = ft_strcpy(dest[count], tab[count]);
		++count;
	}
	dest[count] = NULL;
	return (dest);
}

static void		new_data_tab(t_data *data, char *line, char **tab)
{
	if ((data->tab = malloc(2 * sizeof(char **))) == NULL)
		asm_error("Error Malloc", 2, data, line);
	data->tab[0] = NULL;
	data->tab[0] = copy_tab(data, line, data->tab[0], tab);
	data->tab[1] = NULL;
}

void			fill_data_tab(t_data *data, char *line, char **tab)
{
	int			len;
	int			count;
	char		***tmp;

	if (data->tab == NULL)
		new_data_tab(data, line, tab);
	else
	{
		len = 0;
		while (data->tab[len] != NULL)
			++len;
		if ((tmp = malloc((len + 2) * sizeof(char **))) == NULL)
			asm_error("Error Malloc", 2, data, line);
		count = -1;
		while (data->tab[++count] != NULL)
			tmp[count] = copy_tab(data, line, tmp[count], data->tab[count]);
		tmp[count] = copy_tab(data, line, tmp[count], tab);
		tmp[count + 1] = NULL;
		count = -1;
		while (data->tab[++count] != NULL)
			ft_word_tab_free(data->tab[count]);
		free(data->tab);
		data->tab = tmp;
	}
}
