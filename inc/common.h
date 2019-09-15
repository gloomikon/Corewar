/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:31:54 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/09 19:32:55 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "header.h"
# include "termiante_errors.h"

bool	check_file_extension(char *file, char *ext);
void	terminate(char *message);

#endif
