/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_to_bytecode.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:59:40 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/07 20:09:28 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_ASS_TO_BYTECODE_H
# define CW_ASS_TO_BYTECODE_H

# include "asm.h"
# include "op.h"
# include "asm_instructions.h"

# define NAME		1
# define COMMENT	2
# define MAX_STATEMENT_SIZE 14 // ???

typedef enum
{
	COMMAND,
	COMMAND_NAME,
	COMMAND_COMMENT,
	STRING,
	LABEL,
	INSTRUCTION,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	ENDLINE,
	END
}	t_class;

static char				*g_class[] = {
	"COMMAND",
	"COMMAND_NAME",
	"COMMAND_COMMENT",
	"STRING",
	"LABEL",
	"INSTRUCTION",
	"REGISTER",
	"DIRECT",
	"DIRECT_LABEL",
	"INDIRECT",
	"INDIRECT_LABEL",
	"SEPARATOR",
	"ENDLINE",
	"END"
};

typedef struct s_entity	t_entity;
typedef struct s_pars	t_pars;
typedef struct s_label	t_label;
typedef struct s_mention	t_mention;

struct			s_label
{
	char		*name;
	int			op_pos;
	t_mention	*mentions;
	t_label		*next;
};

struct			s_mention
{
	int			row;
	int			col;
	int			pos;
	int			op_pos;
	int			size;
	t_mention	*next;
};

struct			s_entity
{
	char		*content;
	t_class		class;
	int			col;
	int			row;
	t_entity	*next;
};

struct			s_pars
{
	int			fd;
	int			row;
	int			col;
	t_entity	*entities;
	t_entity	*end;
	t_label		*labels;
	char		*name;
	char		*comment;
	int			pos;
	int			op_pos;
	int			code_size;
	char		*code;
};

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
bool		is_command(t_pars *pars, char *row);
int			upd_buffer(t_pars *pars);
t_label		*find_label(t_label *labels, char *name);
t_inst		*get_instruction(char *name);
int8_t		get_type_code(int8_t type);
int			get_arg_type(t_class class);
void		insert_ints_instead_mentions(t_pars *pars);


/*
**	PARSING
*/

void		read_file(t_pars *pars);
int			get_entities(t_pars *pars, char **row);
void		parse_chars(t_pars *pars, char *row, int start, t_entity *entity);
void		parse_int(t_pars *pars, char *row, int start, t_entity *entity);
void		parse_str(t_pars *pars, char **row, int start, t_entity *entity);
void		parse_command(t_pars *pars, char *row, t_entity *entity);

/*
**	DATA CREATION
*/

t_pars		*init_pars(int fd);
void		add_entity(t_entity **lst, t_entity *new);
t_entity	*new_entity(t_pars *pars, t_class class);
t_label		*new_label(int op_pos, char *name);
void		add_label(t_label **labels, t_label *new);
t_mention	*new_mention(t_pars *pars, t_entity *entity, size_t size);
void		add_mention(t_mention **mentions, t_mention *new);

/*
**	DATA PROCESSING
*/

void		get_data(t_pars *pars, t_entity **curr, int type);
void		get_champ_bio(t_pars *pars, t_entity **curr);
void		read_and_proc_entities(t_pars *pars, t_entity **curr);
void		proc_label(t_pars *pars, t_entity **curr);
void		proc_instruction(t_pars *pars, t_entity **curr);
int8_t		read_and_code_args(t_pars *pars, t_entity **curr, t_inst *inst);
int8_t		get_one_arg(t_pars *pars, t_entity **curr,
								t_inst *inst, int arg_num);
void		proc_reg(t_pars *pars, char *reg_number);
void		proc_mention(t_pars *pars, t_entity *curr, t_inst *inst);
void		proc_int(t_pars *pars, t_entity *curr, t_inst *inst);

/*
**	WRITING
*/

void		write_to_bytecode(char *code, int pos, int8_t data, size_t size);

/*
**	TERMINATE
*/

void		terminate_lexical(int row, int col);
void		terminate_entity(t_entity *entity);
void		terminate_syntax(t_pars *pars, t_entity *entity, bool suggestion);
void		terminate_big_bio(int type);
void 		terminate_instruction(t_entity *entity);
void		terminate_invalid_argument(t_inst *inst, int arg_num,
												t_entity *entity);
void		terminate_label(t_label *label);
void		terminate_invalid_parameter_count(t_inst *inst);

#endif
