/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_to_bytecode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:58:09 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/03 15:26:36 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

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



int8_t	get_arg_type(t_class class)
{
	if (class == REGISTER)
		return (T_REG);
	if (class == DIRECT_LABEL || class == DIRECT)
		return (T_DIR);
	return (T_IND);
}

void	write_to_bytecode(t_pars *pars, int8_t data, size_t size)
{
	int	i;

	i = 0;
	while (size)
	{
		pars->code[pars->pos + (size - 1)] = (data >> i) & 0xFF;
		--size;
		i += 8;
	}
}

void	proc_reg(t_pars *pars, char *reg_number)
{
	write_to_bytecode(pars, ft_atoi(reg_number), 1);
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
	name = ft_strsub(curr->content, start, ft_strlen(curr->content) - size);
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
	write_to_bytecode(pars, ft_atoi(&(curr->content[start])), size);
	pars->pos += size;
}

int8_t	get_one_arg(t_pars *pars, t_entity **curr, t_inst *inst, int arg_num)
{
	int8_t	class;

	class = get_arg_type((*curr)->class);
	if ((inst->args_classes[arg_num] & class) == 0)
		terminate_invalid_argument(inst, arg_num + 1, *curr);
	if (class == T_REG)
		proc_reg(pars, (*curr)->content + 1);
	if ((*curr)->class == LABEL || (*curr)->class == INDIRECT_LABEL)
		proc_mention(pars, *curr, inst);
	if ((*curr)->class == DIRECT || (*curr)->class == INDIRECT)
		proc_int(pars, *curr, inst);
	return (class);
}

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
		||	(*curr)->class == INDIRECT)
		{
			class = get_one_arg(pars, curr, inst, arg_num);
			code |= get_code(class) << (2 * (3 - arg_num));
			*curr = (*curr)->next;
		}
		else
			terminate_entity(*curr);
		if (arg_num++ < inst->args_num - 1)
		{
			if ((*curr)->class == SEPARATOR)
				*curr = (*curr)->next;
			else
				terminate_entity(*curr);
		}
	}
	return (code);
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
	*curr = (*curr)->next;
}

void	read_and_proc_entities(t_pars *pars, t_entity **curr)
{
	while ((*curr)->class != END)
	{
		(pars->pos >= pars->code_size) && upd_buffer(pars);
		pars->op_pos = pars->pos;
		if ((*curr)->class == LABEL)
			proc_label(pars, curr);
		if ((*curr)->class == INSTRUCTION)
			proc_instruction(pars, curr);
		if ((*curr)->class == NEW_LINE)
			*curr = (*curr)->next;
		else
			terminate_syntax(pars, pars->end);	//what should be here ?
	}
}

void	read_file(t_pars *pars)
{
	char	*line;
	int		res;

	pars->end = new_entity(pars, END);
	while ((res = read_next_line(pars->fd, &line)) > 0
		   && !(pars->col = 0)
		   && (++pars->row))
		while (line[pars->col])
			skip_whitespaces(&(pars->col), line)
			&& skip_comment(&(pars->col), line)
			&& (line[pars->col] != '\0')
			&& get_entities(pars, &line);
	add_entity(&(pars->entities), pars->end);
	res == -1 ? terminate("An error occurred while opening file") : 0;
}

int		ass_to_bytecode(char *file)
{
	t_entity	*curr;
	t_pars		*pars;
	int			fd;

	(fd = open(file, O_RDONLY)) < 0 ? terminate("Invalid file") : 0;
	pars = init_pars(fd);
	read_file(pars);

	//	DEBUG
	curr = pars->entities;
	while (curr)
	{
		ft_printf("%-14s content = %s, row = %d, col = %d\n",
				g_class[curr->class],
				curr->content,
				curr->row,
				curr->col);
		curr = curr->next;
	}
	//	END
	curr = pars->entities;
	get_champ_bio(pars, &curr);
	//	DEBUG
	ft_printf("%s = %s\n%s = %s\n", NAME_CMD_STRING, pars->name,
								COMMENT_CMD_STRING, pars->comment);

	read_and_proc_entities(pars, &curr);

	return (1);
}
