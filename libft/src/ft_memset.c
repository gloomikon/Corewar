/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:33:56 by mzhurba           #+#    #+#             */
/*   Updated: 2018/10/26 11:53:07 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	char	*ptr;
	size_t	i;

	ptr = (char*)memptr;
	i = -1;
	while (++i < num)
		ptr[i] = (char)val;
	return (memptr);
}
