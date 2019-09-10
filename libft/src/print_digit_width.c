/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:13:08 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 14:13:08 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_digit_width(t_pf_env *e)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(e->out) > e->flag.prec ?
	ft_strlen(e->out) : e->flag.prec;
	(e->flag.f & (F_PLUS | F_SPACE | F_NEGATIVE)) > 0 ? e->flag.width-- : 0;
	if (e->flag.prec >= 0)
	{
		while (e->flag.width - ++i > len)
			e->ret += write(e->fd, " ", 1);
	}
	else
		while (e->flag.width - ++i > len)
			e->ret += (e->flag.f & F_ZERO) ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1);
}
