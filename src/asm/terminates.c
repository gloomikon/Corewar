/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:46:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/27 19:41:18 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
			"(Perhaps you forgot to end with a newline ?)\n");
	else
	{
		pars->end->col = pars->col + 1;
		pars->end->row = pars->row + (pars->row == 0);
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
	exit(1);
}

void	terminate_instruction(t_entity *entity)
{
	ft_printf("Invalid instruction at token [TOKEN][%03d:%03d] "
		"INSTRUCTION \"%s\"\n", entity->row, entity->col, entity->content);
	exit(1);
}
