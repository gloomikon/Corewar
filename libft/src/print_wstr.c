/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:15:44 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:19:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_wstr(t_pf_env *e, wchar_t *wc)
{
	int i;
	int len;

	i = -1;
	len = (e->flag.prec < 0 ? ft_wstrlen(wc) : e->flag.prec);
	if (e->flag.f & F_MINUS)
		print_wstr_minus(e, wc, len);
	else
	{
		while (e->flag.width-- > len)
			e->ret += (e->flag.f & F_ZERO ?
			write(e->fd, "0", 1) : write(e->fd, " ", 1));
		if (e->flag.prec >= 0)
			while (wc[++i] != 0 && i * 4 < e->flag.prec)
				put_wstr(e, wc[i]);
		else
			while (wc[++i] != 0)
				put_wstr(e, wc[i]);
	}
	++e->i;
}
