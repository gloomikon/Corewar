/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:01:56 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/10 16:44:02 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		main(int argc, char **argv)
{
	bool	file;

	file = false;
	if (argc == 2)
	{
		if (check_file_extension(argv[1]) && ass_to_bytecode(argv[1], "s"))
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
