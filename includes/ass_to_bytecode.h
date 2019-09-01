/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_to_bytecode.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:59:40 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/28 22:22:51 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_ASS_TO_BYTECODE_H
# define CW_ASS_TO_BYTECODE_H

# include "asm.h"
# include "op.h"

typedef enum
{
	COMMAND,
	STRING,
	LABEL,
	OPERATOR,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE,
	END
}	t_class;

static char				*g_class[] = {
	"COMMAND",
	"STRING",
	"LABEL",
	"OPERATOR",
	"REGISTER",
	"DIRECT",
	"DIRECT_LABEL",
	"INDIRECT",
	"INDIRECT_LABEL",
	"SEPARATOR",
	"NEW_LINE",
	"END"
};

typedef struct s_entity	t_entity;

struct			s_entity
{
	char		*content;
	t_class		class;
	int			col;
	int			row;
	t_entity	*next;
};

typedef struct	s_pars
{
	int			fd;
	int			row;
	int			col;
	t_entity	*entities;
}				t_pars;

/*
**	AUXILIARY
*/

bool		is_delimiter(char c);
int			divide_str(char **str, char **row);
int			read_next_line(int fd, char **row);
char		*join_str(char **s1, char **s2);
bool		class_is_register(char *str);
void		upd_row(char **row, char *ptr);
void		upd_pars_row_and_col(t_pars *pars, char const *row);
int			skip_whitespaces(int *col, char *row);
int			skip_comment(int *col, char const *row);

/*
**	PARSING
*/

void		read_file(t_pars *pars);
int			get_entities(t_pars *pars, char **row);
void		parse_chars(t_pars *pars, char *row, int start, t_entity *entity);
void		parse_int(t_pars *pars, char *row, int start, t_entity *entity);
void		parse_str(t_pars *pars, char **row, int start, t_entity *entity);

/*
**	DATA CREATION
*/

t_pars		*init_pars(int fd);
void		add_entity(t_entity **lst, t_entity *new);
t_entity	*new_entity(t_pars *pars, t_class class);

/*
**	TERMINATE
*/

void		terminate_lexical(int row, int col);

#endif
