/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:46:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/03 13:35:06 by mzhurba          ###   ########.fr       */
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

void	terminate_syntax(t_pars *pars, t_entity *entity)
{
	pars->end->col = pars->col;
	pars->end->row = pars->row;
	ft_printf("Syntax error at token [TOKEN][%03d:%03d] %s \"%s\"\n",
		entity->row, entity->col, g_class[entity->class], entity->content);
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
	ft_printf("unknown instruction\n");
	exit(1);
}

void	terminate_invalid_argument(t_inst *inst, int arg_num, t_entity *entity)
{
	ft_printf("Invalid type of parameter #%d for instruction \"%s\" at "
		"[%03d:%03d]\n", arg_num, inst->name, entity->row, entity->col);
	exit(1);
}