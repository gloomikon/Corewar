/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_prec_eg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:53:14 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:16:26 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ftoa_prec_eg(t_pf_env *e, long double d, char type, int prec)
{
	char	*tmp;
	char	*nb;
	char	*expo;
	long	num;

	prec = (prec == 1 ? 0 : prec);
	num = get_prec_num_e(d, prec);
	nb = ft_ftoa(num);
	get_exponent(d, type, &expo);
	tmp = ft_str_prec(nb, 1 + (d < 0 ? 1 : 0),
	prec + (d < 0 ? 1 : 0), e->flag.f & F_HASH);
	if (!(e->flag.f & F_HASH))
		delete_zero(tmp);
	e->out = ft_strjoin(tmp, expo);
	free(nb);
	free(tmp);
	free(expo);
}
