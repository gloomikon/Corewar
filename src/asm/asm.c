/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:01:56 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/15 17:56:15 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "asm.h"

int		main(int argc, char **argv)
{
	bool	file;

	file = false;
	if (argc == 2)
	{
		if (check_file_extension(argv[1], "s") && asm_to_bytecode(argv[1]))
			file = true;
		if (file == false)
		{
			system("leaks -q asm");
			return (ft_printf("ERROR :Invalid filename\n"));
		}
	}
	if (file == false)
	{
		system("leaks -q asm");
		return (ft_printf("Usage: ./asm champ.s\n"));
	}
	system("leaks -q asm");
	return (0);
}
