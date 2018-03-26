/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_tab_asm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 13:29:15 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/26 14:25:26 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		strlen_words(char *str, char c1, char c2)
{
	int			count;
	int			nb;
	int			size;

	count = 0;
	nb = 0;
	size = (int)ft_strlen(str);
	while (count < size)
	{
		while (str[count] == c1 || str[count] == c2)
			++count;
		if (str[count] != '\0')
			++nb;
		while (str[count] != '\0' && str[count] != c1 && str[count] != c2)
			++count;
	}
	return (nb);
}

static char	**copy_word(char *str, char **tab, int count, int count_tab)
{
	int		tmp;
	int		len;
	int		count2;

	tmp = count - 1;
	len = 0;
	while (str[++tmp] != '\0' && str[tmp] != ' ' && str[tmp] != '\t')
		++len;
	if ((tab[count_tab] = malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	count2 = count - 1;
	len = -1;
	while (str[++count2] != '\0' && str[count2] != ' ' && str[count2] != '\t')
		if (str[count2] != '@')
			tab[count_tab][++len] = str[count2];
	tab[count_tab][len + 1] = '\0';
	return (tab);
}

static char		**fill_tab(char *str, char **tab, int count, int count_tab)
{
	while (count < (int)ft_strlen(str))
	{
		while (str[count] == ' ' || str[count] == '\t')
			++count;
		if (str[count] == '\0')
			break ;
		if ((tab = copy_word(str, tab, count, count_tab)) == NULL)
			return (NULL);
		while (str[count] != '\0' && str[count] != ' ' && str[count] != '\t')
			++count;
		++count_tab;
	}
	tab[count_tab] = NULL;
	return (tab);
}

char			**ft_word_tab_asm(char *str)
{
	char		**tab;
	int			nbr_word;
	int			count;
	int			tmp;

	count = -1;
	while (str[++count]  != '\0')
	{
		if (str[count] == ',')
		{
			tmp = count;
			while (--tmp > 0 && (str[tmp] == ' ' || str[tmp] == '\t'))
				str[tmp] = '@';
			tmp = count;
			while (str[++tmp] != '\0' && (str[tmp] == ' ' || str[tmp] == '\t'))
				str[tmp] = '@';
		}
	}
	nbr_word = strlen_words(str, ' ', '\t');
	if ((tab = malloc((unsigned long)(nbr_word + 1) * sizeof(char*))) == NULL)
		return (NULL);
	return (fill_tab(str, tab, 0, 0));
}
