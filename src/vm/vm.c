/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/24 20:37:54 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_start_data(t_corewar *cw)
{
	uint32_t	pc;
	int			id;

	pc = 0;
	id = -1;
	while (++id < cw->champs_num)
	{
		ft_memcpy(&(cw->map[pc]), cw->champs[id]->code,
				cw->champs[id]->size);
		add_carriage(&(cw->carriages), new_carriage(cw->champs[id], pc));
		++(cw->carriages_num);
		pc += MEM_SIZE / cw->champs_num;
	}
}

void	cancel_args(t_corewar *cw)
{
	cw->aff = false;
	cw->debug_cycles = -1;
	cw->dump_cycles = -1;
	cw->verbose = 0;
}

int		main(int argc, char **argv)
{
	t_corewar	*cw;

	if (argc < 2)
	{
		display_usage();
		return (1);
	}
	parse_args(argc, argv, (cw = new_corewar()));
	create_start_data(cw);
	if (cw->visual)
	{
		cancel_args(cw);
		visualize(cw);
	}
	else
	{
		display_start_message(cw->champs) && run_battle(cw);
		display_result(cw);
	}
	free_memory(&cw);
	system("leaks -q corewar");
	return (0);
}
