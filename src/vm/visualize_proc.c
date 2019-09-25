/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:22:21 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/25 17:43:27 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	play_sound(bool finish)
{
	static int i = 0;

	if (finish)
	{
		system("pkill afplay");
		system("afplay mp3/victory.mp3 &> /dev/null &");
	}
	else
	{
		i = (i + 1) % 5;
		if (i == 0)
			system("afplay mp3/1.mp3 &> /dev/null &");
		else if (i == 1)
			system("afplay mp3/2.mp3 &> /dev/null &");
		else if (i == 2)
			system("afplay mp3/3.mp3 &> /dev/null &");
		else if (i == 3)
			system("afplay mp3/4.mp3 &> /dev/null &");
		else if (i == 4)
			system("afplay mp3/5.mp3 &> /dev/null &");
	}
}

void	battle_vs(t_corewar *cw)
{
	int	carriages;

	if (cw->carriages_num)
	{
		execute_one_cycle(cw);
		if (cw->cycles_to_die <= 0
			|| cw->cycles_to_die == cw->cycles_after_check)
		{
			carriages = cw->carriages_num;
			update_cycles_to_die(cw);
			if (cw->carriages_num && carriages != cw->carriages_num)
				play_sound(false);
		}
		if (cw->carriages_num == 0)
		{
			play_sound(true);
			cw->visual->pause = true;
		}
	}
}

void	proc_btn(t_visual *visual, int carriages)
{
	if (visual->btn == SPACE)
		visual->pause = !visual->pause;
	if (visual->btn == KEY_UP)
	{
		if (visual->speed < 200)
			(visual->speed) += 10;
		else
			visual->speed += 100;
	}
	if (visual->btn == KEY_DOWN)
	{
		if (visual->speed <= 200)
			visual->speed -= 10;
		else
			visual->speed -= 100;
	}
	if (carriages == 0)
		visual->pause = true;
	if (visual->speed < 10)
		visual->speed = 10;
	if (visual->speed > 1000)
		visual->speed = 1000;
}

void	visualize_all(t_corewar *cw)
{
	werase(cw->visual->win);
	werase(cw->visual->info);
	visualize_win(cw);
	visualize_info(cw);
	visualize_menu(cw);
	box(cw->visual->win, 0, 0);
	box(cw->visual->info, 0, 0);
	box(cw->visual->menu, 0, 0);
	wrefresh(cw->visual->win);
	wrefresh(cw->visual->info);
	wrefresh(cw->visual->menu);
}

int		upd_map_ind(t_corewar *cw, t_carriage *carriage, int address, int size)
{
	int	ind;

	ind = 1 + ((carriage->champ->id - 1) % 4);
	while (size)
	{
		cw->visual->map[calculate_address(address + size - 1)].ind = ind;
		cw->visual->map[calculate_address(address +
				size - 1)].wait_cycle_st = 50;
		--size;
	}
	return (1);
}
