/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:31:58 by mzhurba           #+#    #+#             */
/*   Updated: 2018/10/26 12:45:58 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst_c;
	char	*src_c;
	size_t	i;

	dst_c = (char*)dst;
	src_c = (char*)src;
	i = -1;
	while (++i < n)
		dst_c[i] = src_c[i];
	return (dst);
}
