/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:01:56 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/09 19:53:05 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	terminate(char *message)
{
	ft_printf("ERROR: %s\n", message);
	exit(0);
}

bool	check_file_extension(char *file)
{
	const char *last_point = ft_strrchr(file, '.');

	if (!last_point || last_point == file)
		return (false);
	return (ft_strequ(last_point + 1, "s"));
}

int		main(int argc, char **argv)
{
	bool	file;

	file = false;
	if (argc == 2)
	{
		if (check_file_extension(argv[1]) && ass_to_bytecode(argv[1]))
			file = true;
		if (file == false)
			return (ft_printf("Invalid filename\n"));
	}
	if (file == false)
		return (ft_printf("Usage: ./asm champ.s | champ.cor\n"
				"\tchamp.s:   assembly -> bytecode\n"
				"\tchamp.cor: bytecode -> assembly\n"));
	return (0);
}
