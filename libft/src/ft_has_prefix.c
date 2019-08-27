/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_prefix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:29:08 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/24 16:30:25 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_has_prefix(const char *str, int base)
{
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[0] != '0')
			return (0);
		if (base == 2 && (str[1] == 'b' || str[1] == 'B'))
			return (1);
		if (base == 16 && (str[1] == 'x' || str[1] == 'X'))
			return (1);
		if (base == 8)
			return (1);
	}
	return (0);
}
