/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:28:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/16 15:28:48 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		upd_buffer(t_pars *pars)
{
	pars->code_size += CHAMP_MAX_SIZE;
	if (!(pars->code = realloc(pars->code, pars->code_size)))
		terminate(MEMORY_ALLOCATION);
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

int8_t	get_type_code(int8_t type)
{
	if (type == T_REG)
		return (REG_CODE);
	else if (type == T_DIR)
		return (DIR_CODE);
	return (IND_CODE);
}

int		get_arg_type(t_class class)
{
	if (class == REGISTER)
		return (T_REG);
	if (class == DIRECT_LABEL || class == DIRECT)
		return (T_DIR);
	return (T_IND);
}
