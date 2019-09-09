/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:57:25 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/09 19:54:12 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_flag(const char *restrict format, t_pf_env *e)
{
	while (ft_strchr(FLAGS, format[e->i]))
	{
		format[e->i] >= 'L' && format[e->i] <= 'z' ? get_mod(format, e) : 0;
		(ft_strchri(FLAGS, format[e->i]) <= 4) ?
			e->flag.f |= (1 << ft_strchri(FLAGS, format[e->i])) : 0;
		format[e->i] == '*' ? get_width(e) : 0;
		if (format[e->i] == '.')
			get_precision(format, e);
		else if (IS_PNUM(format[e->i]) && e->flag.prec < 0)
		{
			e->flag.width = ft_atoi(format + e->i);
			while (IS_NUM(format[e->i]))
				++e->i;
		}
		else
			++e->i;
	}
}
