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
	char	*start;

	if (memptr == NULL)
		return (NULL);
	start = memptr;
	while (num)
	{
		*start = val;
		start++;
		num--;
	}
	return (memptr);
}
