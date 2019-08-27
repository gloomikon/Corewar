/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 18:09:08 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/15 20:04:41 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *str, char c)
{
	int i;
	int space;
	int	words;

	i = -1;
	space = 1;
	words = 0;
	while (str[++i])
		if (str[i] == c)
			space = 1;
		else
		{
			if (space)
				words++;
			space = 0;
		}
	return (words);
}

char			**ft_strsplit(char const *str, char c)
{
	char	**words;
	int		i;
	int		k;
	int		w;

	words = (char**)malloc(sizeof(char*) * (count_words(str, c) + 1));
	words[count_words(str, c)] = NULL;
	w = -1;
	i = -1;
	while (str[++i])
		if ((str[i] != c) && (k = 0) == 0)
		{
			while (str[i + k] && (str[i + k] != c))
				k++;
			words[++w] = (char*)malloc(k);
			k = 0;
			while (str[i + k] && (str[i + k]) != c)
			{
				words[w][k] = str[i + k];
				k++;
			}
			words[w][k] = '\0';
			i = i + k - 1;
		}
	return (words);
}
