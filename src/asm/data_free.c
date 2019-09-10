/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:11:49 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/10 19:12:29 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

void	free_pars(t_pars **pars)
{
	t_entity	*entity_next;
	t_label		*label_next;

	ft_strdel(&((*pars)->name));
	ft_strdel(&((*pars)->comment));
	ft_strdel(&((*pars)->code));
	while ((*pars)->entities)
	{
		entity_next = (*pars)->entities->next;
		free_entity(&((*pars)->entities));
		(*pars)->entities = entity_next;
	}
	while ((*pars)->labels)
	{
		label_next = (*pars)->labels->next;
		free_label(&((*pars)->labels));
		(*pars)->labels = label_next;
	}
	free(*pars);
}

void	free_label(t_label **label)
{
	t_mention *mention_next;

	while ((*label)->mentions)
	{
		mention_next = (*label)->mentions->next;
		free((*label)->mentions);
		(*label)->mentions = mention_next;
	}
	ft_strdel(&((*label)->name));
	free(*label);
}

void	free_entity(t_entity **entity)
{
	ft_strdel(&((*entity)->content));
	free(*entity);
}
