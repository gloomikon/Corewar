/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:38:39 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/17 19:19:06 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump | -d nbr_cycles] [[-n number] "
			"champion1.cor] ... [-v]\n");
	exit(1);
}

t_champ	*find_champ(t_champ *lst, int id)
{
	while (lst)
	{
		if (lst->id == id)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	list_to_array(t_champ *lst, t_corewar *cw)
{
	int		id;
	t_champ	*old;

	old = lst;
	while (lst)
	{
		if (lst->id == 0 && (id = 1))
		{
			while (find_champ(old, id))
				++id;
			lst->id = id;
		}
		if (lst->id > cw->champs_num)
			print_usage();
		cw->champs[lst->id - 1] = lst;
		lst = lst->next;
	}
	cw->last_alive = cw->champs[cw->champs_num - 1];
}
