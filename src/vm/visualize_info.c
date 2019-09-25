/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:34:59 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/25 16:40:50 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	game_status(t_corewar *cw)
{
	mvwprintw(cw->visual->info, 2, 18, "=== INFO ===");
	mvwprintw(cw->visual->info, 5, 9, "Game status:\t");
	if (cw->visual->pause)
	{
		wattron(cw->visual->info, COLOR_PAIR(PINK));
		mvwprintw(cw->visual->info, 5, 32, "Paused");
		wattroff(cw->visual->info, COLOR_PAIR(PINK));
	}
	else
	{
		wattron(cw->visual->info, COLOR_PAIR(GRASS));
		mvwprintw(cw->visual->info, 5, 32, "Running");
		wattroff(cw->visual->info, COLOR_PAIR(GRASS));
	}
}

void	champs(t_corewar *cw)
{
	int	i;

	i = -1;
	while (++i < cw->champs_num)
	{
		wattron(cw->visual->info, g_colors[i % 4 + 1]);
		mvwprintw(cw->visual->info, 22 + 5 * i, 9, "Player number:");
		wattroff(cw->visual->info, g_colors[i % 4 + 1]);
		mvwprintw(cw->visual->info, 22 + 5 * i, 24, "%d", i + 1);
		wattron(cw->visual->info, g_colors[i % 4 + 1]);
		mvwprintw(cw->visual->info, 23 + 5 * i, 9, "Name:");
		wattroff(cw->visual->info, g_colors[i % 4 + 1]);
		mvwprintw(cw->visual->info, 23 + 5 * i, 24, "%-.22s",
				cw->champs[i]->name);
		wattron(cw->visual->info, g_colors[i % 4 + 1]);
		mvwprintw(cw->visual->info, 24 + 5 * i, 9, "Comment:");
		wattroff(cw->visual->info, g_colors[i % 4 + 1]);
		mvwprintw(cw->visual->info, 24 + 5 * i, 24, "%-.22s",
				cw->champs[i]->comment);
		wattron(cw->visual->info, g_colors[i % 4 + 1]);
		mvwprintw(cw->visual->info, 25 + 5 * i, 9, "Last live:");
		wattroff(cw->visual->info, g_colors[i % 4 + 1]);
		mvwprintw(cw->visual->info, 25 + 5 * i, 24, "%d", cw->champs[i]->live);
	}
}

void	winner(t_corewar *cw)
{
	wattron(cw->visual->info, COLOR_PAIR(GRASS) | A_BOLD);
	mvwprintw(cw->visual->info, 23 + 5 * cw->champs_num, 18, "=== WINNER ===");
	wattroff(cw->visual->info, COLOR_PAIR(GRASS) | A_BOLD);
	wattron(cw->visual->info, g_colors[(cw->last->id - 1) % 4 + 1]);
	mvwprintw(cw->visual->info, 25 + 5 * cw->champs_num, 9, "Player number:");
	wattroff(cw->visual->info, g_colors[(cw->last->id - 1) % 4 + 1]);
	mvwprintw(cw->visual->info, 25 + 5 * cw->champs_num, 24, "%d",
			cw->last->id);
	wattron(cw->visual->info, g_colors[(cw->last->id - 1) % 4 + 1]);
	mvwprintw(cw->visual->info, 26 + 5 * cw->champs_num, 9, "Name:");
	wattroff(cw->visual->info, g_colors[(cw->last->id - 1) % 4 + 1]);
	mvwprintw(cw->visual->info, 26 + 5 * cw->champs_num, 24, "%-.22s",
			cw->last->name);
	wattron(cw->visual->info, g_colors[(cw->last->id - 1) % 4 + 1]);
	mvwprintw(cw->visual->info, 27 + 5 * cw->champs_num, 9, "Comment:");
	wattroff(cw->visual->info, g_colors[(cw->last->id - 1) % 4 + 1]);
	mvwprintw(cw->visual->info, 27 + 5 * cw->champs_num, 24, "%-.22s",
			cw->last->comment);
	wattron(cw->visual->info, g_colors[(cw->last->id - 1) % 4 + 1]);
	mvwprintw(cw->visual->info, 28 + 5 * cw->champs_num, 9, "Last live:");
	wattroff(cw->visual->info, g_colors[(cw->last->id - 1) % 4 + 1]);
	mvwprintw(cw->visual->info, 28 + 5 * cw->champs_num, 24, "%d",
			cw->last->live);
}

void	visualize_info(t_corewar *cw)
{
	wattron(cw->visual->info, A_BOLD);
	game_status(cw);
	mvwprintw(cw->visual->info, 8, 9, "Speed:\t\t\t%d c.p.s.",
			cw->visual->speed);
	mvwprintw(cw->visual->info, 10, 9, "Cycles \t\t%d",
			cw->cycles);
	mvwprintw(cw->visual->info, 12, 9, "Carriages number:\t%d",
			cw->carriages_num);
	mvwprintw(cw->visual->info, 14, 9, "Cycles to die:\t\t%d",
			cw->cycles_to_die);
	mvwprintw(cw->visual->info, 16, 9, "Cycles delta:\t\t%d",
			CYCLE_DELTA);
	mvwprintw(cw->visual->info, 18, 9, "Cycles after check:\t%d",
			cw->cycles_after_check);
	mvwprintw(cw->visual->info, 20, 9, "Lives num:\t\t%d",
			cw->lives);
	champs(cw);
	if (cw->carriages_num == 0)
		winner(cw);
}
