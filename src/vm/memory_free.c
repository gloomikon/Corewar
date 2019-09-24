/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:03:23 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/24 18:03:23 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_champ(t_champ **champ)
{
	free((*champ)->name);
	free((*champ)->comment);
	free((*champ)->code);
	free((*champ));
}

void	free_carriage(t_carriage **carriage)
{
	free((*carriage)->reg);
	free(*carriage);
}

void	free_memory(t_corewar **cw)
{
	int			i;
	t_carriage	*next;

	i = -1;
	while (++i < (*cw)->champs_num)
		free_champ(&((*cw)->champs[i]));
	free((*cw)->champs);
	free((*cw)->map);
	while ((*cw)->carriages)
	{
		next = (*cw)->carriages->next;
		free_carriage(&((*cw)->carriages));
		(*cw)->carriages = next;
	}
	free(*cw);
}
