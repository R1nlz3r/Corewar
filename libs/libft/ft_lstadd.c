/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:00:27 by kda-silv          #+#    #+#             */
/*   Updated: 2016/12/12 17:01:16 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (alst != NULL && new != NULL)
	{
		tmp = *alst;
		*alst = new;
		new->next = tmp;
	}
}
