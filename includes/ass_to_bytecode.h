/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_to_bytecode.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:59:40 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/28 22:22:51 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_ASS_TO_BYTECODE_H
# define CW_ASS_TO_BYTECODE_H

# include "asm.h"
# include "op.h"

typedef enum
{
	COMMAND,
	STRING,
	LABEL,
	OPERATOR,
	REGISTER,
	DIRECT,
	DIRECT_LABEL,
	INDIRECT,
	INDIRECT_LABEL,
	SEPARATOR,
	NEW_LINE,
	END
}	t_class;

static char				*g_class[] = {
		"COMMAND",
		"STRING",
		"LABEL",
		"OPERATOR",
		"REGISTER",
		"DIRECT",
		"DIRECT_LABEL",
		"INDIRECT",
		"INDIRECT_LABEL",
		"SEPARATOR",
		"NEW_LINE",
		"END"
};

typedef struct s_entity	t_entity;

struct			s_entity
{
	char		*content;
	t_class		class;
	size_t		col;
	size_t		row;
	t_entity	*next;
};

typedef struct	s_pars
{
	int			fd;
	size_t		row;
	size_t		col;
	t_entity	*entities;
}				t_pars;

#endif
