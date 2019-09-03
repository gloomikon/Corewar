/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:26:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/03 14:26:45 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

void	get_data(t_pars *pars, t_entity **curr, int type)
{
	if ((type == NAME && pars->name != NULL)
		|| (type == COMMENT && pars->comment != NULL))
		terminate_syntax(0, 0, (*curr));
	if (!((*curr) = (*curr)->next))
		terminate_syntax(pars->row, pars->col + 1, NULL);
	if ((*curr)->class != STRING)
		terminate_syntax(0, 0, *curr);
	if (type == NAME)
		pars->name = ft_strdup((*curr)->content);
	else if (type == COMMENT)
		pars->comment = ft_strdup((*curr)->content);
	if (!((*curr) = (*curr)->next))
		terminate_syntax(pars->row, pars->col + 1, NULL);
	if ((*curr)->class != NEW_LINE)
		terminate_syntax(0, 0, *curr);
}

void	get_champ_bio(t_pars *pars, t_entity **curr)
{
	while (pars->name == NULL || pars->comment == NULL)
	{
		if (!(*curr))
			terminate_syntax(pars->row, pars->col + 1, NULL);
		else if ((*curr)->class == COMMAND_NAME)
			get_data(pars, curr, NAME);
		else if ((*curr)->class == COMMAND_COMMENT)
			get_data(pars, curr, COMMENT);
		else
			terminate_entity(*curr);
		*curr = (*curr)->next;
	}
}
