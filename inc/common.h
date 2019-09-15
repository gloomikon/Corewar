/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 17:06:38 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/15 17:06:38 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "header.h"
# include "terminate_errors.h"

bool	check_file_extension(char *file, char *ext);
void	terminate(char *message);

#endif
