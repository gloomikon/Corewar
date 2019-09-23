/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_1_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:06:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/22 18:56:02 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_instructions.h"

void	inst_live(t_corewar *cw, t_carriage *carriage)
{
	t_champ	*champ;
	int		id;

	champ = NULL;
	++(cw->lives);
	carriage->step += 1;
	id = get_inst_argument(carriage, 0, false, cw);
	carriage->live_cycle = cw->cycles;
	if (id >= -(cw->champs_num) && id <= -1)
	{
		champ = cw->champs[-id - 1];
		cw->last = champ;
	}
	if (cw->verbose & OPS)
		ft_printf("P %4d | live %d\n", carriage->id, id);
	if ((cw->verbose & LIVES) && champ)
		ft_printf("Player %d (%s) is said to be alive\n", -id, champ->name);
}

void	inst_ld(t_corewar *cw, t_carriage *carriage)
{
	int	reg;
	int	value;

	carriage->step += 2;
	value = get_inst_argument(carriage, 0, true, cw);
	carriage->carry = value ? false : true;
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	carriage->reg[reg - 1] = value;
	carriage->step += 1;
	if (cw->verbose & OPS)
		ft_printf("P %4d | ld %d r%d\n", carriage->id, value, reg);
}

void	inst_st(t_corewar *cw, t_carriage *carriage)
{
	int	value;
	int	address;
	int	reg;

	carriage->step += 2;
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	value = carriage->reg[reg - 1];
	carriage->step += 1;
	if (carriage->args_types[1] != T_REG)
	{
		address = get_int(cw->map, carriage->step + carriage->pc, IND_SIZE);
		write_to_bytecode(cw->map, carriage->pc + (address % IDX_MOD), value,
														DIR_SIZE);
		carriage->step += 2;
	}
	else
	{
		address = cw->map[calculate_address(carriage->pc + carriage->step)];
		carriage->reg[address - 1] = value;
		carriage->step += 1;
	}
	if (cw->verbose & OPS)
		ft_printf("P %4d | st r%d %d\n", carriage->id, reg, address);
}

void	inst_add(t_corewar *cw, t_carriage *carriage)
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
	val = carriage->reg[reg1 - 1] + carriage->reg[reg2 - 1];
	carriage->carry = val ? false : true;
	carriage->reg[reg3 - 1] = val;
	++(carriage->step);
	if (cw->verbose & OPS)
		ft_printf("P %4d | add r%d r%d r%d\n", carriage->id, reg1, reg2, reg3);
}
