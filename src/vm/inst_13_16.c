/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_13_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:35:52 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/20 16:45:42 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_instructions.h"

void	inst_lld(t_corewar *cw, t_carriage *carriage)
{
	int	reg;
	int	value;

	carriage->step += 2;
	value = get_inst_argument(carriage, 0, false, cw);
	carriage->carry = value ? false : true;
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	carriage->reg[reg - 1] = value;
	carriage->step += 1;
}

void	inst_lldi(t_corewar *cw, t_carriage *carriage)
{
	int	reg;
	int	address1;
	int	address2;

	carriage->step += 2;
	address1 = get_inst_argument(carriage, 0, true, cw);
	address2 = get_inst_argument(carriage, 1, true, cw);
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	carriage->reg[reg - 1] = get_int(cw->map,
									carriage->pc + address1 + address2,
									DIR_SIZE);
	carriage->step += 1;
}

void	inst_lfork(t_corewar *cw, t_carriage *carriage)
{
	int			address;

	carriage->step += 1;
	address = get_inst_argument(carriage, 0, true, cw);
	add_carriage(&(cw->carriages), dup_carriage(carriage, address));
	++(cw->carriages_num);
}

void	inst_aff(t_corewar *cw, t_carriage *carriage)
{
	int	val;
	int	reg;

	carriage->step += 2;
	reg = cw->map[calculate_address(carriage->pc + carriage->step)];
	val = carriage->reg[reg - 1];
	++(carriage->step);
	(cw->aff) && ft_printf("Aff: %c\n", (char)val);
}