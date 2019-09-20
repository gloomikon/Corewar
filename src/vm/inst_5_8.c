/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_5_8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:22:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/20 16:11:48 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_instructions.h"

void	inst_sub(t_corewar *cw, t_carriage *carriage)
{
	int	val;
	int	reg1;
	int	reg2;
	int	reg3;

	carriage->step += 2;
	reg1 = cw->map[calculate_address(carriage->pc + carriage->step)];
	++(carriage->step);
	reg2 = cw->map[calculate_address(carriage->pc + carriage->step)];
	++(carriage->step);
	reg3 = cw->map[calculate_address(carriage->pc + carriage->step)];
	val = carriage->reg[reg1 - 1] - carriage->reg[reg2 - 1];
	carriage->carry = val ? false : true;
	carriage->reg[reg3 - 1] = val;
	++(carriage->step);
}

void	inst_and(t_corewar *cw, t_carriage *carriage)
{
	int	res;
	int	reg;
	int	val1;
	int	val2;

	carriage->step += 2;
	val1 = get_inst_argument(carriage, 0, true, cw);
	val2 = get_inst_argument(carriage, 1, true, cw);
	res = val1 & val2;
	carriage->carry = res ? false : true;
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	carriage->reg[reg - 1] = res;
	carriage->step += 1;
}

void	inst_or(t_corewar *cw, t_carriage *carriage)
{
	int	res;
	int	reg;
	int	val1;
	int	val2;

	carriage->step += 2;
	val1 = get_inst_argument(carriage, 0, true, cw);
	val2 = get_inst_argument(carriage, 1, true, cw);
	res = val1 | val2;
	carriage->carry = res ? false : true;
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	carriage->reg[reg - 1] = res;
	carriage->step += 1;
}

void	inst_xor(t_corewar *cw, t_carriage *carriage)
{
	int	res;
	int	reg;
	int	val1;
	int	val2;

	carriage->step += 2;
	val1 = get_inst_argument(carriage, 0, true, cw);
	val2 = get_inst_argument(carriage, 1, true, cw);
	res = val1 ^ val2;
	carriage->carry = res ? false : true;
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	carriage->reg[reg - 1] = res;
	carriage->step += 1;
}
