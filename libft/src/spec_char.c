/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:16:31 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 23:59:18 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	spec_char(t_pf_env *e, char type)
{
	char	*stmp;
	int		ctmp;

	e->flag.f & F_MINUS ? e->flag.f &= ~F_ZERO : 0;
	if (type == 's')
	{
		init_str_arg(e, &stmp);
		if (stmp == NULL)
			e->out = ft_strdup("(null)");
		else if (!e->flag.prec)
			e->out = ft_strdup("\0");
		else
			e->out = ft_strdup((char*)stmp);
		print_str(e);
	}
	else if (type == 'c')
	{
		init_char_arg(e, &ctmp);
		print_char(e, ctmp);
	}
}
