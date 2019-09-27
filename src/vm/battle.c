/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:53:15 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/27 19:53:25 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_instructions.h"

int		run_battle(t_corewar *cw)
{
	while (cw->carriages_num)
	{
		if (cw->cycles == cw->dump_cycles)
		{
			display_map(cw->dump_mode, cw->map);
			exit(0);
		}
		if (cw->debug_cycles > 0 && (cw->cycles % cw->debug_cycles) == 0)
		{
			display_map(cw->debug_mode, cw->map);
			getchar();
		}
		execute_one_cycle(cw);
		if (cw->cycles_to_die <= 0
		|| cw->cycles_to_die == cw->cycles_after_check)
			update_cycles_to_die(cw);
	}
	return (1);
}

void	execute_one_cycle(t_corewar *cw)
{
	t_carriage	*carriage;

	++(cw->cycles_after_check) && ++(cw->cycles);
	carriage = cw->carriages;
	if (cw->verbose & CYCLES)
		ft_printf("It is now cycle %d\n", cw->cycles);
	while (carriage)
		execute_instruction(carriage, cw) && (carriage = carriage->next);
}

void	update_carriage_cycles(t_carriage *carriage, t_corewar *cw)
{
	if (!carriage->cycles_to_ex)
	{
		carriage->instruction = cw->map[carriage->pc];
		(carriage->instruction >= 1 && carriage->instruction <= 16) &&
		(carriage->cycles_to_ex = g_inst[carriage->instruction - 1].cycles);
	}
}

int		execute_instruction(t_carriage *carriage, t_corewar *cw)
{
	t_inst	*inst;

	update_carriage_cycles(carriage, cw);
	(carriage->cycles_to_ex > 0) && --(carriage->cycles_to_ex);
	if (!carriage->cycles_to_ex)
	{
		if (carriage->instruction >= 1 && carriage->instruction <= 16)
		{
			inst = &(g_inst[carriage->instruction - 1]);
			get_inst_args(inst, carriage, cw);
			if (args_valid(carriage, inst, cw))
				inst->func(cw, carriage);
			else
				carriage->step += step(carriage, inst);
			if (carriage->step && (cw->verbose & PC))
				verbose_pc(carriage, cw->map);
		}
		else
			carriage->step = 1;
		move_carriage(carriage, cw);
	}
	return (1);
}

void	move_carriage(t_carriage *carriage, t_corewar *cw)
{
	if (cw->visual)
		dull_carriage(carriage, cw);
	carriage->pc += carriage->step;
	carriage->pc = calculate_address(carriage->pc);
	carriage->step = 0;
	if (cw->visual)
		highlight_carriage(carriage, cw);
	carriage->args_types[0] = 0;
	carriage->args_types[1] = 0;
	carriage->args_types[2] = 0;
}
