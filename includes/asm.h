/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:31:54 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/28 01:59:31 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_ASM_H
# define CW_ASM_H

# include "header.h"

# define REGISTER_SYMB	'r'

int		ass_to_bytecode(char *file);
void	terminate(char *message);

#endif
