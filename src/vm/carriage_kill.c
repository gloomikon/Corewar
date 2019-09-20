/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_kill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:04:02 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/20 11:14:31 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	update_cycles_to_die(t_corewar *cw)
{
	++(cw->checks);
	kill_carriages(cw);
	if (cw->lives >= NBR_LIVE
		|| cw->checks == MAX_CHECKS)
	{
		cw->cycles_to_die -= CYCLE_DELTA;
		cw->checks = 0;
	}
//	reset_lives(cw); for visualisator?
	cw->cycles_after_check = 0;
}

void	kill_carriages(t_corewar *cw)
{
	t_carriage	*del;
	t_carriage	*prev;
	t_carriage	*curr;

	prev = NULL;
	curr = cw->carriages;
	while (curr)
	{
		if (dead((del = curr), cw))
		{
			curr = curr->next;
			(cw->carriages == del) && (cw->carriages = curr);
			(prev != NULL) && (prev->next = curr);
			free(del);
		}
		else
			(prev = curr)
			&& (curr = curr->next);
	}
}

bool	dead(t_carriage *carriage, t_corewar *cw)
{
	return (cw->cycles - carriage->live_cycle >= cw->cycles_to_die
	|| cw->cycles_to_die <= 0);
}
