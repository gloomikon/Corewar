/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:46:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/13 16:46:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

#include "header.h"
#include "op.h"

typedef struct s_corewar	t_corewar;
typedef struct s_champ		t_champ;

struct s_champ
{
	int	id;
};

struct s_corewar
{
	uint8_t	map[MEM_SIZE];
	t_champ	*champs[MAX_PLAYERS];
	int		champs_num;
	int		dump_mode;
	int		dump_cycles;
};

#endif