/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:32:34 by mzhurba           #+#    #+#             */
/*   Updated: 2018/11/08 16:46:36 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*ptr;

	i = -1;
	ptr = (char*)malloc(size);
	if (ptr)
		while (++i < size)
			ptr[i] = 0;
	else
		return (NULL);
	return (ptr);
}
