/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_prepare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:19:59 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/24 20:37:43 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	delete_whitespaces(t_corewar *cw)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cw->champs_num && (j = -1))
		while (cw->champs[i]->name[++j])
			if (ft_isspace(cw->champs[i]->name[j]))
				cw->champs[i]->name[j] = ' ';
}

void	prepare(t_corewar *cw)
{
	delete_whitespaces(cw);
	initscr();
	keypad(stdscr, true);
	nodelay(stdscr, true);
	curs_set(0);
	refresh();
	cbreak();
	noecho();
	use_default_colors();
	start_color();
	set_colors();
	cw->visual->menu = newwin(15, WIDTH / 4, 1, WIDTH + 2);
	cw->visual->win = newwin(HEIGHT, WIDTH, 1, 1);
	cw->visual->info = newwin(HEIGHT - 15, WIDTH / 4, 16, WIDTH + 2);
	set_map(cw);
	set_carriages(cw);
}

void	set_colors(void)
{
	init_pair(DEFAULT, GREY_COLOR, COLOR_BLACK);
	init_pair(PINK, PINK_COLOR, COLOR_BLACK);
	init_pair(PEACH, PEACH_COLOR, COLOR_BLACK);
	init_pair(GRASS, GRASS_COLOR, COLOR_BLACK);
	init_pair(SKY, SKY_COLOR, COLOR_BLACK);
	init_pair(C_DEFAULT, COLOR_BLACK, GREY_COLOR);
	init_pair(C_PINK, COLOR_BLACK, PINK_COLOR);
	init_pair(C_PEACH, COLOR_BLACK, PEACH_COLOR);
	init_pair(C_GRASS, COLOR_BLACK, GRASS_COLOR);
	init_pair(C_SKY, COLOR_BLACK, SKY_COLOR);
	init_pair(L_PINK, COLOR_WHITE, PINK_COLOR);
	init_pair(L_PEACH, COLOR_WHITE, PEACH_COLOR);
	init_pair(L_GRASS, COLOR_WHITE, GRASS_COLOR);
	init_pair(L_SKY, COLOR_WHITE, SKY_COLOR);
}

void	set_carriages(t_corewar *cw)
{
	t_carriage	*carriage;

	carriage = cw->carriages;
	while (carriage)
	{
		highlight_carriage(carriage, cw);
		carriage = carriage->next;
	}
}

void	set_map(t_corewar *cw)
{
	int	id;
	int	pc;
	int	pos;
	int	ind;

	pc = 0;
	id = -1;
	while (++id < cw->champs_num)
	{
		pos = pc;
		ind = (id % 4) + 1;
		while (pos < cw->champs[id]->size + pc)
			cw->visual->map[pos++].ind = ind;
		pc += MEM_SIZE / cw->champs_num;
	}
}
