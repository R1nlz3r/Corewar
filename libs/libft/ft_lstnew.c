/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:14:08 by kda-silv          #+#    #+#             */
/*   Updated: 2017/06/08 19:36:55 by kda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;
	void		*ptr;

	if ((list = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->next = NULL;
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
		return (list);
	}
	if ((ptr = malloc(content_size)) == NULL)
		return (NULL);
	list->content = ft_memcpy(ptr, (void *)(uintptr_t)content, content_size);
	list->content_size = content_size;
	return (list);
}
