/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:44:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/15 17:56:35 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	upd_row(char **row, char *ptr)
{
	char	*new;

	if (!(new = ft_strdup(ptr)))
		terminate(MEMORY_ALLOCATION);
	ft_strdel(row);
	*row = new;
}

void	upd_pars_row_and_col(t_pars *pars, char const *row)
{
	size_t	i;

	i = (pars->col)++;
	while (row[++i] != '\0' && row[i] != '"')
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

bool	is_command(t_pars *pars, char *row)
{
	return ((!ft_strncmp(row + pars->col, NAME_CMD_STRING,
								ft_strlen(NAME_CMD_STRING))
			&& is_delimiter(row[pars->col + ft_strlen(NAME_CMD_STRING)]))
			|| (!ft_strncmp(row + pars->col, COMMENT_CMD_STRING,
								ft_strlen(COMMENT_CMD_STRING))
			&& is_delimiter(row[pars->col + ft_strlen(COMMENT_CMD_STRING)])));
}
