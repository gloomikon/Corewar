/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/01 14:42:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

t_entity	*new_entity(t_pars *pars, t_class class)
{
	t_entity	*entity;

	entity = ft_memalloc(sizeof(t_entity));
	entity->class = class;
	entity->row = pars->row;
	entity->col = pars->col -
				  ((class == SEPARATOR || class == NEW_LINE) ? 1 : 0);
	return (entity);
}

void		add_entity(t_entity **lst, t_entity *new)
{
	t_entity	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		if (!(new->class == NEW_LINE && tmp->class == NEW_LINE))
			tmp->next = new;
		else
			free(new);
	}
	else
	{
		if (!(new->class == NEW_LINE))
			*lst = new;
		else
			free(new);
	}
}

t_pars		*init_pars(int fd)
{
	t_pars	*pars;

	pars = ft_memalloc(sizeof(t_pars));
	pars->fd = fd;
	return (pars);
}
