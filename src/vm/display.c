/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:16:40 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/19 13:17:23 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
		while (++j < mode)
			ft_printf("%.2x ", map[i + j]);
		ft_printf("\n");
	}
}