/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_ups_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 16:19:16 by kda-silv          #+#    #+#             */
/*   Updated: 2017/09/12 17:29:18 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		real_space_write(int precision, int len, int size
					, t_printf_data **data)
{
	int			count;

	count = -1;
	if (precision < size)
		while (++count < (size - precision - 1))
		{
			if ((*data)->zero[0] == 2)
				len += write(1, "0", 1);
			if ((*data)->zero[0] == 1)
				len += write(1, " ", 1);
		}
	return (len);
}

static int		real_space(int precision, int len, wchar_t *s
					, t_printf_data **data)
{
	int			size;
	int			count;
	char		*bin;

	size = 0;
	while (size < precision)
	{
		count = -1;
		if ((bin = ft_longlong_to_binaire((unsigned long long)s[++count]))
			== NULL)
			return (-1);
		size += ((int)ft_strlen(bin) / 8) + 1;
		if (((int)ft_strlen(bin) % 8) != 0)
			++size;
		free(bin);
	}
	return (real_space_write(precision, len, size, data));
}

static int		count_for_write(wchar_t *s)
{
	char		*bin;
	int			count;
	int			tmp;

	count = -1;
	if ((int)s[++count] > 177)
	{
		if ((bin = ft_longlong_to_binaire((unsigned long long)s[count]))
			== NULL)
			return (-1);
		tmp = ((int)ft_strlen(bin) / 8) + 1;
		if (((int)ft_strlen(bin) % 8) != 0)
			++tmp;
		free(bin);
	}
	else
		tmp = 1;
	return (tmp);
}

static int		do_write(int size, int len, wchar_t *s)
{
	int			tmp;
	int			tmp2;
	int			count;

	count = -1;
	tmp = 0;
	while (0 < size)
	{
		++count;
		if ((tmp2 = count_for_write(s)) == -1)
			return (-1);
		if (size >= tmp2)
		{
			if ((tmp = ft_wputchar(s[count])) == -1)
				return (-1);
			len += tmp;
		}
		size -= tmp;
	}
	return (len);
}

int				write_wchar(wchar_t *s, int len, int size, t_printf_data **data)
{
	int			count;
	int			tmp;

	count = -1;
	if (size == -200)
		while (s[++count] != '\0')
		{
			if ((tmp = ft_wputchar(s[count])) == -1)
				return (-1);
			len += tmp;
		}
	else
	{
		if (((*data)->zero[0] == 1 || (*data)->zero[0] == 2)
			&& (*data)->zero[2] == 0)
			if ((len = real_space(size, len, s, data)) == -1)
				return (-1);
		if ((len = do_write(size, len, s)) == -1)
			return (-1);
	}
	return (len);
}
