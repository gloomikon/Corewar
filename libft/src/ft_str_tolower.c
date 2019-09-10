/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:47:12 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/10 15:47:21 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(char *str)
{
	char	*new;
	int		i;

	if (!str)
		return (NULL);
	new = ft_memalloc(ft_strlen(str) + 1);
	i = -1;
	while (str[++i])
		new[i] = ft_tolower(str[i]);
	return (new);
}
