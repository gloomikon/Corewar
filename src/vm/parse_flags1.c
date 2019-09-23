/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:10:28 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/23 12:14:18 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parse_args(int argc, char **argv, t_corewar *cw)
{
	t_champ *lst;

	lst = NULL;
	(argv++) && (argc--);
	while (argc > 0)
		if (ft_strequ(*argv, "-dump") || ft_strequ(*argv, "-d"))
			init_dump_flag(&argc, &argv, cw);
		else if (ft_strequ(*argv, "-debug32")
				 || ft_strequ(*argv, "-debug64"))
			init_debug_flag(&argc, &argv, cw);
		else if (ft_strequ(*argv, "-a"))
			init_aff_flag(&argc, &argv, cw);
		else if (ft_strequ(*argv, "-verbose"))
			init_verbose_flag(&argc, &argv, cw);
		else if (ft_strequ(*argv, "-visual"))
			init_visual_flag(&argc, &argv, cw);
		else if (check_file_extension(*argv, "cor") || ft_strequ(*argv, "-n"))
			proc_champ(&argc, &argv, &lst, cw);
		else
			display_usage();
	list_to_array(lst, cw);
}

void	init_visual_flag(int *argc, char ***argv, t_corewar *cw)
{
	if (cw->visual != NULL)
		display_usage();
	cw->visual = new_visual();
	++(*argv);
	--(*argc);
}