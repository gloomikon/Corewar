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

t_label	*new_label(int op_pos, char *name)
{
	t_label *label;

	label = ft_memalloc(sizeof(t_label));
	label->op_pos = op_pos;
	label->name = ft_strdup(name);
	return (label);
}

void	add_label(t_label **labels, t_label *new)
{
	t_label *tmp;

	if (!(*labels))
		*labels = new;
	else
	{
		tmp = *labels;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

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

t_inst	*get_instruction(char *name)
{
	int	i;

	i = -1;
	while (++i < 16)
		if (ft_strequ(g_inst[i].name, name))
			return (&(g_inst[i]));
	return (NULL);
}

void	proc_instruction(t_pars *pars, t_entity **curr)
{
	int8_t	types_code;
	t_inst	*inst;

	if (!(inst = get_instruction((*curr)->content)))
		terminate_instruction(*curr);
	pars->code[(pars->pos)++] = inst->code;
	*curr = (*curr)->next;
	(inst->args_types_code) && ++(pars->pos);
	types_code = get_args(pars, curr, inst);
}

void	qhjvufej(t_pars *pars, t_entity **curr)
{
	while (*curr)
	{
		(pars->pos >= pars->code_size) && upd_buffer(pars);
		pars->op_pos = pars->pos;
		if ((*curr) && (*curr)->class == LABEL)
			proc_label(pars, curr);
		if ((*curr) && (*curr)->class == INSTRUCTION)
			proc_instruction(pars, curr);
		if ((*curr) && (*curr)->class == NEW_LINE)
			*curr = (*curr)->next;
		else
			terminate_entity(*curr);
	}
}

void	read_file(t_pars *pars)
{
	char	*line;
	int		res;

	while ((res = read_next_line(pars->fd, &line)) > 0
		   && !(pars->col = 0)
		   && (++pars->row))
		while (line[pars->col])
			skip_whitespaces(&(pars->col), line)
			&& skip_comment(&(pars->col), line)
			&& (line[pars->col] != '\0')
			&& get_entities(pars, &line);
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

	qhjvufej(pars, &curr);

	return (1);
}
