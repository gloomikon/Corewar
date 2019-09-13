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

int		print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump | -d nbr_cycles] [[-n number] [-v]"
			  "champion1.cor] ...");
	return (1);
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
	}
	else
		print_usage();
}

void	parse_args(int argc, char **argv, t_corewar *cw)
{
	(argv++) && (argc--);
	while (argc >= 1)
		if (ft_strequ(*argv, "-dump") || ft_strequ(*argv, "-d"))
			init_dump_flag(&argc, &argv, cw);
}

int		main(int argc, char **argv)
{
	t_corewar	*cw;

	if (argc < 2)
		return (print_usage());
	parse_args(argc, argv, (cw = new_corewar()));
}