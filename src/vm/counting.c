/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:59:18 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/20 17:29:17 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_instructions.h"

int			calculate_address(int address)
{
	address %= MEM_SIZE;
	address += address < 0 ? MEM_SIZE : 0;
	return (address);
}

uint32_t	arg_size(uint8_t arg, t_inst *inst)
{
	if (arg & T_REG)
		return (1);
	else if (arg & T_DIR)
		return (inst->t_dir_size);
	else if (arg & T_IND)
		return (2);
	else
		return (0);
}

uint32_t	step(t_carriage *carriage, t_inst *inst)
{
	uint32_t	step;
	int			i;

	step = 1 + (inst->args_types_code);
	i = -1;
	while (++i < g_inst[carriage->instruction - 1].args_num)
		step += arg_size(carriage->args_types[i], inst);
	return (step);
}
