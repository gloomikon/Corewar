/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:59:33 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/23 20:50:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	delete_whitespaces(t_corewar *cw)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cw->champs_num && (j = -1))
		while(cw->champs[i]->name[++j])
			if (ft_isspace(cw->champs[i]->name[j]))
				cw->champs[i]->name[j] = ' ';
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

void	visualize_carriage(t_carriage *carriage, t_corewar *cw)
{
	int	ind;

	ind = cw->visual->map[carriage->pc].ind;
	if (ind <= 4 && ind >= 0)
		cw->visual->map[carriage->pc].ind = ind + 5;
}

void	set_carriages(t_corewar *cw)
{
	t_carriage	*carriage;

	carriage = cw->carriages;
	while (carriage)
	{
		visualize_carriage(carriage, cw);
		carriage = carriage->next;
	}
}

void	prepare(t_corewar *cw)
{
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
	cw->visual->menu = newwin(HEIGHT, WIDTH / 4, 0, 0);
	cw->visual->win = newwin(HEIGHT, WIDTH, 0, WIDTH / 4 + 1);
	cw->visual->info = newwin(HEIGHT, WIDTH / 4, 0, WIDTH / 4 + 1 + WIDTH + 1);
	set_map(cw);
	set_carriages(cw);
}

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

void	visualize_win(t_corewar *cw)
{
	int			i;
	int			j;
	static int	cycles = 0;
	int			attr;

	i = -1;
	while (++i < 64 && (j = -1))
	{
		wmove(cw->visual->win, i + 2, 3);
		while (++j < 64)
		{
			attr = get_attr(cw, &(cw->visual->map[i * 64 + j]), cycles);
			wattron(cw->visual->win, attr);
			wprintw(cw->visual->win, "%.2x", cw->map[i * 64 + j]);
			wattroff(cw->visual->win, attr);
			wprintw(cw->visual->win, " ");
		}
		wprintw(cw->visual->win, "\n");
	}
	cycles = cw->cycles;
}

void	visualize_all(t_corewar *cw)
{
	werase(cw->visual->win);
	werase(cw->visual->info);
	visualize_win(cw);

	box(cw->visual->win, 0, 0);
	wrefresh(cw->visual->win);
}

void	draw_help(t_corewar *cw)
{
//	werase(cw->visual->menu);
//	wattr_on(cw->visual->menu, A_BOLD);
	mvwprintw(cw->visual->menu, 1, 1, "Start / Pause - SPACE");
	box(cw->visual->menu, 0, 0);
	wrefresh(cw->visual->menu);
}

void	visualize(t_corewar *cw)
{
	delete_whitespaces(cw);
	prepare(cw);
	draw_help(cw);
	while ((cw->visual->btn = getch()) != ESCAPE)
	{
		visualize_all(cw);
	}
}
