/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar_write.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 18:02:33 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/06 18:02:47 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				*fill_octet(int size, char *mask, int *octet)
{
	int					count;
	int					count2;
	char				*tmp;

	count = -1;
	while (++count < size)
	{
		if ((tmp = malloc(9 * sizeof(char))) == NULL)
			return (NULL);
		tmp[8] = '\0';
		if (ft_strncpy(tmp, mask, 8) == NULL)
			return (NULL);
		if (mask[8] != '\0')
		{
			count2 = 7;
			while (mask[++count2] != '\0')
				mask[count2 - 8] = mask[count2];
			mask[count2 - 8] = '\0';
		}
		octet[count] = ft_convert_bin_to_decimal(tmp);
		free(tmp);
	}
	return (octet);
}

int						write_octet(char *mask)
{
	int					len;
	int					size;
	int					count;
	int					*octet;

	size = (int)ft_strlen(mask) / 8;
	if ((octet = malloc((size_t)(size + 1) * (size_t)sizeof(int))) == NULL)
		return (-1);
	octet[size] = -1;
	if ((octet = fill_octet(size, mask, octet)) == NULL)
		return (-1);
	len = 0;
	count = -1;
	while (octet[++count] != -1)
		len += write(1, &(octet[count]), 1);
	free(octet);
	return (len);
}
