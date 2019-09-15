/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/10 16:40:02 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

t_label		*new_label(int op_pos, char *name)
{
	t_label *label;

	label = ft_memalloc(sizeof(t_label));
	label->op_pos = op_pos;
	label->name = ft_strdup(name);
	return (label);
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

t_pars		*new_pars(int fd)
{
	t_pars	*pars;

	pars = ft_memalloc(sizeof(t_pars));
	pars->fd = fd;
	return (pars);
}
