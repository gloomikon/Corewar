/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:47:36 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:16:26 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_form(t_pf_env *e, long double d, char type)
{
	char	*nb;
	int		neg;

	neg = (d < 0 ? -1 : 1);
	d *= neg;
	if ((d + 0.5 > 1000000 || d < 0.0001) && e->flag.prec < 0 &&
		d != 0)
		return (ftoa_prec_eg(e, d * neg, type - 2, 5));
	else if (e->flag.prec < 0)
		return (ftoa_prec_fg(e, d * neg, 6));
	nb = ft_ltoa((long)d);
	if (((int)ft_strlen(nb) > e->flag.prec && e->flag.prec != 0) ||
		(e->flag.prec == 0 && d >= 10))
	{
		free(nb);
		return (ftoa_prec_eg(e, d * neg, type - 2, e->flag.prec - 1));
	}
	free(nb);
	ftoa_prec_fg(e, d * neg, e->flag.prec);
}
