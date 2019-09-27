/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_9_12.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:12:06 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/25 15:04:58 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_instructions.h"

void	inst_zjmp(t_corewar *cw, t_carriage *carriage)
{
	int	address;

	carriage->step += 1;
	address = get_inst_argument(carriage, 0, true, cw);
	if (carriage->carry == true)
	{
		if (cw->visual)
			dull_carriage(carriage, cw);
		carriage->pc = calculate_address(carriage->pc + (address % IDX_MOD));
		carriage->step = 0;
		if (cw->visual)
			highlight_carriage(carriage, cw);
	}
	if (cw->verbose & OPS)
		ft_printf("P %4d | zjmp %d %s\n",
			carriage->id, address, (carriage->carry) ? "OK" : "FAILED");
}

void	inst_ldi(t_corewar *cw, t_carriage *carriage)
{
	int	reg;
	int	address1;
	int	address2;

	carriage->step += 2;
	address1 = get_inst_argument(carriage, 0, true, cw);
	address2 = get_inst_argument(carriage, 1, true, cw);
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	carriage->reg[reg - 1] = get_int(cw->map,
			carriage->pc + (address1 + address2) % IDX_MOD,
			DIR_SIZE);
	carriage->step += 1;
	if (cw->verbose & OPS)
		ft_printf("P %4d | ldi %d %d r%d\n", carriage->id, address1, address2,
				reg) &&
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
								address1, address2, address1 + address2,
								carriage->pc + (address1 + address2) % IDX_MOD);
}

void	inst_sti(t_corewar *cw, t_carriage *carriage)
{
	int	reg;
	int	address1;
	int	address2;
	int	val;

	carriage->step += 2;
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	val = carriage->reg[reg - 1];
	++(carriage->step);
	address1 = get_inst_argument(carriage, 1, true, cw);
	address2 = get_inst_argument(carriage, 2, true, cw);
	write_to_bytecode(cw->map, carriage->pc + (address1 + address2) % IDX_MOD,
			val, DIR_SIZE);
	(cw->visual) && upd_map_ind(cw, carriage, carriage->pc +
	(address1 + address2) % IDX_MOD, DIR_SIZE);
	if (cw->verbose & OPS)
		ft_printf("P %4d | sti r%d %d %d\n",
				carriage->id, reg, address1, address2) &&
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
							address1, address2, address1 + address2,
							carriage->pc + ((address1 + address2) % IDX_MOD));
}

void	inst_fork(t_corewar *cw, t_carriage *carriage)
{
	int	address;

	carriage->step += 1;
	address = get_inst_argument(carriage, 0, true, cw);
	add_carriage(&(cw->carriages),
			dup_carriage(carriage, address % IDX_MOD, cw));
	++(cw->carriages_num);
	if (cw->verbose & OPS)
		ft_printf("P %4d | fork %d (%d)\n",
				carriage->id, address, carriage->pc + address % IDX_MOD);
}
