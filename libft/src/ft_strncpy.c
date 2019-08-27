/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 13:05:57 by mzhurba           #+#    #+#             */
/*   Updated: 2018/10/27 19:10:49 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(src);
	i = -1;
	while (++i < len)
		if (i < n)
			dst[i] = src[i];
		else if (i >= n)
			dst[i] = '\0';
	return (dst);
}
