/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:46:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/19 20:36:51 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "header.h"
# include "op.h"
# include "common.h"

typedef struct s_corewar	t_corewar;
typedef struct s_champ		t_champ;
typedef struct s_carriage	t_carriage;

/*
**	COMMON
*/

bool	check_file_extension(char *file, char *ext);
void	terminate(char *message);

const uint8_t			g_arg_code[3] = {
		T_REG,
		T_DIR,
		T_IND
};

/*
**	STRUCTS
*/

struct s_carriage
{
	uint32_t	id;
	t_champ		*champ;
	bool		carry;
	int			pc;
	int			*reg;
	int			cycles_to_ex;
	uint8_t		instruction;
	uint8_t		args_types[3];
	int			step;
	t_carriage	*next;
};

struct s_champ
{
	int		id;
	char	*name;
	char	*comment;
	int		size;
	uint8_t	*code;
	t_champ	*next;
};

struct s_corewar
{
	uint8_t		*map;
	int			dump_mode;
	int			dump_cycles;
	int			cycles;
	int			cycles_after_check;
	int			cycles_to_die;
	int			checks;
	int			lives;
	t_champ		**champs;
	int			champs_num;
	t_carriage	*carriages;
	int			carriages_num;
	t_champ		*last_alive;
};

/*
**	PARSE FLAGS
*/

void	parse_args(int argc, char **argv, t_corewar *cw);
void	init_dump_flag(int *argc, char ***argv, t_corewar *cw);
void	proc_champ(int *argc, char ***argv, t_champ **lst, t_corewar *cw);

/*
**	READING FROM .COR
*/

int		convert_to_int(uint8_t *bytes, size_t size);
int		read_from_bytecode(int fd);
char	*read_str_from_bytecode(int fd, int length);
uint8_t	*read_code(int fd, int code_size);

/*
**	DATA CREATION
*/

t_corewar	*new_corewar(void);
t_champ		*new_champ(char *file, int id);
t_carriage	*new_carriage(t_champ *champ, int pc);


/*
**	DATA ADD TO LIST
*/

void	add_champ(t_champ **lst, t_champ *new);
void	add_carriage(t_carriage **lst, t_carriage *new);


/*
** AUXILIARY
*/

void	print_usage(void);
t_champ	*find_champ(t_champ *lst, int id);
void	list_to_array(t_champ *lst, t_corewar *cw);

/*
**	DISPLAY FUNCTIONS
*/

int		display_start_message(t_champ **champ);
void	display_map(int mode, uint8_t *map);



#endif