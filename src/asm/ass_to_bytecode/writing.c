/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:44:52 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/06 17:44:59 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

void	write_to_bytecode(char *code, int pos, int8_t data, size_t size)
{
	int	i;

	i = 0;
	while (size)
	{
		code[pos + (size - 1)] = (data >> i) & 0xFF;
		--size;
		i += 8;
	}
}
