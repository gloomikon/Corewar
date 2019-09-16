/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:46:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/16 16:46:16 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "header.h"
# include "op.h"
# include "common.h"

typedef struct s_corewar	t_corewar;
typedef struct s_champ		t_champ;

/*
**	COMMON
*/

bool	check_file_extension(char *file, char *ext);
void	terminate(char *message);

struct s_champ
{
	int		id;
	char	*name;
	char	*comment;
	t_champ	*next;
};

struct s_corewar
{
	uint8_t	*map;
	t_champ	**champs;
	int		champs_num;
	int		dump_mode;
	int		dump_cycles;
};

t_corewar	*new_corewar(void);

#endif