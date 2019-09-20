/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:36:00 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/14 18:36:00 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	check_file_extension(char *file, char *ext)
{
	const char *last_point = ft_strrchr(file, '.');

	if (!last_point || last_point == file)
		return (false);
	return (ft_strequ(last_point + 1, ext));
}

void	terminate(char *message)
{
	ft_printf("ERROR: %s\n", message);
	system("leaks -q asm");
	exit(0);
}
