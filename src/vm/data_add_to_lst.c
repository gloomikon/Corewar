/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_add_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:40:43 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/17 15:42:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	add_champ(t_champ **lst, t_champ *new)
{
	t_champ *curr;

	if (!(*lst))
		*lst = new;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}

void	add_carriage(t_carriage **lst, t_carriage *new)
{
	new->next = *lst;
	*lst = new;
}
