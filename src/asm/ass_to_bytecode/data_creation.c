/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/07 17:44:53 by mzhurba          ###   ########.fr       */
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
		if (!(new->class == ENDLINE && tmp->class == ENDLINE))
			tmp->next = new;
		else
			free(new);
	}
	else
	{
		if (!(new->class == ENDLINE))
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

t_mention	*new_mention(t_pars *pars, t_entity *entity, size_t size)
{
	t_mention *mention;

	mention = malloc(sizeof(t_mention));
	mention->size = size;
	mention->pos = pars->pos;
	mention->op_pos = pars->op_pos;
	mention->row = entity->row;
	mention->col = entity->col;
	mention->next = NULL;
	return (mention);
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

t_pars		*init_pars(int fd)
{
	t_pars	*pars;

	pars = ft_memalloc(sizeof(t_pars));
	pars->fd = fd;
	return (pars);
}
