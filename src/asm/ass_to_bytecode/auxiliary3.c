/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 14:28:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/03 14:28:33 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ass_to_bytecode.h"

int		upd_buffer(t_pars *pars)
{
	pars->code_size += CHAMP_MAX_SIZE;
	pars->code = realloc(pars->code, pars->code_size + MAX_STATEMENT_SIZE);
	return (1);
}