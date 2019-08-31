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

//#include "ass_to_bytecode.h"
#include "../includes/ass_to_bytecode.h"

bool	is_delimiter(char c)
{
	return (ft_isspace(c) || c == '"' || c == '\0'
		|| c == COMMAND_CHAR
		|| c == DIRECT_CHAR
		|| c == SEPARATOR_CHAR
		|| c == COMMENT_CHAR || c == ANOTHER_COMMENT_CHAR);
}

void	terminate_lexical(size_t row, size_t col)
{
	ft_printf("Lexical error at [%u:%u]\n", row, col);
	exit(1);
}

t_pars	*init_pars(int fd)
{
	t_pars	*pars;

	pars = ft_memalloc(sizeof(t_pars));
	pars->fd = fd;
	return (pars);
}

int	divide_str(char **str, char **row)
{
	char *div;
	char *new;

	div = ft_strchr(*str, '\n') + 1;
	*row = ft_strsub(*str, 0, div - *str);
	if (!ft_strlen(div))
		ft_strdel(str);
	else
	{
		new = ft_strdup(div);
		ft_strdel(str);
		*str = new;
	}
	return (1);
}

long long	get_row(int fd, char **row)
{
	char	*tmp;
	char	buff[BUFF_SIZE + 1];
	static char *str = NULL;
	size_t	size;

	if (read(fd, buff, 0) < 0)
		return (-1);
	while (!ft_strchr(str, '\n'))
	{
		if ((size = read(fd, buff, BUFF_SIZE)) == 0)
		{
			if ((*row = str) == NULL)
				return (0);
			str = NULL;
			return (1);
		}
		buff[size] = '\0';
		tmp = str;
		str = ft_strjoin(str, buff);
        ft_strdel(&tmp);
//		if (str == NULL)
//			return (-1);
	};
	return (divide_str(&str, row));
}

int		skip_whitespaces(size_t *col, char *row)
{
	while (ft_isspace(row[*col]) && (row[*col] != '\n'))
		++(*col);
	return (1);
}

int		skip_comment(size_t *col, char *row)
{
	if (row[*col] == COMMENT_CHAR
	|| row[*col] == ANOTHER_COMMENT_CHAR)
		while (row[*col] != '\0' && row[*col] != '\n')
			++(*col);
	return (1);
}

t_entity	*new_entity(t_pars *pars, t_class class)
{
	t_entity	*entity;

	entity = ft_memalloc(sizeof(t_entity));
	entity->class = class;
	entity->row = pars->row;
	entity->col = pars->col -
			((class == SEPARATOR || class == NEW_LINE) ? 1 : 0);
	return (entity);
}

void	add_entity(t_entity **lst, t_entity *new)
{
	t_entity	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		if (!(new->class == NEW_LINE && tmp->class == NEW_LINE))
			tmp->next = new;
		else
			free(new);
	}
	else
	{
		if (!(new->class == NEW_LINE))
			*lst = new;
		else
			free(new);
	}
}

bool	class_is_register(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	if ((len == 2 || len == 3) && str[0] == 'r') // is there a define for r ?
	{
		i = 1;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == '\0' && ft_atoi(&str[1]) > 0)
			return(true);
	}
	return (false);
}

void	parse_chars(t_pars *pars, char *row, size_t start, t_entity *entity)
{
	size_t	col;

	entity->col = start;
	col = pars->col;
	while (row[pars->col] != '\0' && ft_strchr(LABEL_CHARS, row[pars->col]))
		++(pars->col);
	if ((pars->col - col) && row[pars->col] == LABEL_CHAR && (++(pars->col)))
	{
		entity->content =  ft_strsub(row, start, pars->col - start);
		entity->class = LABEL;
		add_entity(&(pars->entities), entity);
	}
	else if ((pars->col - col) && is_delimiter(row[pars->col]))
	{
		entity->content = ft_strsub(row, start, pars->col - start);
		if (entity->class == INDIRECT)
			entity->class = class_is_register(entity->content) ?
					REGISTER : OPERATOR;
		add_entity(&(pars->entities), entity);
	}
	else
		terminate_lexical(pars->row, pars->col);
}

void	parse_int(t_pars *pars, char *row, size_t start, t_entity *entity)
{
	size_t	col;

	entity->col = start;
	row[pars->col] == '-' ? ++(pars->col) : 0;
	col = pars->col;
	while (ft_isdigit(row[pars->col]))
		++(pars->col);
	if ((pars->col - col)
	&& (entity->class == DIRECT || is_delimiter(row[pars->col])))
	{
		entity->content = ft_strsub(row, start, pars->col - start);
		add_entity(&(pars->entities), entity);
	}
	else if (entity->class != DIRECT)
	{
		pars->col = start;
		parse_chars(pars, row, start, entity);
	}
	else
		terminate_lexical(pars->row, pars->col);
}

char	*join_str(char **s1, char **s2)
{
	char	*res;

	res = ft_strjoin(*s1, *s2);
	ft_strdel(s1);
	ft_strdel(s2);
	return (res);
}

void	upd_pars_row_and_col(t_pars *pars, char *row)
{
	size_t	i;

	i = (pars->col)++;
	while (row[++i]!= '\0' && row[i] != '"')
		row[i] == '\n' ? (++(pars->row)) && (pars->col = 0) : (++(pars->col));
}

void	upd_row(char **row, char *ptr)
{
	char	*new;

	new = ft_strdup(ptr);
	ft_strdel(row);
	*row = new;
}

void	parse_str(t_pars *pars, char **row, size_t start, t_entity *entity)
{
	long long	size;
	char		*str;
	char		*end;

	entity->col = start;
	size = 1;
	while (!(end = ft_strchr(*row + start + 1, '"'))
		&& (size = get_row(pars->fd, &str)))
		*row = join_str(row, &str);
	upd_pars_row_and_col(pars, *row);
	if (!size)
		terminate_lexical(pars->row, pars->col);
	entity->content = ft_strsub(*row, start, end + 1 - (*row) - start);
	(end - pars->col != *row) ? upd_row(row, end - pars->col) : 0;
	++(pars->col);
	add_entity(&(pars->entities), entity);
}

int		get_entities(t_pars *pars, char **row)
{
	if ((*row)[pars->col] == '\n' && (++(pars->col)))
		add_entity(&(pars->entities), new_entity(pars, NEW_LINE));
	else if ((*row)[pars->col] == SEPARATOR_CHAR && (++(pars->col)))
		add_entity(&(pars->entities), new_entity(pars, SEPARATOR));
	else if ((*row)[pars->col] == '.')
		parse_chars(pars, *row, ++(pars->col), new_entity(pars, COMMAND));
	else if ((*row)[pars->col] == DIRECT_CHAR && (++(pars->col)))
		(*row)[pars->col] == LABEL_CHAR && (++(pars->col)) ?
		parse_chars(pars, *row, pars->col - 2, new_entity(pars, DIRECT_LABEL)) :
		parse_int(pars, *row, pars->col - 1, new_entity(pars, DIRECT));
	else if ((*row)[pars->col] == '"')
		parse_str(pars, row, pars->col, new_entity(pars, STRING));
	else if ((*row)[pars->col] == LABEL_CHAR)
		parse_chars(pars, *row, ++(pars->col),
				new_entity(pars, INDIRECT_LABEL));
	else
		parse_int(pars, *row, pars->col, new_entity(pars, INDIRECT));
//		(++(pars->col));
	return (1);
}

void	parse_ass(t_pars *pars)
{
	char		*row;
	long long	size;

	while (!(pars->col = 0)
		&& (++pars->row)
		&& (size = get_row(pars->fd, &row)) > 0)
	{
		ft_printf("%s\n", row);
		while (row[pars->col])
		{
			skip_whitespaces(&(pars->col), row)
			&& skip_comment(&(pars->col), row)
			&& (row[pars->col] != '\0')
			&& get_entities(pars, &row);
		}
	}
}

int		ass_to_bytecode(char *file)
{
	t_entity	*curr;
	t_pars		*pars;
	int			fd;

	(fd = open(file, O_RDONLY)) < 0 ? terminate("Invalid file") : 0;
	pars = init_pars(fd);
	parse_ass(pars);
	while (pars->entities)
	{
		ft_printf("%-14s content = %s, row = %d, col = %d\n",
				g_class[pars->entities->class],
				pars->entities->content,
				pars->entities->row,
				pars->entities->col);
		pars->entities = pars->entities->next;
	}
	return (1);
}