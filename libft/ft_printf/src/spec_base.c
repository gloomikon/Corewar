/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:24 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:19:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spec_base(t_pf_env *e, char tp)
{
	long			tmp;
	unsigned long	val;

	val = 0;
	init_int_arg(e, &tmp);
	if (tp == 'O' || (e->flag.f & (SM_Z | SM_T | SM_J | SM_L | SM_LL)))
		val = (unsigned long)tmp;
	else if (e->flag.f & (SM_H))
		val = (unsigned short)tmp;
	else if (e->flag.f & (SM_HH))
		val = (unsigned char)tmp;
	else if (e->flag.f & SM_NO_MOD)
		val = (unsigned int)tmp;
	(tp == 'b' || tp == 'B') ? e->out = ft_ultoa_base(val, 2) : 0;
	(tp == 'o' || tp == 'O') ? e->out = ft_ultoa_base(val, 8) : 0;
	(tp == 'x' || tp == 'X') ? e->out = ft_ultoa_base(val, 16) : 0;
	if (tp == 'b' || tp == 'o' || tp == 'x')
		ft_strlower(e->out);
	e->flag.f & F_MINUS ? e->flag.f &= ~F_ZERO : 0;
	print_base(e, tp, (long)val);
}
