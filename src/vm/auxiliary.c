/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:38:39 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/20 14:16:42 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_instructions.h"

t_champ	*find_champ(t_champ *lst, int id)
{
	while (lst)
	{
		if (lst->id == id)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	list_to_array(t_champ *lst, t_corewar *cw)
{
	int		id;
	t_champ	*old;

	if (!lst)
		display_usage();
	old = lst;
	while (lst)
	{
		if (lst->id == 0 && (id = 1))
		{
			while (find_champ(old, id))
				++id;
			lst->id = id;
		}
		if (lst->id > cw->champs_num)
			display_usage();
		cw->champs[lst->id - 1] = lst;
		lst = lst->next;
	}
	cw->last = cw->champs[cw->champs_num - 1];
}

void	get_inst_args(t_inst *inst,
					t_carriage *carriage,
					t_corewar *cw)
{
	int8_t	code;

	if (inst->args_types_code == false)
		carriage->args_types[0] = T_DIR;
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

int		get_inst_argument(t_carriage *carriage, uint8_t pos, bool mod,
							t_corewar *cw)
{
	int		address;
	int		value;
	t_inst	*inst;

	value = 0;
	inst = &(g_inst[carriage->instruction - 1]);
	(carriage->args_types[pos] & T_REG) &&
	(value = carriage->reg[cw->map[calculate_address(
			carriage->pc + carriage->step)] - 1]);
	(carriage->args_types[pos] & T_DIR) &&
	(value = get_int(cw->map, carriage->pc + carriage->step, inst->t_dir_size));
	if (carriage->args_types[pos] & T_IND)
	{
		address = get_int(cw->map, carriage->pc + carriage->step, IND_SIZE);
		value = get_int(cw->map,
				carriage->pc + (mod ? address % IDX_MOD : address), DIR_SIZE);
	}
	carriage->step += arg_size(carriage->args_types[pos], inst);
	return (value);
}

void	write_to_bytecode(uint8_t *map, int address, int value, int size)
{
	int8_t	i;

	i = 0;
	while (size)
	{
		map[calculate_address(address + size - 1)] =
				(uint8_t)((value >> i) & 0xFF);
		--size;
		i += 8;
	}
}
