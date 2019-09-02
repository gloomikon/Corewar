/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_to_bytecode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:58:09 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/29 07:23:02 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

void	get_data(t_pars *pars, t_entity **curr, int type)
{
	if (!((*curr) = (*curr)->next))
		terminate("gg");
	if ((*curr)->class != STRING)
		terminate_entity(*curr);
	if (type == NAME)
		pars->name = ft_strdup((*curr)->content);
	else
		pars->comment = ft_strdup((*curr)->content);
	if (!((*curr) = (*curr)->next))
		terminate("gg");
	if ((*curr)->class != NEW_LINE)
		terminate_entity(*curr);
}

void get_champ_bio(t_pars *pars, t_entity **curr)
{
	while (pars->name == NULL || pars->comment == NULL)
	{
		if (!(*curr))
			terminate("gg");
		else if ((*curr)->class == COMMAND
				&& ft_strequ((*curr)->content, NAME_CMD_STRING)
				&& (pars->name == NULL))
			get_data(pars, curr, NAME);
		else if ((*curr)->class == COMMAND
				 && ft_strequ((*curr)->content, COMMENT_CMD_STRING)
				 && (pars->comment == NULL))
			get_data(pars, curr, COMMENT);
		else
			terminate_entity(*curr);
		*curr = (*curr)->next;
	}
}

void	read_file(t_pars *pars)
{
	char	*line;
	int		res;

	while (!(pars->col = 0)
			&& (++pars->row)
			&& (res = read_next_line(pars->fd, &line)) > 0)
		while (line[pars->col])
			skip_whitespaces(&(pars->col), line)
			&& skip_comment(&(pars->col), line)
			&& (line[pars->col] != '\0')
			&& get_entities(pars, &line);
	res == -1 ? terminate("An error occurred while opening file") : 0;
}

int		upd_buffer(t_pars *pars)
{
	pars->code_size += CHAMP_MAX_SIZE;
	pars->code = realloc(pars->code, pars->code_size + MAX_STATEMENT_SIZE);
	return (1);
}

void	proc_label(t_pars *pars,  t_entity **curr)
{
	char	*name;
	t_label	*label;

	name = ft_strdup((*curr)->content);
	// stopped here
}

void	proc_op(t_pars *pars,  t_entity **curr)
{

}

void	qhjvufej(t_pars *pars, t_entity **curr)
{
	while (*curr)
	{
		(pars->pos >= pars->code_size) && upd_buffer(pars);
		pars->op_pos = pars->pos;
		if ((*curr) && (*curr)->class == LABEL)
			proc_label(pars, curr);
		if ((*curr) && (*curr)->class == OPERATOR)
			proc_op(pars, curr);
		if ((*curr) && (*curr)->class == NEW_LINE)
			*curr = (*curr)->next;
		else
			terminate_entity(*curr);
	}
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