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
	entity->col = pars->col;
	if (entity->class == SEPARATOR)
		entity->content = ft_strdup(",");
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

t_label		*new_label(int op_pos, char *name)
{
	t_label *label;

	label = ft_memalloc(sizeof(t_label));
	label->op_pos = op_pos;
	label->name = ft_strdup(name);
	return (label);
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

t_pars		*init_pars(int fd)
{
	t_pars	*pars;

	pars = ft_memalloc(sizeof(t_pars));
	pars->fd = fd;
	return (pars);
}
