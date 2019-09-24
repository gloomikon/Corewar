/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:34:16 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/24 20:34:16 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
