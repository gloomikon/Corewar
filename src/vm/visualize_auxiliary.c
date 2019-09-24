/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_auxiliary.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:24:23 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/24 20:44:59 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_attr(t_corewar *cw, t_attr *attr, int cycles)
{
	(cw->cycles != cycles && cw->cycles_to_die > 0
		&& attr->wait_cycle_live > 0)
	&& --(attr->wait_cycle_live);
	(cw->cycles != cycles && cw->cycles_to_die > 0
		&& attr->wait_cycle_st > 0)
	&& --(attr->wait_cycle_st);
	if (attr->wait_cycle_live)
		return (g_colors[(attr->champ->id - 1) % 4 + 10] | A_BOLD);
	if (attr->wait_cycle_st)
		return (g_colors[attr->ind] | A_BOLD);
	return (g_colors[attr->ind]);
}

void	highlight_carriage(t_carriage *carriage, t_corewar *cw)
{
	int	ind;

	ind = cw->visual->map[carriage->pc].ind;
	if (ind <= 4 && ind >= 0)
		cw->visual->map[carriage->pc].ind = ind + 5;
}

void	dull_carriage(t_carriage *carriage, t_corewar *cw)
{
	int	ind;

	ind = cw->visual->map[carriage->pc].ind;
	if (ind <= 4 && ind >= 0)
		cw->visual->map[carriage->pc].ind = ind - 5;
}

void	exit_visual(t_corewar *cw)
{
	delwin(cw->visual->win);
	delwin(cw->visual->info);
	delwin(cw->visual->menu);
	free(cw->visual->map);
	free(cw->visual);
	endwin();
}
