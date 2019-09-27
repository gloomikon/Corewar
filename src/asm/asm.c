/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:01:56 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/27 19:40:33 by ozhadaie         ###   ########.fr       */
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
			return (ft_printf("ERROR :Invalid filename\n"));
	}
	if (file == false)
		return (ft_printf("Usage: ./asm champ.s\n"));
	return (0);
}
