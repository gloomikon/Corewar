/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:47:57 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/17 16:11:34 by mzhurba          ###   ########.fr       */
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

t_carriage	*new_carriage(t_champ *champ, int pc)
{
	t_carriage		*carriage;
	static uint32_t	carrige_id;

	if (!(carriage = ft_memalloc(sizeof(t_carriage))))
		terminate(MEMORY_ALLOCATION);
	if (!(carriage->reg = ft_memalloc(sizeof(int) * REG_NUMBER)))
		terminate(MEMORY_ALLOCATION);
	carriage->id = ++carrige_id;
	carriage->pc = pc;
	carriage->reg[0] = -(champ->id);
	carriage->champ = champ;
	return (carriage);
}
