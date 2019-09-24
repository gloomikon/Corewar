/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:59:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/24 20:36:30 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visualize(t_corewar *cw)
{
	prepare(cw);
	while ((cw->visual->btn = getch()) != ESCAPE)
	{
		proc_btn(cw->visual, cw->carriages_num);
		if (cw->visual->pause == false
		&& (cw->visual->time + CLOCKS_PER_SEC / cw->visual->speed <= clock()))
		{
			cw->visual->time = clock();
			battle_vs(cw);
		}
		visualize_all(cw);
	}
	exit_visual(cw);
}
