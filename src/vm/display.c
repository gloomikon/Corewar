/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:16:40 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/24 15:14:28 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_usage(void)
{
	ft_printf("Usage: ./corewar [-dump | -d nbr_cycles] [[-n number] "
		"[-debug32 | -debug64 nbr_cycles] champion1.cor] ... [-v]\n\n");
	ft_printf("{yellow}-dump | -d nbr_cycles{off}\n"
		"at the end of nbr_cycles of executions, dump the memory on the\n"
		"standard output and {red}quit{off} the game. The memory will be\n"
		"dumped in the hexadecimal format with 32 | 64 octets per line\n");
	ft_printf("{yellow}-debug32 | -debug64 nbr_cycles{off}\n"
		"at the end of nbr_cycles of executions, dump the memory on the\n"
		"standard output and {red}pause{off} the game. The memory will be\n"
		"dumped in the hexadecimal format with 32 | 64 octets per line\n");
	ft_printf("{yellow}-n number{off}\n"
		"sets the number of the next player. If non-existent, the player will\n"
		"have the next available number in the order of the parameters. The\n"
		"last player will have the first process in the order of execution\n");
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
