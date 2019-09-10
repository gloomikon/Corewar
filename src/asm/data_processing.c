/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:26:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/10 15:59:15 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

void	get_data(t_pars *pars, t_entity **curr, int type)
{
	if ((type == NAME && pars->name != NULL)
		|| (type == COMMENT && pars->comment != NULL))
		terminate_syntax(pars, *curr, false);
	*curr = (*curr)->next;
	if ((*curr)->class != STRING)
		terminate_syntax(pars, *curr, false);
	if (type == NAME)
		pars->name = ft_strdup((*curr)->content);
	else if (type == COMMENT)
		pars->comment = ft_strdup((*curr)->content);
	*curr = (*curr)->next;
	if ((*curr)->class != ENDLINE)
		terminate_syntax(pars, *curr, false);
}

void	get_champ_bio(t_pars *pars, t_entity **curr)
{
	while (pars->name == NULL || pars->comment == NULL)
	{
		if ((*curr)->class == COMMAND_NAME)
			get_data(pars, curr, NAME);
		else if ((*curr)->class == COMMAND_COMMENT)
			get_data(pars, curr, COMMENT);
		else
			terminate_syntax(pars, *curr, false);
		*curr = (*curr)->next;
	}
}

void	read_and_proc_entities(t_pars *pars, t_entity **curr)
{
	bool	was_label;

	was_label = false;
	while ((*curr)->class != END)
	{
		(pars->pos >= pars->code_size) && upd_buffer(pars);
		pars->op_pos = pars->pos;
		if ((*curr)->class == LABEL && (was_label = true))
			proc_label(pars, curr);
		if (was_label && (*curr)->class != INSTRUCTION
		&& (*curr)->class != ENDLINE)
			break ;
		if ((*curr)->class == INSTRUCTION)
			proc_instruction(pars, curr);
		if ((*curr)->class == ENDLINE)
			*curr = (*curr)->next;
		else
			(*curr)->class == END ? terminate_syntax(pars, pars->end, true) :
			terminate_entity(*curr);
	}
	insert_ints_instead_mentions(pars);
}
