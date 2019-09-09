/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_unsint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:17:27 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 18:52:14 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spec_unsint(t_pf_env *e, char t)
{
	long tmp;

	e->flag.f &= ~F_SPACE;
	e->flag.f &= ~F_PLUS;
	e->flag.f & F_MINUS ? e->flag.f &= ~F_ZERO : 0;
	init_int_arg(e, &tmp);
	if (tmp == LLONG_MIN || tmp == LONG_MIN)
		e->out = ft_strdup("-9223372036854775808");
	else if (t == 'D' || t == 'U' ||
		(e->flag.f & (SM_L | SM_T | SM_J | SM_LL)))
		e->out = ft_ultoa((unsigned long)tmp);
	else if (e->flag.f & SM_Z)
		e->out = ft_ltoa((long)tmp);
	else if (e->flag.f & SM_H)
		e->out = ft_ultoa((unsigned short)tmp);
	else if (e->flag.f & SM_HH)
		e->out = ft_ultoa((unsigned char)tmp);
	else if ((e->flag.f & (SM_BIG_L | SM_NO_MOD)) && t != 'U')
		e->out = ft_ultoa((unsigned int)tmp);
	print_digit(e);
}
