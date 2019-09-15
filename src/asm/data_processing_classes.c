/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing_classes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:47:05 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/07 20:28:36 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	proc_label(t_pars *pars, t_entity **curr)
{
	char	*name;
	t_label	*label;

	name = ft_strsub((*curr)->content, 0, ft_strlen((*curr)->content) - 1);
	!(label = find_label(pars->labels, name)) ?
	add_label(&(pars->labels), new_label(pars->op_pos, name)) : 0;
	(label && label->op_pos == -1) && (label->op_pos = pars->pos);
	ft_strdel(&name);
	*curr = (*curr)->next;
}

void	proc_instruction(t_pars *pars, t_entity **curr)
{
	int8_t	code;
	t_inst	*inst;

	if (!(inst = get_instruction((*curr)->content)))
		terminate_instruction(*curr);
	pars->code[(pars->pos)++] = inst->code;
	*curr = (*curr)->next;
	(inst->args_need_code) && ++(pars->pos);
	code = read_and_code_args(pars, curr, inst);
	if (inst->args_need_code)
		pars->code[pars->op_pos + 1] = code;
}
