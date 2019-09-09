/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit_sign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:12:54 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:22:52 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_digit_sign(t_pf_env *e)
{
	if (e->flag.f & F_PLUS)
		e->ret += write(e->fd, "+", 1);
	else if (e->flag.f & F_SPACE)
		e->ret += write(e->fd, " ", 1);
	else if (e->flag.f & F_NEGATIVE)
		e->ret += write(e->fd, "-", 1);
}
