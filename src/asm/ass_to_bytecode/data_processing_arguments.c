/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_processing_arguments.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:48:57 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/06 19:42:34 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

int8_t	read_and_code_args(t_pars *pars, t_entity **curr, t_inst *inst)
{
	int8_t	code;
	int8_t	class;
	int		arg_num;

	arg_num = 0;
	code = 0;
	while (arg_num < inst->args_num)
	{
		if ((*curr)->class == REGISTER || (*curr)->class == DIRECT
			|| (*curr)->class == DIRECT_LABEL || (*curr)->class == INDIRECT
			|| (*curr)->class == INDIRECT_LABEL)
		{
			class = get_one_arg(pars, curr, inst, arg_num);
			code |= get_type_code(class) << (2 * (3 - arg_num));
			*curr = (*curr)->next;
		}
		else
			terminate_syntax(pars, (*curr), false);
		if (arg_num++ < inst->args_num - 1)
			(*curr)->class == SEPARATOR ?
			*curr = (*curr)->next : terminate_entity(*curr);
	}
	return (code);
}

int8_t	get_one_arg(t_pars *pars, t_entity **curr, t_inst *inst, int arg_num)
{
	int8_t	class;

	class = get_arg_type((*curr)->class);
	if ((inst->args_classes[arg_num] & class) == 0)
		terminate_invalid_argument(inst, arg_num, *curr);
	if (class == T_REG)
		proc_reg(pars, (*curr)->content + 1);
	if ((*curr)->class == DIRECT_LABEL || (*curr)->class == INDIRECT_LABEL)
		proc_mention(pars, *curr, inst);
	if ((*curr)->class == DIRECT || (*curr)->class == INDIRECT)
		proc_int(pars, *curr, inst);
	return (class);
}

void	proc_reg(t_pars *pars, char *reg_number)
{
	write_to_bytecode(pars->code, pars->pos, ft_atoi(reg_number), 1);
	++(pars->pos);
}

void	proc_mention(t_pars *pars, t_entity *curr, t_inst *inst)
{
	t_label *label;
	char	*name;
	int		start;
	size_t	size;

	start = (curr->class == INDIRECT_LABEL) ? 1 : 2;
	size = (curr->class == INDIRECT_LABEL) ? IND_SIZE : inst->t_dir_size;
	name = ft_strsub(curr->content, start, ft_strlen(curr->content) - start);
	ft_printf("%s  %s\n", curr->content, name);
	if (!(label = find_label(pars->labels, name)))
	{
		label = new_label(-1, name);
		add_label(&(pars->labels), label);
	}
	add_mention(&(label->mentions), new_mention(pars, curr, size));
	pars->pos += size;
	ft_strdel(&name);
}

void	proc_int(t_pars *pars, t_entity *curr, t_inst *inst)
{
	int		start;
	size_t	size;

	start = (curr->class == INDIRECT) ? 0 : 1;
	size = (curr->class == INDIRECT) ? IND_SIZE : inst->t_dir_size;
	write_to_bytecode(pars->code, pars->pos, ft_atoi(&(curr->content[start])), size);
	pars->pos += size;
}
