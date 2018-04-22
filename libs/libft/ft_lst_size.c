/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:26:48 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/12 16:29:57 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lst_size(t_list *lst)
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}
