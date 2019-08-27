/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:00:50 by mzhurba           #+#    #+#             */
/*   Updated: 2018/10/27 18:52:38 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_c;
	unsigned char	*s2_c;
	size_t			i;

	s1_c = (unsigned char*)s1;
	s2_c = (unsigned char*)s2;
	i = -1;
	while (++i < n)
		if (s1_c[i] != s2_c[i])
			return (s1_c[i] - s2_c[i]);
	return (0);
}
