/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:51:20 by mzhurba           #+#    #+#             */
/*   Updated: 2018/11/08 16:50:33 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*new;
	size_t	i;

	if (!(new = (char*)malloc(n + 1)))
		return (NULL);
	i = -1;
	while (s[++i] && i < n)
		new[i] = s[i];
	new[i] = '\0';
	return (new);
}
