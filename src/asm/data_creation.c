/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/16 14:51:27 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_entity	*new_entity(t_pars *pars, t_class class)
{
	t_entity	*entity;

	if (!(entity = ft_memalloc(sizeof(t_entity))))
		terminate(MEMORY_ALLOCATION);
	entity->class = class;
	entity->row = pars->row;
	entity->col = pars->col;
	if (entity->class == SEPARATOR)
		if (!(entity->content = ft_strdup(",")))
			terminate(MEMORY_ALLOCATION);
	entity->next = NULL;
	return (entity);
}

t_label		*new_label(int op_pos, char *name)
{
	t_label *label;

	if (!(label = ft_memalloc(sizeof(t_label))))
		terminate(MEMORY_ALLOCATION);
	label->op_pos = op_pos;
	if (!(label->name = ft_strdup(name)))
		terminate(MEMORY_ALLOCATION);
	return (label);
}

t_mention	*new_mention(t_pars *pars, t_entity *entity, size_t size)
{
	t_mention *mention;

	if (!(mention = malloc(sizeof(t_mention))))
		terminate(MEMORY_ALLOCATION);
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

	if (!(pars = ft_memalloc(sizeof(t_pars))))
		terminate(MEMORY_ALLOCATION);
	pars->fd = fd;
	return (pars);
}
