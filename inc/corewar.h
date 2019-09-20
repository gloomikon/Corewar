/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:46:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/20 17:30:59 by mzhurba          ###   ########.fr       */
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
typedef struct s_inst		t_inst;

static uint8_t			g_arg_code[3] = {
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
	int			live_cycle;
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
	uint8_t	*code;
	int		size;
	int		live_cycle;
	t_champ	*next;
};

struct s_corewar
{
	uint8_t		*map;
	t_champ		**champs;
	int			champs_num;
	t_champ		*last;
	bool		aff;
	int			dump_mode;
	int			dump_cycles;
	int			debug_mode;
	int			debug_cycles;
	int			cycles;
	t_carriage	*carriages;
	int			carriages_num;
	int			cycles_to_die;
	int			cycles_after_check;
	int			checks;
	int			lives;
};

/*
**	PARSE FLAGS
*/

void			parse_args(int argc, char **argv, t_corewar *cw);
void			init_dump_flag(int *argc, char ***argv, t_corewar *cw);
void			init_debug_flag(int *argc, char ***argv, t_corewar *cw);
void			proc_champ(int *argc, char ***argv, t_champ **lst,
												t_corewar *cw);
void			init_aff_flag(int *argc, char ***argv, t_corewar *cw);

/*
**	READING FROM .COR
*/

int				convert_to_int(uint8_t *bytes, size_t size);
int				read_from_bytecode(int fd);
char			*read_str_from_bytecode(int fd, int length);
uint8_t			*read_code(int fd, int code_size);
int				get_int(uint8_t *map, int address, int size);

/*
**	DATA CREATION
*/

t_corewar		*new_corewar(void);
t_champ			*new_champ(char *file, int id);
t_carriage		*new_carriage(t_champ *champ, int pc);
void			create_start_data(t_corewar *cw);
t_carriage		*dup_carriage(t_carriage *carriage, int address);

/*
**	BATTLE
*/

int				run_battle(t_corewar *cw);
void			execute_one_cycle(t_corewar *cw);
int				execute_instruction(t_carriage *carriage, t_corewar *cw);
void			move_carriage(t_carriage *carriage, t_corewar *cw);

/*
**	CARRIAGE KILL
*/

void	update_cycles_to_die(t_corewar *cw);
void	kill_carriages(t_corewar *cw);
bool	dead(t_carriage *carriage, t_corewar *cw);


/*
*	VALIDATION
*/

bool			args_valid(t_carriage *carriage, t_inst *inst, t_corewar *cw);
bool			args_types_valid(t_carriage *carriage, t_inst *inst);
bool			t_reg(int pc, int step, t_corewar *cw);


/*
**	DATA ADD TO LIST
*/

void			add_champ(t_champ **lst, t_champ *new);
void			add_carriage(t_carriage **lst, t_carriage *new);


/*
** AUXILIARY
*/

t_champ			*find_champ(t_champ *lst, int id);
void			list_to_array(t_champ *lst, t_corewar *cw);
void			get_inst_args(t_inst *inst, t_carriage *carriage,
													t_corewar *cw);
int				get_inst_argument(t_carriage *carriage, uint8_t pos, bool mod,
							 						t_corewar *cw);
void			write_to_bytecode(uint8_t *map, int address,
									int value, int size);

/*
**	COUNTING
*/

int				calculate_address(int address);
uint32_t		arg_size(uint8_t arg, t_inst *inst);
uint32_t		step(t_carriage *carriage, t_inst *inst);

/*
**	DISPLAY FUNCTIONS
*/

void			display_usage(void);
int				display_start_message(t_champ **champ);
void			display_map(int mode, uint8_t *map);
void			display_result(t_corewar *cw);


#endif
