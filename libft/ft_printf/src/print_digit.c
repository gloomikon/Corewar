/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:13:15 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 14:13:15 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_digit(t_pf_env *e)
{
	check_digit_prec(e);
	if (e->flag.f & F_ZERO)
	{
		print_digit_sign(e);
		print_digit_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	else if (e->flag.f & F_MINUS)
	{
		print_digit_sign(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_digit_width(e);
	}
	else
	{
		print_digit_width(e);
		print_digit_sign(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
