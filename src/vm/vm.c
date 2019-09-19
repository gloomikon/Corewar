/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/19 20:42:09 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_instructions.h"

void	create_start_data(t_corewar *cw)
{
	uint32_t	pc;
	int			id;

	pc = 0;
	id = -1;
	while (++id < cw->champs_num)
	{
		ft_memcpy(&(cw->map[pc]), cw->champs[id]->code,
				cw->champs[id]->size);
		add_carriage(&(cw->carriages), new_carriage(cw->champs[id], pc));
		pc += MEM_SIZE / cw->champs_num;
	}
}

int		calculate_address(int address)
{
	address %= MEM_SIZE;
	address += address < 0 ? MEM_SIZE : 0;
	return (address);
}


void	get_inst_args(t_inst *inst,
					t_carriage *carriage,
					t_corewar *cw)
{
	int8_t	code;

	if (inst->args_types_code == false)
		carriage->args_types[0] = T_REG;
	else
	{
		code = cw->map[calculate_address(carriage->pc + 1)];
		carriage->args_types[0] = g_arg_code[((code & 0xC0) >> 6) - 1];
		(inst->args_num > 1) &&
		(carriage->args_types[1] = g_arg_code[((code & 0x30) >> 4) - 1]);
		(inst->args_num > 2) &&
		(carriage->args_types[2] = g_arg_code[((code & 0xC) >> 2) - 1]);
	}
}

bool	args_types_valid(t_carriage *carriage, t_inst *inst)
{
	int	i;

	i = -1;
	while (++i < inst->args_num)
		if (!(carriage->args_types[i] & inst->args_types[i]))
			return (false);
	return (true);
}

uint32_t	arg_size(uint8_t arg, t_inst *inst)
{
	if (arg & T_REG)
		return (1);
	else if(arg & T_DIR)
		return (inst->t_dir_size);
	else
		return (2);
}

bool	t_reg(int pc, int step, t_corewar *cw)
{
	int8_t	byte;

	byte = cw->map[calculate_address(pc + step)];
	return (byte > 0 && byte <= REG_NUMBER);
}

bool	args_valid(t_carriage *carriage, t_inst *inst, t_corewar *cw)
{
	uint32_t	step;
	int			i;

	step = (1 + inst->args_types_code);
	i = -1;
	while (++i < inst->args_num)
	{
		if ((inst->args_types[i] == T_REG) && !t_reg(carriage->pc, step, cw))
			return (false);
		step += arg_size(carriage->args_types[i], inst);
	}
	return (true);
}

uint32_t	step(t_carriage *carriage, t_inst *inst)
{
	uint32_t	step;
	int			i;

	step = 1 + (inst->args_types_code);
	i = -1;
	while (++i < g_inst[carriage->instruction - 1].args_num)
		step += arg_size(carriage->args_types[i], inst);
}

void	move_carriage(t_carriage *carriage, t_corewar *cw)
{
	carriage->pc += carriage->step;
	carriage->pc = calculate_address(carriage->pc);
	carriage->step = 0;
	carriage->args_types[0] = 0;
	carriage->args_types[1] = 0;
	carriage->args_types[2] = 0;
}

int		execute_instruction(t_carriage *carriage, t_corewar *cw)
{
	t_inst	*inst;

	if (!carriage->cycles_to_ex)
	{
		carriage->instruction = cw->map[carriage->pc];
		(carriage->instruction >= 1 && carriage->instruction <= 16) &&
		(carriage->cycles_to_ex = g_inst[carriage->instruction - 1].cycles);
	}
	(carriage->cycles_to_ex > 0) && --(carriage->cycles_to_ex);
	if (!carriage->cycles_to_ex)
	{
		if (carriage->instruction >= 1 && carriage->instruction <= 16)
		{
			inst = &(g_inst[carriage->instruction - 1]);
			get_inst_args(inst, carriage, cw);
			if (args_types_valid(carriage, inst)
			&& args_valid(carriage, inst, cw))
				inst->func(cw, carriage);
			else
				carriage->step += step(carriage, inst);
		}
		else
			carriage->step = 1;
		move_carriage(carriage, cw);
	}
}

void	execute_one_cycle(t_corewar *cw)
{
	t_carriage	*carriage;

	++(cw->cycles_after_check) && ++(cw->cycles);
	carriage = cw->carriages;
	while (carriage)
		execute_instruction(carriage, cw) && (carriage = carriage->next);
}

void	update_cycles_to_die(t_corewar *cw)
{
	++(cw->checks);
	remove_died_carriges(cw);
	if (cw->lives >= NBR_LIVE
	|| cw->checks == MAX_CHECKS)
	{
		cw->cycles_to_die -= CYCLE_DELTA;
		cw->checks = 0;
	}
	reset_lives(cw);
	cw->cycles_after_check = 0;
}

int		run_battle(t_corewar *cw)
{
	while (cw->carriages_num)
	{
		if (cw->cycles == cw->dump_cycles)
		{
			display_map(cw->dump_mode, cw->map);
			system("leaks -q corewar");
			exit(0);
		}
		execute_one_cycle(cw);
		if (cw->cycles_to_die <= 0
		|| cw->cycles_to_die == cw->cycles_after_check)
			update_cycles_to_die(cw);
	}
}

int		main(int argc, char **argv)
{
	t_corewar	*cw;

	if (argc < 2)
		print_usage();
	parse_args(argc, argv, (cw = new_corewar()));

//	for (int i = 0; i < cw->champs_num; i++)
//		printf("%d: %s\n", cw->champs[i]->id, cw->champs[i]->name);

	create_start_data(cw);
//	while (cw->carriages)
//	{
//		printf("%d: %d %s\n",
//				cw->carriages->id,
//				cw->carriages->pc,
//				cw->carriages->champ->name);
//		cw->carriages = cw->carriages->next;
//	}
	display_map(64, cw->map);
	display_start_message(cw->champs) && run_battle(cw);

}
