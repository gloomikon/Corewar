/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_char_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:07:47 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:16:26 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_char_arg(t_pf_env *e, int *tmp)
{
	if (e->tag)
	{
		va_copy(e->ap[0], e->ap[1]);
		while (--e->tag >= 0)
			*tmp = va_arg(e->ap[0], int);
	}
	else
		*tmp = va_arg(e->ap[0], int);
}
