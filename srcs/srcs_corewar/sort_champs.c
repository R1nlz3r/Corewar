/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 11:32:01 by cfrouin           #+#    #+#             */
/*   Updated: 2018/04/21 11:35:00 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				swap_champions(t_data *data,
									t_champion *ch1, t_champion *ch2)
{
	ch2 = ch1->next;
	if (ch1 == data->champions)
		data->champions = ch2;
	ch1->next = ch2->next;
	ch2->prev = ch1->prev;
	if (ch1->prev != NULL)
		ch1->prev->next = ch2;
	if (ch2->next != NULL)
		ch2->next->prev = ch1;
	ch1->prev = ch2;
	ch2->next = ch1;
}

void				sort_champions(t_data *data)
{
	int				flag;
	t_champion		*champ;

	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		champ = data->champions;
		while (champ)
		{
			if (champ->next && champ->next->number < champ->number)
			{
				flag = 1;
				swap_champions(data, champ, champ->next);
			}
			champ = champ->next;
		}
	}
}
