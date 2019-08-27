/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_non_printable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:43:20 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/03 00:41:56 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_zero_to_ten(t_pf_env *e, char c)
{
	if (c == 0)
		e->ret += write(e->fd, "[NUL]", 5);
	else if (c == 1)
		e->ret += write(e->fd, "[SOH]", 5);
	else if (c == 2)
		e->ret += write(e->fd, "[STX]", 5);
	else if (c == 3)
		e->ret += write(e->fd, "[ETX]", 5);
	else if (c == 4)
		e->ret += write(e->fd, "[EOT]", 5);
	else if (c == 5)
		e->ret += write(e->fd, "[ENQ]", 5);
	else if (c == 6)
		e->ret += write(e->fd, "[ACK]", 5);
	else if (c == 7)
		e->ret += write(e->fd, "[BEL]", 5);
	else if (c == 8)
		e->ret += write(e->fd, "[BS]", 4);
	else if (c == 9)
		e->ret += write(e->fd, "[TAB]", 5);
	else if (c == 10)
		e->ret += write(e->fd, "[LF]", 4);
}

void	print_ten_to_twenty(t_pf_env *e, char c)
{
	if (c == 11)
		e->ret += write(e->fd, "[VT]", 5);
	else if (c == 12)
		e->ret += write(e->fd, "[FF]", 4);
	else if (c == 13)
		e->ret += write(e->fd, "[CR]", 4);
	else if (c == 14)
		e->ret += write(e->fd, "[SO]", 4);
	else if (c == 15)
		e->ret += write(e->fd, "[SI]", 4);
	else if (c == 16)
		e->ret += write(e->fd, "[DLE]", 5);
	else if (c == 17)
		e->ret += write(e->fd, "[DC1]", 5);
	else if (c == 18)
		e->ret += write(e->fd, "[DC2]", 5);
	else if (c == 19)
		e->ret += write(e->fd, "[DC3]", 5);
	else if (c == 20)
		e->ret += write(e->fd, "[DC4]", 5);
}

void	print_twenty_to_thirty(t_pf_env *e, char c)
{
	if (c == 21)
		e->ret += write(e->fd, "[NAK]", 5);
	else if (c == 22)
		e->ret += write(e->fd, "[SYN]", 5);
	else if (c == 23)
		e->ret += write(e->fd, "[ETB]", 5);
	else if (c == 24)
		e->ret += write(e->fd, "[CAN]", 5);
	else if (c == 25)
		e->ret += write(e->fd, "[EM]", 4);
	else if (c == 26)
		e->ret += write(e->fd, "[SUB]", 5);
	else if (c == 27)
		e->ret += write(e->fd, "[ESC]", 5);
	else if (c == 28)
		e->ret += write(e->fd, "[FS]", 4);
	else if (c == 29)
		e->ret += write(e->fd, "[GS]", 4);
	else if (c == 30)
		e->ret += write(e->fd, "[RS]", 4);
	else if (c == 31)
		e->ret += write(e->fd, "[US]", 4);
}

void	spec_non_printable(t_pf_env *e)
{
	char	*tmp;
	int		i;

	init_str_arg(e, &tmp);
	i = -1;
	e->flag.width = e->flag.width ? e->flag.width : ft_strlen(tmp);
	while (++i < e->flag.width)
	{
		if (tmp[i] >= 0 && tmp[i] <= 10)
			print_zero_to_ten(e, tmp[i]);
		else if (tmp[i] >= 11 && tmp[i] <= 20)
			print_ten_to_twenty(e, tmp[i]);
		else if (tmp[i] >= 21 && tmp[i] <= 31)
			print_twenty_to_thirty(e, tmp[i]);
		else
			e->ret += write(e->fd, &tmp[i], 1);
	}
	++e->i;
}
