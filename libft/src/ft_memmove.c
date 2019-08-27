/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:50:11 by mzhurba           #+#    #+#             */
/*   Updated: 2018/10/26 17:57:32 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst_c;
	char	*src_c;
	size_t	i;
	int		int_n;

	i = -1;
	int_n = (int)n;
	dst_c = (char*)dst;
	src_c = (char*)src;
	if (src_c < dst_c)
		while (--int_n >= 0)
			dst_c[int_n] = src_c[int_n];
	else
		while (++i < n)
			dst_c[i] = src_c[i];
	return (dst);
}
