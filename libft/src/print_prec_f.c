/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prec_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:14:16 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:19:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_prec_f(t_pf_env *e, long double d)
{
	ftoa_prec_f(e, d);
	if (e->flag.f & F_MINUS)
	{
		if (d > 0 && (e->flag.f & (F_PLUS | F_SPACE)))
			e->ret += (e->flag.f & F_PLUS ?
			write(e->fd, "+", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_prec_width(e);
	}
	else
	{
		print_prec_width(e);
		if (d > 0 && (e->flag.f & (F_PLUS | F_SPACE)))
			e->ret += (e->flag.f & F_PLUS ?
			write(e->fd, "+", 1) : write(e->fd, " ", 1));
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
