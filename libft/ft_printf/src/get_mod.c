/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:57:37 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/03 00:47:46 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	get_mod(const char *restrict format, t_pf_env *e)
{
	if (e->flag.f & SM_NO_MOD)
	{
		if (format[e->i] == 'h' && format[e->i + 1] == 'h')
		{
			e->flag.f |= SM_HH;
			++e->i;
		}
		else if (format[e->i] == 'l' && format[e->i + 1] == 'l')
		{
			e->flag.f |= SM_LL;
			++e->i;
		}
		else if (ft_strchri(FLAGS, format[e->i]))
			e->flag.f |= (1 << (ft_strchri(FLAGS, format[e->i]) - 6));
		if (e->flag.f & (SM_HH | SM_LL | SM_H | SM_L | SM_Z |
			SM_J | SM_BIG_L | SM_T))
			e->flag.f &= ~SM_NO_MOD;
	}
}
