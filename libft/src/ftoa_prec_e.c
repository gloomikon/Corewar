/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_prec_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:52:55 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:16:26 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ftoa_prec_e(t_pf_env *e, long double d, char type)
{
	char	*tmp;
	char	*nb;
	char	*expo;
	long	num;
	int		prec;

	prec = (e->flag.prec >= 0 ? e->flag.prec : 6);
	num = (d == 0 ? 0 : get_prec_num_e(d, prec));
	nb = (d == 0 ? ft_strdup("0000000") : ft_ftoa(num));
	d == 0 ? expo = ft_strjoin(&type, "+00") : get_exponent(d, type, &expo);
	tmp = (d < 0 ? ft_str_prec(nb, 2, prec + 1, e->flag.f & F_HASH)
	: ft_str_prec(nb, 1, prec, e->flag.f & F_HASH));
	e->out = ft_strjoin(tmp, expo);
	free(nb);
	free(tmp);
	free(expo);
}
