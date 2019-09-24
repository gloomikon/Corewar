/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_menu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:36:08 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/24 20:36:08 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	visualize_menu(t_corewar *cw)
{
	wattron(cw->visual->menu, A_BOLD);
	mvwprintw(cw->visual->menu, 2, 15, "=== HELP GUIDE ===");
	mvwprintw(cw->visual->menu, 5, 9, "Start / Pause\t\tSPACE");
	mvwprintw(cw->visual->menu, 7, 9, "Increase speed\t\tARROW UP");
	mvwprintw(cw->visual->menu, 9, 9, "Decrease speed\t\tARROW DOWN");
	mvwprintw(cw->visual->menu, 11, 9, "Exit\t\t\tESCAPE");
}
