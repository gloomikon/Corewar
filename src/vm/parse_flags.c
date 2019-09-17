/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:58:08 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/17 16:09:10 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parse_args(int argc, char **argv, t_corewar *cw)
{
	t_champ *lst;

	lst = NULL;
	(argv++) && (argc--);
	while (argc >= 1)
		if (ft_strequ(*argv, "-dump") || ft_strequ(*argv, "-d"))
			init_dump_flag(&argc, &argv, cw);
		else if (check_file_extension(*argv, "cor") || ft_strequ(*argv, "-n"))
			proc_champ(&argc, &argv, &lst, cw);
	list_to_array(lst, cw);
}

void	init_dump_flag(int *argc, char ***argv, t_corewar *cw)
{
	if (cw->dump_mode == 0 && (*argc > 1) && ft_isnumber(*(*argv + 1), 10))
	{
		cw->dump_mode = (ft_strequ(**argv, "-dump")) ? 32 : 64;
		if ((cw->dump_cycles = (int)ft_atoi(*(*argv + 1))) < 0)
			cw->dump_cycles = -1;
		(*argv) += 2;
		(*argc) -= 2;
	}
	else
		print_usage();
}

void	proc_champ(int *argc, char ***argv, t_champ **lst, t_corewar *cw)
{
	int	id;

	if (cw->champs_num == MAX_PLAYERS)
		terminate(CHAMPS_NUM);
	if (ft_strequ(**argv, "-n") && (*argc > 2))
	{
		if (ft_isnumber(*(*argv + 1), 10) == false
			|| (id = (int)ft_atoi(*(*argv + 1))) > MAX_PLAYERS || id < 1
			|| find_champ(*lst, id)
			|| !check_file_extension(*(*argv + 2), "cor"))
			print_usage();
		add_champ(lst, new_champ(*(*argv + 2), id));
		++(cw->champs_num)	;
		(*argv) += 3;
		(*argc) -= 3;
	}
	else if (check_file_extension(**argv, "cor"))
	{
		add_champ(lst, new_champ(**argv, 0));
		++(cw->champs_num);
		++(*argv);
		--(*argc);
	}
	else
		print_usage();
}
