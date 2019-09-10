/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_spec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:13:20 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:19:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_invalid_spec(t_pf_env *e, char c)
{
	if (e->flag.f & F_MINUS)
	{
		e->ret += write(e->fd, &c, 1);
		print_invalid_width(e);
	}
	else
	{
		print_invalid_width(e);
		e->ret += write(e->fd, &c, 1);
	}
	++e->i;
}
