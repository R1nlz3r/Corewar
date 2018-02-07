/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 23:34:24 by mapandel          #+#    #+#             */
/*   Updated: 2018/02/07 20:03:12 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		set_mode(int want_key)
{
	static struct termios	old;
	static struct termios	new;

	if (!want_key)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &old);
		return;
	}
	tcgetattr(STDIN_FILENO, &old);
	new = old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &new);
}

static int		get_key()
{
	int				c;
	struct timeval	tv;
	fd_set			fs;

	c = 0;
	tv.tv_sec = 0;
	tv.tv_usec = 0;
	FD_ZERO(&fs);
	FD_SET(STDIN_FILENO, &fs);
	select(STDIN_FILENO + 1, &fs, 0, 0, &tv);
	if (FD_ISSET(STDIN_FILENO, &fs))
	{
		c = getchar();
		set_mode(0);
	}
	return c;
}

void			key_hub(t_data *data)
{
	int		c;

	set_mode(1);
	c = get_key();
	if (c == 113)
	{
		ft_putstr("\033[H\033[J\e[?25h");
		exit(0); //FREE
	}
	else if (c == 97 && data->speed != 1)
		data->speed /= 2;
	else if (c == 100 && data->speed < 1024)
		data->speed *= 2;
	else if (c == 32 && data->pause)
		data->pause = 0;
	else if (c == 32)
		data->pause = 1;
}
