/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 17:06:52 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:23:40 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			clean_leaks(t_printf_data *data)
{
	free(data->flags);
	free(data);
}

static char			*init_flags2(char *flags)
{
	flags[19] = 'U';
	flags[20] = 'O';
	flags[21] = 'b';
	flags[22] = '\0';
	return (flags);
}

static char			*init_flags(void)
{
	char			*flags;

	if ((flags = ft_strnew(22)) == NULL)
		return (NULL);
	flags[0] = '0';
	flags[1] = '0';
	flags[2] = 'c';
	flags[3] = 'C';
	flags[4] = 's';
	flags[5] = 'S';
	flags[6] = 'd';
	flags[7] = 'i';
	flags[8] = 'w';
	flags[9] = 'r';
	flags[10] = 'u';
	flags[11] = 'o';
	flags[12] = 'x';
	flags[13] = 'X';
	flags[14] = '.';
	flags[15] = '#';
	flags[16] = 'p';
	flags[17] = '%';
	flags[18] = 'D';
	return (init_flags2(flags));
}

int					ft_printf(const char *str, ...)
{
	t_printf_data	*data;
	int				len;

	if ((data = malloc(sizeof(t_printf_data))) == NULL)
		return (-1);
	if ((data->flags = init_flags()) == NULL)
		return (-1);
	va_start(data->ap, str);
	if ((data = init_functions(data)) == NULL)
		return (-1);
	data->len = 0;
	reinit_data(&data);
	data->str = (char *)(uintptr_t)str;
	if (run_printf(&data) == -1)
		return (-1);
	va_end(data->ap);
	len = data->len;
	clean_leaks(data);
	return (len);
}
