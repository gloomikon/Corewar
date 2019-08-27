/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:04:50 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 14:04:51 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_tag(const char *restrict format, t_pf_env *e)
{
	int	i;
	int	tmp;

	init_flag(&e->flag);
	e->flag.f |= SM_NO_MOD;
	i = 0;
	if (IS_NUM(format[e->i]))
	{
		tmp = ft_atoi(format + e->i);
		while (IS_NUM(format[e->i + i]))
			i++;
		if (format[e->i + i] == '$')
		{
			e->tag = tmp;
			e->i += i + 1;
		}
	}
}
