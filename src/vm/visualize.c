/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:59:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/25 17:28:32 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visualize(t_corewar *cw)
{
	prepare(cw);
	system("afplay mp3/music.mp3 &> /dev/null &");
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
	system("pkill afplay");
	exit_visual(cw);
}
