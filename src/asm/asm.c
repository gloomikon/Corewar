/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:01:56 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/28 03:04:25 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	terminate(char *message)
{
	ft_printf("ERROR: %s\n", message);
	exit(0);
}

bool	check_file_extension(char *file, char *ext)
{
	const char *last_point = ft_strrchr(file, '.');

	if (!last_point || last_point == file)
		return (false);
	return (ft_strequ(last_point + 1, ext));
}

int		bytecode_to_ass(char *file)
{
	return (ft_printf("File valid\n"));
}

int		main(int argc, char **argv)
{
	bool	file;

	file = false;
	if (argc == 2)
	{
		if ((check_file_extension(argv[1], "s") && ass_to_bytecode(argv[1]))
		|| (check_file_extension(argv[1], "cor") && bytecode_to_ass(argv[1])))
			file = true;
		if (file == false)
			return (ft_printf("Invalid filename\n"));
	}
	if (file == false)
		ft_printf("Usage: ./asm champ.s | champ.cor\n"
				"\tchamp.s:   assembly -> bytecode\n"
				"\tchamp.cor: bytecode -> assembly\n");
	return (0);
}
