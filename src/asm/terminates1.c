/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminates1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:41:27 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/16 14:57:35 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	terminate_invalid_argument(t_inst *inst, int arg_num, t_entity *entity)
{
	char	*str;

	str = ft_str_tolower(g_class[entity->class]);
	ft_printf("Invalid parameter %d type %s for instruction \"%s\"\n",
			arg_num, str, inst->name);
	ft_strdel(&str);
	system("leaks -q asm");
	exit(1);
}

void	terminate_label(t_label *label)
{
	ft_printf("No such label %s while attempting to dereference token "
		"[TOKEN][%03d:%03d] DIRECT_LABEL \"%:%s\"\n",
		label->name, label->mentions->row, label->mentions->col, label->name);
	system("leaks -q asm");
	exit(1);
}

void	terminate_invalid_parameter_count(t_inst *inst)
{
	ft_printf("Invalid parameter count for instruction %s\n", inst->name);
	system("leaks -q asm");
	exit(1);
}
