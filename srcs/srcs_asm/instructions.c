/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:50:26 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/07 20:10:29 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		check_label(char **tab, int count_word, int count, int mode)
{
	char		*tmp;
	int			flag;
	int			count2;

	if (mode == 0 && count_word != 0)
		return (-1);
	tmp = LABEL_CHARS;
	while (tab[count_word][count] != '\0'
		&& tab[count_word][count] != SEPARATOR_CHAR
		&& tab[count_word][count] != LABEL_CHAR)
	{
		flag = 0;
		count2 = -1;
		while (tmp[++count2] != '\0')
			if (tmp[count2] == tab[count_word][count])
				++flag;
		if (flag == 0)
			return (-1);
		++count;
	}
	if (mode == 1 && tab[count_word][count] != '\0'
		&& tab[count_word][count] != SEPARATOR_CHAR)
		return (-1);
	return (1);
}

static void		arguments(char **tab, int count_word, t_data *data, char *line)
{
	int			count;

	count = 0;
	//printf("nnnn\n");
	while (tab[count_word][count] != '\0')
	{
		//printf("oooo\n");
		if (tab[count_word][count] == 'r')
		{
			//printf("pppp\n");
			++count;
			if (atoi((tab[count_word] + count)) < 0
				|| atoi((tab[count_word] + count)) > REG_NUMBER)
				asm_error("Bad registre", 2, data, line);
				//printf("qqqq\n");
			while (tab[count_word][count] >= '0'
				&& tab[count_word][count] <= '9')
				++count;
			//printf("rrrr\n");
			if (tab[count_word][count] != '\0'
				&& tab[count_word][count] != SEPARATOR_CHAR)
				asm_error("Bad registre", 2, data, line);
			//printf("ssss\n");
			if (tab[count_word][count] == SEPARATOR_CHAR)
				++count;
			//printf("tttt\n");
		}
		if (tab[count_word][count] == DIRECT_CHAR)
		{
			//printf("uuuu\n");
			++count;
			if (tab[count_word][count] == LABEL_CHAR)
			{
				//printf("vvvv\n");
				if (check_label(tab, count_word, ++count, 1) == -1)
					asm_error("Bad Label", 2, data, line);
					//printf("wwww\n");
				while (tab[count_word][count] != '\0'
					&& tab[count_word][count] != SEPARATOR_CHAR)
					++count;
					//printf("xxxx\n");
			}
			else
			{
				//printf("yyyy\n");
				if (tab[count_word][count] == '-')
					++count;
					//printf("zzzz\n");
				--count;
				while (tab[count_word][++count] != '\0'
					&& tab[count_word][count] != SEPARATOR_CHAR)
					if (tab[count_word][count] < '0'
						&& tab[count_word][count] > '9')
						asm_error("Bad registre", 2, data, line);
						//printf("++++\n");
			}
			if (tab[count_word][count] == '-' || (tab[count_word][count] >= '0'
				&& tab[count_word][count] <= '9'))
			{
				while (tab[count_word][++count] != '\0'
					&& tab[count_word][count] != SEPARATOR_CHAR)
					if (!(tab[count_word][count] >= '0'
						&& tab[count_word][count] <= '9'))
						asm_error("Bad registre", 2, data, line);
			}
			//printf("----\n");
			if (tab[count_word][count] == '\0')
				break ;
				//printf("****\n");
		}
		++count;
		//printf("////\n");
	}
	//printf("====\n");
}

static int		error_start_line(char **tab, t_data *data, char *line)
{
	int			count;

	count = 0;
	if (tab[0] == NULL)
		return (0);
	while (tab[0][count] != '\0' && tab[0][count] != LABEL_CHAR)
		++count;
	if (tab[0][count] == LABEL_CHAR && count > 0 && tab[0][count - 1] == '%'
		&& tab[0][count + 1] != '\0')
		asm_error("Bad Label", 2, data, line);
	return (1);
}

int				instructions(char *line, t_data *data)
{
	int			count_word;
	char		**tab;

	count_word = -1;
	bad_char(line, data);
	if ((tab = ft_word_tab(line)) == NULL)
		asm_error("Error Malloc", 1, data, NULL);
	if (error_start_line(tab, data, line) == 0)
		return (0);
	while (tab[++count_word] != NULL)
	{
		if (tab[count_word][0] == COMMENT_CHAR)
			break ;
		if (tab[count_word][ft_strlen(tab[count_word]) - 1] == LABEL_CHAR)
		{
			if (check_label(tab, count_word, 0, 0) == -1)
				asm_error("Bad Label", 2, data, line);
			else
				++count_word;
			if (tab[count_word] == NULL)
				break ;
		}
		if (tab[count_word][0] == 'r' || tab[count_word][0] == DIRECT_CHAR)
			arguments(tab, count_word, data, line);
	}
	ft_word_tab_free(tab);
	return (1);
}
