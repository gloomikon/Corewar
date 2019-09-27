/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:47:57 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/27 11:54:24 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_corewar	*new_corewar(void)
{
	t_corewar	*corewar;

	if (!(corewar = ft_memalloc(sizeof(t_corewar))))
		terminate(MEMORY_ALLOCATION);
	if (!(corewar->map = ft_memalloc(sizeof(uint8_t) * MEM_SIZE)))
		terminate(MEMORY_ALLOCATION);
	if (!(corewar->champs = ft_memalloc(sizeof(t_champ*) * MAX_PLAYERS)))
		terminate(MEMORY_ALLOCATION);
	corewar->cycles_to_die = CYCLE_TO_DIE;
	corewar->dump_cycles = -1;
	corewar->debug_cycles = -1;
	return (corewar);
}

t_champ		*new_champ(char *file, int id)
{
	int		fd;
	t_champ	*champ;

	if (!(champ = ft_memalloc(sizeof(t_champ))))
		terminate(MEMORY_ALLOCATION);
	champ->id = id;
	if ((fd = open(file, O_RDONLY)) == -1)
		terminate(FILE_OPENING);
	if (read_from_bytecode(fd) != COREWAR_EXEC_MAGIC)
		terminate(INVALID_MAGIC);
	champ->name = read_str_from_bytecode(fd, PROG_NAME_LENGTH);
	if (read_from_bytecode(fd))
		terminate(NULL_BYTES);
	champ->size = read_from_bytecode(fd);
	if (champ->size > CHAMP_MAX_SIZE || champ->size < 0)
		terminate(CODE_SIZE);
	champ->comment = read_str_from_bytecode(fd, COMMENT_LENGTH);
	if (read_from_bytecode(fd))
		terminate(NULL_BYTES);
	champ->code = read_code(fd, champ->size);
	return (champ);
}

t_carriage	*new_carriage(t_champ *champ, int pc, t_corewar *cw)
{
	t_carriage		*carriage;
	static uint32_t	carrige_id;

	if (!(carriage = ft_memalloc(sizeof(t_carriage))))
		terminate(MEMORY_ALLOCATION);
	carriage->id = ++carrige_id;
	carriage->pc = pc;
	carriage->reg[0] = -(champ->id);
	carriage->champ = champ;
	if (cw->carriages_curr == cw->carriages_max)
	{
		cw->carriages_max += 1000;
		if (!(cw->all_carriages = realloc(cw->all_carriages,
				sizeof(t_carriage*) * cw->carriages_max)))
			terminate(MEMORY_ALLOCATION);
	}
//	cw->all_carriages[cw->carriages_curr++] = carriage;
	return (carriage);
}

t_carriage	*dup_carriage(t_carriage *carriage, int address, t_corewar *cw)
{
	int			i;
	t_carriage	*new;

	address += carriage->pc;
	new = new_carriage(carriage->champ, calculate_address(address), cw);
	new->carry = carriage->carry;
	new->live_cycle = carriage->live_cycle;
	i = -1;
	while (++i < REG_NUMBER)
		new->reg[i] = carriage->reg[i];
	return (new);
}

t_visual	*new_visual(void)
{
	t_visual	*visual;

	if (!(visual = ft_memalloc(sizeof(t_visual))))
		terminate(MEMORY_ALLOCATION);
	visual->speed = SPEED;
	visual->pause = false;
	if (!(visual->map = ft_memalloc(sizeof(t_attr) * MEM_SIZE)))
		terminate(MEMORY_ALLOCATION);
	return (visual);
}
