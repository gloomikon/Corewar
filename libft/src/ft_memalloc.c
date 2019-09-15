/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 18:32:34 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/15 18:18:29 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = (char*)malloc(size);
	if (ptr)
		while (++i < (int)size)
			ptr[i] = 0;
	else
		return (NULL);
	return (ptr);
}
