/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_add_to_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:40:07 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/15 18:35:15 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		add_entity(t_entity **lst, t_entity *new)
{
	t_entity	*tmp;


	if (*lst)
	{

		tmp = *lst;

		while (tmp->next)
			tmp = tmp->next;

		if (!(new->class == ENDLINE && tmp->class == ENDLINE))
		{

			tmp->next = new;
		}
		else
		{

			free(new);
		}

	}
	else
	{

		if (!(new->class == ENDLINE))
			*lst = new;
		else
			free(new);

	}
}

void		add_label(t_label **labels, t_label *new)
{
	t_label *tmp;

	if (!(*labels))
		*labels = new;
	else
	{
		tmp = *labels;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		add_mention(t_mention **mentions, t_mention *new)
{
	t_mention *tmp;

	if (!(*mentions))
		*mentions = new;
	else
	{
		tmp = *mentions;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
