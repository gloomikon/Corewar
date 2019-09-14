/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:42:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/13 16:42:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


void	print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump | -d nbr_cycles] [[-n number] [-v] "
		   "champion1.cor] ...");
	exit(1);

}

t_corewar	*new_corewar(void)
{
	t_corewar	*corewar;

	corewar = ft_memalloc(sizeof(t_corewar));
	return corewar;
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

void	add_champ(int *argc, char **argv, t_champ **lst, t_corewar *cw)
{

}

void	parse_args(int argc, char **argv, t_corewar *cw)
{
	t_champ *lst;

	lst = NULL;
	(argv++) && (argc--);
	while (argc >= 1)
		if (ft_strequ(*argv, "-dump") || ft_strequ(*argv, "-d"))
			init_dump_flag(&argc, &argv, cw);
		else if (check_file_extension(*argv, "cor") || ft_strequ(*argv, "-n"))
			add_champ(&argc, &argv, &lst, cw);
}

int		main(int argc, char **argv)
{
	t_corewar	*cw;

	if (argc < 2)
		print_usage();
	parse_args(argc, argv, (cw = new_corewar()));
	printf("dump-mode : %d, dump-cycles : %d\n", cw->dump_mode, cw->dump_cycles);
}