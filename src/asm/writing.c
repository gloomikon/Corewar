/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:44:52 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/09 21:15:03 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

void	write_to_bytecode(char *code, int pos, int32_t data, size_t size)
{
	int8_t	i;

	i = 0;
	printf("pos = %d data = %d size = %lu\n", pos, data, size);
	while (size)
	{
		code[pos + (size - 1)] = (uint8_t)((data >> i) & 0xFF);
		--size;
		i += 8;
	}
}
