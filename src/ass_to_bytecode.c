/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_to_bytecode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:58:09 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/28 23:25:40 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ass_to_bytecode.h"
#include "../includes/ass_to_bytecode.h"

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

//void	parse_characters(t_pars *pars, char *row, size_t start, t_entity *ent)
//{
//
//}

int		get_entities(t_pars *pars, char **row)
{
	if ((*row)[pars->col] == '\n' && (++(pars->col)))
		add_entity(&(pars->entities), new_entity(pars, NEW_LINE));
	else if ((*row)[pars->col] == SEPARATOR_CHAR && (++(pars->col)))
		add_entity(&(pars->entities), new_entity(pars, SEPARATOR));
	else (++(pars->col));
//	else if ((*row)[pars->col] == '.')
//		parse_characters(pars, *row, (pars->col)++, new_entity(pars, COMMAND));

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
		ft_printf("%s: row = %d, col = %d\n",
				g_class[pars->entities->class],
				pars->entities->row,
				pars->entities->col);
		pars->entities = pars->entities->next;
	}
	return (1);
}