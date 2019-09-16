/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:40:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/15 18:35:20 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_entities(t_pars *pars, char **row)
{

	if ((*row)[pars->col] == '\n' && (++(pars->col)))
		add_entity(&(pars->entities), new_entity(pars, ENDLINE));
	else if ((*row)[pars->col] == SEPARATOR_CHAR && (++(pars->col)))
		add_entity(&(pars->entities), new_entity(pars, SEPARATOR));
	else if (is_command(pars, *row))
		parse_command(pars, *row, new_entity(pars, COMMAND));
	else if ((*row)[pars->col] == DIRECT_CHAR && (++(pars->col)))
		(*row)[pars->col] == LABEL_CHAR && (++(pars->col)) ?
		parse_chars(pars, *row, pars->col - 2, new_entity(pars, DIRECT_LABEL)) :
		parse_int(pars, *row, pars->col - 1, new_entity(pars, DIRECT));
	else if ((*row)[pars->col] == '"')
		parse_str(pars, row, pars->col, new_entity(pars, STRING));
	else if ((*row)[pars->col] == LABEL_CHAR)
		parse_chars(pars, *row, (pars->col)++,
					new_entity(pars, INDIRECT_LABEL));
	else
		parse_int(pars, *row, pars->col, new_entity(pars, INDIRECT));

	return (1);
}

void	parse_chars(t_pars *pars, char *row, int start, t_entity *entity)
{
	size_t	col;

	entity->col = start + 1;
	col = pars->col;
	while (row[pars->col] != '\0' && ft_strchr(LABEL_CHARS, row[pars->col]))
		++(pars->col);
	if ((pars->col - col) && row[pars->col] == LABEL_CHAR && (++(pars->col)))
	{
		if (!(entity->content = ft_strsub(row, start, pars->col - start)))
			terminate(MEMORY_ALLOCATION);
		(entity->class = LABEL);
		add_entity(&(pars->entities), entity);
	}
	else if ((pars->col - col) && is_delimiter(row[pars->col]))
	{
		if (!(entity->content = ft_strsub(row, start, pars->col - start)))
			terminate(MEMORY_ALLOCATION);
		if (entity->class == INDIRECT)
			entity->class = class_is_register(entity->content) ?
							REGISTER : INSTRUCTION;
		add_entity(&(pars->entities), entity);
	}
	else
		terminate_lexical(entity->row, entity->col);
}

void	parse_int(t_pars *pars, char *row, int start, t_entity *entity)
{
	size_t	col;

	entity->col = start + 1;
	row[pars->col] == '-' ? ++(pars->col) : 0;
	col = pars->col;
	while (ft_isdigit(row[pars->col]))
		++(pars->col);
	if ((pars->col - col)
		&& (entity->class == DIRECT || is_delimiter(row[pars->col])))
	{
		if (!(entity->content = ft_strsub(row, start, pars->col - start)))
			terminate(MEMORY_ALLOCATION);
		add_entity(&(pars->entities), entity);
	}
	else if (entity->class != DIRECT)
	{
		pars->col = start;
		parse_chars(pars, row, start, entity);
	}
	else
		terminate_lexical(pars->row, start);
}

void	parse_str(t_pars *pars, char **row, int start, t_entity *entity)
{
	long long	size;
	char		*str;
	char		*end;

	entity->col = start;
	size = 1;
	while (!(end = ft_strchr(*row + start + 1, '"'))
		&& (size = read_next_line(pars->fd, &str)))
		if (!(*row = join_str(row, &str)))
			terminate(MEMORY_ALLOCATION);
	upd_pars_row_and_col(pars, *row);
	if (!size)
		terminate_lexical(pars->row, pars->col);
	if (!(entity->content = ft_strsub(*row, start + 1, end - (*row) - start - 1)))
		terminate(MEMORY_ALLOCATION);
	(end - pars->col != *row) ? upd_row(row, end - pars->col) : 0;
	++(pars->col);
	add_entity(&(pars->entities), entity);
}

void	parse_command(t_pars *pars, char *row, t_entity *entity)
{

	entity->col = pars->col + 1;
	if (!ft_strncmp(row + pars->col, NAME_CMD_STRING,
			ft_strlen(NAME_CMD_STRING)))
	{
		entity->class = COMMAND_NAME;
		if (!(entity->content = ft_strsub(row, pars->col, ft_strlen(NAME_CMD_STRING))))
			terminate(MEMORY_ALLOCATION);
		pars->col += ft_strlen(NAME_CMD_STRING);
		if (ft_strlen(entity->content) > PROG_NAME_LENGTH)
			terminate_big_bio(NAME);
	}
	else
	{
		entity->class = COMMAND_COMMENT;
		if (!(entity->content = ft_strsub(row, pars->col,
				ft_strlen(COMMENT_CMD_STRING))))
			terminate(MEMORY_ALLOCATION);
		pars->col += ft_strlen(COMMENT_CMD_STRING);
		if (ft_strlen(entity->content) > COMMENT_LENGTH)
			terminate_big_bio(COMMENT);
	}

	add_entity(&(pars->entities), entity);

}
