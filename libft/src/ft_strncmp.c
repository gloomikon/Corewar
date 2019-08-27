/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 10:26:30 by mzhurba           #+#    #+#             */
/*   Updated: 2018/11/08 17:16:31 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l;
	size_t	l1;
	size_t	l2;
	int		r;

	l1 = ft_strlen(s1) + 1;
	l2 = ft_strlen(s2) + 1;
	l = (l2 < n) ? l2 : n;
	l = (l1 < l) ? l1 : l;
	r = ft_memcmp(s1, s2, l);
	return (r);
}
