/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exponent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:57:08 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 15:16:26 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	get_exponent(long double d, char type, char **expo)
{
	int		ex;
	char	*tmp1;
	char	*tmp2;

	d *= d < 0 ? -1 : 1;
	ex = 0;
	while (d < 1)
	{
		d *= 10;
		ex--;
	}
	while (d >= 10)
	{
		d /= 10;
		ex++;
	}
	if (ex > 9 || ex < -9)
		tmp1 = ft_strjoin(type == 'e' ? "e" : "E", ex < 0 ? "-" : "+");
	else
		tmp1 = ft_strjoin(type == 'e' ? "e" : "E", ex < 0 ? "-0" : "+0");
	tmp2 = ft_itoa(ex < 0 ? ex * -1 : ex);
	*expo = ft_strjoin(tmp1, tmp2);
	free(tmp1);
	free(tmp2);
}
