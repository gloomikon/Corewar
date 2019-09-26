/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:44:52 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/26 16:08:10 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_to_bytecode(char *code, int pos, int32_t data, size_t size)
{
	int8_t	i;

	i = 0;
	while (size)
	{
		code[pos + (size - 1)] = (uint8_t)((data >> i) & 0xFF);
		--size;
		i += 8;
	}
}

void	write_code_to_bytecode(t_pars *pars, int fd)
{
	char	*bcode;
	int		len;

	len = 4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4 + pars->pos;
	if (!(bcode = ft_memalloc(sizeof(char) * (len + 1))))
		terminate(MEMORY_ALLOCATION);
	write_to_bytecode(bcode, 0, COREWAR_EXEC_MAGIC, 4);
	ft_memcpy(&(bcode[4]), pars->name, ft_strlen(pars->name));
	write_to_bytecode(bcode, 4 + PROG_NAME_LENGTH + 4, pars->pos, 4);
	ft_memcpy(&(bcode[4 + PROG_NAME_LENGTH + 4 + 4]), pars->comment,
			ft_strlen(pars->comment));
	ft_memcpy(&(bcode[4 + PROG_NAME_LENGTH + 4 + 4 + COMMENT_LENGTH + 4]),
			pars->code, pars->pos);
	write(fd, bcode, len);
	ft_strdel(&bcode);
}
