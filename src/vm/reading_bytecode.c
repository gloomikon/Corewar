/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_bytecode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:53:41 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/17 15:44:12 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		convert_to_int(uint8_t *bytes, size_t size)
{
	int		move;
	int		res;

	move = 0;
	res = 0;
	while (size)
	{
		res += bytes[size - 1] << (move++ * 8);
		--size;
	}
	return (res);
}

int		get_int(uint8_t *map, int address, int size)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (size)
	{
		res += map[calculate_address(address + size - 1)] << (i++ * 8);
		--size;
	}
	return (res);
}

int		read_from_bytecode(int fd)
{
	uint8_t		buff[4];
	size_t		size;

	size = read(fd, &buff, 4);
	if (size == -1)
		terminate(FILE_READING);
	else if (size < 4)
		terminate(FILE_INVALID);
	return (convert_to_int(buff, 4));
}

char	*read_str_from_bytecode(int fd, int length)
{
	int		size;
	char	*buff;

	if (!(buff = ft_strnew(length)))
		terminate(MEMORY_ALLOCATION);
	size = read(fd, buff, length);
	if (size != length)
		terminate(size == -1 ? FILE_OPENING : FILE_INVALID);
	return (buff);
}

uint8_t	*read_code(int fd, int code_size)
{
	uint8_t	*code;
	int		size;
	uint8_t	tmp;

	if (!(code = malloc(sizeof(uint8_t) * code_size)))
		terminate(MEMORY_ALLOCATION);
	size = read(fd, code, code_size);
	if (size != code_size)
		terminate(size == -1 ? FILE_OPENING : FILE_INVALID);
	if (read(fd, &tmp, 1))
		terminate(FILE_INVALID);
	return (code);
}
