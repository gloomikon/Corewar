/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptraddr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:14:43 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:19:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_ptraddr(t_pf_env *e, char type)
{
	if ((e->flag.f & F_ZERO) && e->flag.prec == -1)
		e->flag.prec = e->flag.width - 2;
	ptraddr_prec(e);
	if (type == 'p')
		ft_strlower(e->out);
	if (e->flag.f & F_MINUS)
	{
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
		print_ptraddr_width(e);
	}
	else
	{
		print_ptraddr_width(e);
		e->ret += write(e->fd, e->out, ft_strlen(e->out));
	}
	++e->i;
	free(e->out);
}
