/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:11:58 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/02 14:11:59 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_and_print(const char *restrict format, t_pf_env *e)
{
	++e->i;
	get_tag(format, e);
	get_flag(format, e);
	get_spec(format, e);
}
