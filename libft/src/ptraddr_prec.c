/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptraddr_prec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:15:50 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:19:37 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ptraddr_prec(t_pf_env *e)
{
	char	*tmp;
	int		i;
	int		len;
	char	*res;

	i = -1;
	len = (int)ft_strlen(e->out);
	if (e->flag.prec > len)
	{
		tmp = ft_strnew(e->flag.prec - len);
		while (++i < e->flag.prec - len)
			tmp[i] = '0';
		res = ft_strjoin(tmp, e->out);
		free(e->out);
		free(tmp);
		e->out = res;
	}
	tmp = ft_strjoin("0x", e->out);
	free(e->out);
	e->out = tmp;
}
