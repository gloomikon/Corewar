/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:46:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/23 15:02:21 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "header.h"
# include "op.h"
# include "common.h"
# include <ncurses.h>
# include <time.h>

/*
**	==================================COREWAR===================================
*/

# define LIVES	(1 << 0)
# define CYCLES	(1 << 1)
# define OPS	(1 << 2)
# define DEATHS	(1 << 3)
# define PC		(1 << 4)

typedef struct s_corewar	t_corewar;
typedef struct s_champ		t_champ;
typedef struct s_carriage	t_carriage;
typedef struct s_inst		t_inst;
typedef struct s_visual		t_visual;
typedef struct s_attr		t_attr;

static uint8_t	g_arg_code[3] = {
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
	int			id;
	char		*name;
	char		*comment;
	uint8_t		*code;
	int			size;
	t_champ		*next;
};

struct s_corewar
{
	uint8_t		*map;
	t_champ		**champs;
	int			champs_num;
	t_champ		*last;
	bool		aff;
	int			verbose;
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
	t_visual	*visual;
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
void			init_verbose_flag(int *argc, char ***argv, t_corewar *cw);
void			init_visual_flag(int *argc, char ***argv, t_corewar *cw);

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
t_visual		*new_visual(void);

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

void			update_cycles_to_die(t_corewar *cw);
void			kill_carriages(t_corewar *cw);
bool			dead(t_carriage *carriage, t_corewar *cw);


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

/*
**	VERBOSE FUNCTIONS
*/

void			verbose_death(t_carriage *del, t_corewar *cw);
void			verbose_cycles(int cycles);
void			verbose_pc(t_carriage *carriage, uint8_t *map);


/*
**	================================VISUALIZATION===============================
*/

# define WIDTH	(64 * 3 + 5)
# define HEIGHT	(MEM_SIZE / 64 + 4)

# define GREY_COLOR		254
# define PINK_COLOR		219
# define PEACH_COLOR	215
# define GRASS_COLOR	193
# define SKY_COLOR		147

# define DEFAULT	1
# define PINK		2
# define PEACH		3
# define GRASS		5
# define SKY		8
# define C_DEFAULT	13
# define C_PINK		21
# define C_PEACH	34
# define C_GRASS	55
# define C_SKY		89
# define L_PINK		144
# define L_PEACH	233
# define L_GRASS	377
# define L_SKY		610

# define SPEED	50

struct s_visual
{
	bool	pause;
	t_attr	*map;
	WINDOW	*menu;
	WINDOW	*win;
	WINDOW	*info;
	int		speed;
	int		btn;
	clock_t	time;
};

struct s_attr
{
	int	ind;
};

void	visualize(t_corewar *cw);



#endif
