/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:28:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/03 14:28:33 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

int		upd_buffer(t_pars *pars)
{
	pars->code_size += CHAMP_MAX_SIZE;
	pars->code = realloc(pars->code, pars->code_size + MAX_STATEMENT_SIZE);
	return (1);
}

t_label	*find_label(t_label *labels, char *name)
{
	while (labels)
	{
		if (ft_strequ(labels->name, name))
			return (labels);
		labels = labels->next;
	}
	return (NULL);
}

t_inst	*get_instruction(char *name)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (ft_strequ(g_inst[i].name, name))
			return (&(g_inst[i]));
	return (NULL);
}