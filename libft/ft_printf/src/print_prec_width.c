/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:14:31 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:23:07 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_prec_width(t_pf_env *e)
{
	int i;
	int len;

	i = -1;
	len = ft_strlen(e->out) + ((e->flag.f & F_PLUS) / F_PLUS) +
		((e->flag.f & F_SPACE) / F_SPACE);
	if (e->flag.prec >= 0)
	{
		while (e->flag.width - ++i > len)
			e->ret += e->flag.f & F_ZERO ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1);
		i = -1;
		while ((int)ft_strlen(e->out) < len - ++i)
			e->ret += write(e->fd, "0", 1);
	}
	else
		while (e->flag.width - ++i > len)
			e->ret += (e->flag.f & F_ZERO ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
}
