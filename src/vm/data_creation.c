/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:47:57 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/16 16:46:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_corewar	*new_corewar(void)
{
	t_corewar	*corewar;
	int			i;

	if (!(corewar = ft_memalloc(sizeof(t_corewar))))
		terminate(MEMORY_ALLOCATION);
	if (!(corewar->map = ft_memalloc(sizeof(uint8_t) * MEM_SIZE)))
		terminate(MEMORY_ALLOCATION);
	if (!(corewar->champs = malloc(sizeof(t_champ*) * MAX_PLAYERS)))
		terminate(MEMORY_ALLOCATION);
	i = -1;
	while (++i < MAX_PLAYERS)
		if (!(corewar->champs[i] = ft_memalloc(sizeof(t_champ))))
			terminate(MEMORY_ALLOCATION);
	return corewar;
}