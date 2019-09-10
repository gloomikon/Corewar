/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi32.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:25:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/09 21:21:38 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t		ft_atoi32(const char *str)
{
	size_t			i;
	int				sign;
	unsigned long	result;
	unsigned long	border;

	border = (unsigned long)(LONG_MAX / 10);
	i = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] != '-') ? 1 : -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		if ((result > border || (result == border && (str[i] - '0') > 7))
			&& sign == 1)
			return (-1);
		else if ((result > border || (result == border && (str[i] - '0') > 8))
				 && sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int32_t)(result * sign));
}
