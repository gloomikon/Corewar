/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/22 19:14:20 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "corewar_instructions.h"

void	parse_args(int argc, char **argv, t_corewar *cw)
{
	t_champ *lst;

	lst = NULL;
	(argv++) && (argc--);
	while (argc >= 1)
		if (ft_strequ(*argv, "-dump") || ft_strequ(*argv, "-d"))
			init_dump_flag(&argc, &argv, cw);
		else if (ft_strequ(*argv, "-debug32")
				|| ft_strequ(*argv, "-debug64"))
			init_debug_flag(&argc, &argv, cw);
		else if (ft_strequ(*argv, "-a"))
			init_aff_flag(&argc, &argv, cw);
		else if (ft_strequ(*argv, "-v"))
			init_verbose_flag(&argc, &argv, cw);
		else if (check_file_extension(*argv, "cor") || ft_strequ(*argv, "-n"))
			proc_champ(&argc, &argv, &lst, cw);
		else
			display_usage();
	list_to_array(lst, cw);
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
	display_start_message(cw->champs) && run_battle(cw);
	display_result(cw);
	system("leaks -q corewar");
	return (0);
}
