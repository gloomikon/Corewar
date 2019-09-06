/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:46:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/06 19:07:07 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

void	terminate_lexical(int row, int col)
{
	ft_printf("Lexical error at [%d:%d]\n", row, col);
	exit(1);
}

void	terminate_entity(t_entity *entity)
{
	ft_printf("Unexpected token \"%s\" %s at [%d:%d]\n",
			entity->content, g_class[entity->class], entity->row, entity->col);
	exit(1);
}

void	terminate_syntax(t_pars *pars, t_entity *entity, bool suggestion)
{
	if (suggestion)
		ft_printf("Syntax error - unexpected end of input "
			"(Perhaps you forgot to end with a newline ?)");
	else
	{
		pars->end->col = pars->col + 1;
		pars->end->row = pars->row;
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"%s\"\n",
			entity->row, entity->col, g_class[entity->class], entity->content);
	}
	exit(1);
}

void	terminate_big_bio(int type)
{
	ft_printf("Champion %s too long (Max length %d)\n",
			type == NAME ? "name" : "comment",
			type == NAME ? PROG_NAME_LENGTH : COMMENT_LENGTH);
}

void	terminate_instruction(t_entity *entity)
{
	ft_printf("Invalid instruction at token [TOKEN][%03d:%03d] "
		"INSTRUCTION \"%s\"", entity->row, entity->col, entity->content);
	exit(1);
}

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

void	terminate_invalid_argument(t_inst *inst, int arg_num, t_entity *entity)
{
	char	*str;

	str = ft_str_tolower(g_class[entity->class]);
	ft_printf("Invalid parameter %d type %s for instruction \"%s\"",
			arg_num, str, inst->name);
	ft_strdel(&str);
	exit(1);
}

void	terminate_label(t_label *label)
{
	ft_printf("No such label %s while attempting to dereference token "
		"[TOKEN][%03d:%03d] DIRECT_LABEL \"%:%s\"",
		label->name, label->mentions->row, label->mentions->col, label->name);
	exit(1);
}