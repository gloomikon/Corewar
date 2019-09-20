/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   battle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:53:15 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/20 18:10:51 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_instructions.h"

int		run_battle(t_corewar *cw)
{
	while (cw->carriages_num)
	{
		printf("%d cycles\n", cw->cycles);
		if (cw->cycles == cw->dump_cycles)
		{
			display_map(cw->dump_mode, cw->map);
			system("leaks -q corewar");
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
	while (carriage)
		execute_instruction(carriage, cw) && (carriage = carriage->next);
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
			if (args_valid(carriage, inst, cw))
				inst->func(cw, carriage);
			else
				carriage->step += step(carriage, inst);
		}
		else
			carriage->step = 1;
		move_carriage(carriage, cw);
	}
	return (1);
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
