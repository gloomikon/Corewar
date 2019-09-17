/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/17 19:51:05 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_start_map(t_corewar *cw)
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
		pc += MEM_SIZE / cw->champs_num;
	}
}


int		main(int argc, char **argv)
{
	t_corewar	*cw;

	if (argc < 2)
		print_usage();
	parse_args(argc, argv, (cw = new_corewar()));

	for (int i = 0; i < cw->champs_num; i++)
		printf("%d: %s\n", cw->champs[i]->id, cw->champs[i]->name);

	create_start_map(cw);
	while (cw->carriages)
	{
		printf("%d: %d %s\n",
				cw->carriages->id,
				cw->carriages->pc,
				cw->carriages->champ->name);
		cw->carriages = cw->carriages->next;
	}
}
