/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar_mask.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 18:00:34 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/06 21:29:01 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*fill_mask(char *mask, char *bin)
{
	int					count;
	int					count2;

	count = (int)ft_strlen(mask);
	count2 = (int)ft_strlen(bin);
	while (--count > 0)
	{
		if (mask[count] == '2' && count2 > 0)
			mask[count] = bin[--count2];
		if (mask[count] == '2' && count2 <= 0)
			mask[count] = '0';
	}
	return (mask);
}

static char				*choose_mask(int size, char *bin, char **mask)
{
	char				*good_mask;

	if (size <= 7)
		good_mask = fill_mask(mask[0], bin);
	else if (size <= 11)
		good_mask = fill_mask(mask[1], bin);
	else if (size <= 16)
		good_mask = fill_mask(mask[2], bin);
	else
		good_mask = fill_mask(mask[3], bin);
	return (good_mask);
}

static char				**mask_base(char **mask)
{
	mask[1][2] = '0';
	mask[1][9] = '0';
	mask[2][3] = '0';
	mask[2][9] = '0';
	mask[2][17] = '0';
	mask[3][4] = '0';
	mask[3][9] = '0';
	mask[3][17] = '0';
	mask[3][25] = '0';
	mask[1][0] = '1';
	mask[1][1] = '1';
	mask[1][8] = '1';
	mask[2][0] = '1';
	mask[2][1] = '1';
	mask[2][2] = '1';
	mask[2][8] = '1';
	mask[2][16] = '1';
	mask[3][0] = '1';
	mask[3][1] = '1';
	mask[3][2] = '1';
	mask[3][3] = '1';
	mask[3][8] = '1';
	mask[3][16] = '1';
	mask[3][24] = '1';
	return (mask);
}

static char				**create_mask(void)
{
	char				**mask;
	int					count;
	int					count2;
	int					count3;

	if ((mask = malloc(5 * sizeof(char *))) == NULL)
		return (NULL);
	count = -1;
	count2 = 0;
	while (++count < 4)
	{
		if ((mask[count] = malloc((size_t)((count2 += 8) + 1)
			* (size_t)sizeof(char))) == NULL)
			return (NULL);
		count3 = -1;
		while (++count3 < count2)
			mask[count][count3] = '2';
		mask[count][count3] = '\0';
	}
	mask[count] = NULL;
	mask[0][0] = '0';
	return (mask_base(mask));
}

int						ft_wputchar(wchar_t c)
{
	char				*bin;
	int					count;
	int					len;
	char				**mask;

	if ((bin = ft_longlong_to_binaire((unsigned long long)c)) == NULL)
		return (-1);
	if ((mask = create_mask()) == NULL)
		return (-1);
	if ((len = write_octet(choose_mask((int)ft_strlen(bin), bin, mask))) == -1)
		return (-1);
	count = -1;
	while (++count < 4)
		free(mask[count]);
	free(mask);
	free(bin);
	return (len);
}
