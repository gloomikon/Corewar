/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:16:40 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/25 19:34:40 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_usage(void)
{
	ft_printf("Usage: ./corewar [-dump | -d nbr_cycles] [-debug32 | -debug64 "
	"nbr_cycles] [-verbose nbr] [-n number] champion1.cor ... [-visual]\n\n");
	ft_printf("{yellow}-dump | -d nbr_cycles{off}\n"
	"\tat the end of nbr_cycles of executions, dump the memory on the\n"
	"\tstandard output and {red}quit{off} the game. The memory will be\n"
	"\tdumped in the hexadecimal format with 32 | 64 octets per line\n");
	ft_printf("{yellow}-debug32 | -debug64 nbr_cycles{off}\n"
	"\tat the end of nbr_cycles of executions, dump the memory on the\n"
	"\tstandard output and {red}pause{off} the game. The memory will be\n"
	"\tdumped in the hexadecimal format with 32 | 64 octets per line\n");
	ft_printf("{yellow}-n number{off}\n"
	"\tsets the number of the next player. If non-existent, the player will\n"
	"\thave the next available number in the order of the parameters. The\n"
	"\tlast player will have the first process in the order of execution\n");
	ft_printf("{yellow}-verbose nbr{off}\n"
	"\tLogging actions while executions. Add log levels to combine\n\t\t"
	"1  : Log lives\n \t\t2  : Log cycles\n\t\t4  : Log instructions\n\t\t"
	"8  : Log deaths\n \t\t16 : Log PC movements\n");
	ft_printf("{yellow}-visual{off}\n\tVisualizer with music\n");
	exit(1);
}

int		display_start_message(t_champ **champ)
{
	int	id;

	ft_printf("Introducing contestants...\n");
	id = -1;
	while (champ[++id])
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				id + 1, champ[id]->size, champ[id]->name, champ[id]->comment);
	return (1);
}

void	display_map(int mode, uint8_t *map)
{
	int	i;
	int	j;

	i = -mode;
	while ((i += mode) < MEM_SIZE && (j = -1))
	{
		ft_printf("%.4p : ", i);
		while ((i + ++j < MEM_SIZE) && j < mode)
			ft_printf("%.2x ", map[i + j]);
		ft_printf("\n");
	}
}

void	display_result(t_corewar *cw)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
			cw->last->id, cw->last->name);
}
