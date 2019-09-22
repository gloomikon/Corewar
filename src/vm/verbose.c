/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:50:04 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/22 18:46:33 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	verbose_death(t_carriage *del, t_corewar *cw)
{
	ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
			del->id, cw->cycles - del->live_cycle, cw->cycles_to_die);
}

void	verbose_cycles(int cycles)
{
	ft_printf("Cycle to die is now %d\n", cycles);
}

void	verbose_pc(t_carriage *carriage, uint8_t *map)
{
	int	i;

	ft_printf("ADV %d (%0.4p -> %0.4p) ",
			carriage->step, carriage->pc, carriage->pc + carriage->step);
	i = -1;
	while (++i < carriage->step)
		ft_printf("%02x ", map[calculate_address(carriage->pc + i)]);
	ft_printf("\n");
}
