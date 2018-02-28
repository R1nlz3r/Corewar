/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:42:13 by kda-silv          #+#    #+#             */
/*   Updated: 2018/02/28 14:10:49 by cyrillefrouin    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_word_tab_free(char **tab)
{
	int			count;

	count = -1;
	while (tab[++count] != NULL)
		free(tab[count]);
	free(tab);
}

static int		strlen_words(char *str, char c1, char c2)
{
	int			count;
	int			nb;
	int			size;

	count = 0;
	nb = 0;
	size = ft_strlen(str);
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

char			**ft_word_tab(char *str)
{
	char		**tab;
	int			nbr_word;
	int			count;
	int			count_tab;
	int			tmp;

	nbr_word = strlen_words(str, ' ', '\t');
	if ((tab = malloc((nbr_word + 1) * sizeof(char*))) == NULL)
		return (NULL);
	count = 0;
	count_tab = 0;
	while (count < (int)ft_strlen(str))
	{
		while (str[count] == ' ' || str[count] == '\t')
			++count;
		if (str[count] == '\0')
			break;
		tmp = count;
		while (str[tmp] != '\0' && str[tmp] != ' ' && str[tmp] != '\t')
			++tmp;
		if ((tab[count_tab] = malloc((tmp - count) * sizeof(char))) == NULL)
			return (NULL);
		++count_tab;
	}
	tab[count_tab] = NULL;
	return (tab);
}
