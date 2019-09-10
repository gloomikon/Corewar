/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_ptraddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:17:15 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:19:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spec_ptraddr(t_pf_env *e, char type)
{
	long			tmp;
	unsigned long	addr;

	init_int_arg(e, &tmp);
	addr = (unsigned long)tmp;
	if (e->flag.prec == 0)
		e->out = ft_strdup("\0");
	else
		e->out = ft_ltoa_base(addr, 16);
	print_ptraddr(e, type);
}
