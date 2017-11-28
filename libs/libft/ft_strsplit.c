/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:35:52 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:30:48 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strsize(int count, const char *s, char c)
{
	size_t		size;

	size = 0;
	while (s[count] != '\0' && s[count] != c)
	{
		++size;
		++count;
	}
	return (size + 1);
}

static char		*ft_fillcase(int count, const char *s, char c)
{
	char		*str;
	int			count2;

	count2 = 0;
	if ((str = malloc(ft_strsize(count, s, c) * sizeof(char))) == NULL)
		return (NULL);
	while (s[count] != '\0' && s[count] != c)
	{
		str[count2] = s[count];
		++count2;
		++count;
	}
	str[count2] = '\0';
	return (str);
}

static char		**ft_filltab(char **tab, const char *s, char c)
{
	int			count;
	int			here;

	count = 0;
	here = -1;
	while (s[count] != '\0')
	{
		while (s[count] == c)
			++count;
		if (s[count] != c && s[count] != '\0')
		{
			++here;
			if ((tab[here] = ft_fillcase(count, s, c)) == NULL)
				return (NULL);
			while (s[count] != '\0' && s[count] != c)
				++count;
		}
		if (s[count] != '\0')
			++count;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			count;
	size_t		size;

	count = 0;
	size = 0;
	if (s == NULL)
		return (NULL);
	while (s[count] != '\0')
	{
		while (s[count] == c)
			++count;
		if (s[count] != c && s[count] != '\0')
		{
			++size;
			while (s[count] != '\0' && s[count] != c)
				++count;
		}
		if (s[count] != '\0')
			++count;
	}
	if ((tab = malloc((size + 1) * sizeof(char *))) == NULL)
		return (NULL);
	tab[size] = NULL;
	return (ft_filltab(tab, s, c));
}
