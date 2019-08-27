/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_prec_fg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:57:01 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:16:26 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ftoa_prec_fg(t_pf_env *e, long double d, int end)
{
	int		prec;
	char	*tmp;
	char	*nb;
	long	num;

	tmp = ft_ltoa((long)d);
	end -= ft_strlen(tmp) - 1;
	d == 0 ? --e->flag.prec : 0;
	d == 0 ? --end : 0;
	prec = ft_strlen(tmp);
	num = get_prec_num_f(d, end);
	nb = (num == 0 ? ft_strdup("0000000") : ft_ftoa(num));
	if ((end <= prec || d == (long)d) && !(e->flag.f & F_HASH))
		e->out = ft_strdup(tmp);
	else
		e->out = ft_str_prec(nb, prec, end, 0);
	if (!(e->flag.f & F_HASH) && d - (long)d != 0)
		delete_zero(e->out);
	free(tmp);
	free(nb);
}
