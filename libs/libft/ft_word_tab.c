/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:42:13 by kda-silv          #+#    #+#             */
/*   Updated: 2018/03/01 14:42:43 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_word_tab_free(char **tab)
{
	(void)tab;
/*	int			count;

	count = -1;
	while (tab[++count] != NULL)
		free(tab[count]);
	free(tab);*/
}
//test
static int		strlen_words(char *str, char c1, char c2)
{
	(void)str;
	(void)c1;
	(void)c2;
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
//test
char			**ft_word_tab(char *str)
{
	(void)str;
	char		**tab;
	int			nbr_word;
	int			count;
	int			count_tab;
	int			tmp;

	nbr_word = strlen_words(str, ' ', '\t');
	if ((tab = malloc((unsigned long)(nbr_word + 1) * sizeof(char*))) == NULL)
		return (NULL);
	count = 0;
	count_tab = 0;
	while (count < (int)ft_strlen(str))
	{
		while (str[count] == ' ' || str[count] == '\t')
			++count;
			//test si on est bien au premier char d'un mot
		if (str[count] == '\0')
			break;
		tmp = count;
		while (str[tmp] != '\0' && str[tmp] != ' ' && str[tmp] != '\t')
			++tmp;
//test verif tmp-count = taille du mot
		if ((tab[count_tab] = malloc((unsigned long)(tmp - count) * sizeof(char))) == NULL)
			return (NULL);
		if ((tab[count_tab] = ft_strncpy(tab[count_tab], str + count, (size_t)(tmp - count))) == NULL)
			return (NULL);
		//verif la copie
		++count_tab;
	}
	tab[count_tab] = NULL;
	return (tab);
}
