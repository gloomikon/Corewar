/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:55:59 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/20 16:50:50 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_instructions.h"

bool	args_valid(t_carriage *carriage, t_inst *inst, t_corewar *cw)
{
	uint32_t	step;
	int			i;

	if (!(args_types_valid(carriage, inst)))
		return (false);
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

bool	args_types_valid(t_carriage *carriage, t_inst *inst)
{
	int	i;

	i = -1;
	while (++i < inst->args_num)
		if (!(carriage->args_types[i] & inst->args_types[i]))
			return (false);
	return (true);
}

bool	t_reg(int pc, int step, t_corewar *cw)
{
	int8_t	byte;

	byte = cw->map[calculate_address(pc + step)];
	return (byte > 0 && byte <= REG_NUMBER);
}
