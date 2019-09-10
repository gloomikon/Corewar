/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:01:56 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/10 15:49:30 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	terminate(char *message)
{
	ft_printf("ERROR: %s\n", message);
	system("leaks asm");
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
		{
			system("leaks asm");
			return (ft_printf("ERROR :Invalid filename\n"));
		}
	}
	if (file == false)
	{
		system("leaks asm");
		return (ft_printf("Usage: ./asm champ.s\n"));
	}
	system("leaks asm");
	return (0);
}
