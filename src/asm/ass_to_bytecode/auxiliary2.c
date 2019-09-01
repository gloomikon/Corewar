/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:44:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/01 14:44:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

void	upd_row(char **row, char *ptr)
{
	char	*new;

	new = ft_strdup(ptr);
	ft_strdel(row);
	*row = new;
}

void	upd_pars_row_and_col(t_pars *pars, char const *row)
{
	size_t	i;

	i = (pars->col)++;
	while (row[++i]!= '\0' && row[i] != '"')
		row[i] == '\n' ? (++(pars->row)) && (pars->col = 0) : (++(pars->col));
}

int		skip_whitespaces(int *col, char *row)
{
	while (ft_isspace(row[*col]) && (row[*col] != '\n'))
		++(*col);
	return (1);
}

int		skip_comment(int *col, char const *row)
{
	if (row[*col] == COMMENT_CHAR
		|| row[*col] == ANOTHER_COMMENT_CHAR)
		while (row[*col] != '\0' && row[*col] != '\n')
			++(*col);
	return (1);
}
