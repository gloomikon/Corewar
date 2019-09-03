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

void	terminate_syntax(int row, int col, t_entity *entity)
{
	if (entity == NULL)
		ft_printf("Syntax error at token [TOKEN][%03d:%03d] END \"(null)\"\n",
			row, col);
	else
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
