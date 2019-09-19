/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_instructions.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:49:45 by mzhurba           #+#    #+#             */
/*   Updated: 2019/09/19 15:52:19 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_INSTRUCTIONS_H
# define COREWAR_INSTRUCTIONS_H

#include "header.h"
#include "corewar.h"

typedef struct s_inst	t_inst;

struct	s_inst
{
	char		*name;
	uint8_t		code;
	uint8_t		args_num;
	bool		args_types_code;
	uint8_t		args_types[3];
	bool		modify_carry;
	uint8_t		t_dir_size;
	uint32_t	cycles;
	void		(*func)(t_corewar *, t_carriage *);
};

static t_inst		g_inst[16] = {
	{
			.name = "live",
			.code = 0x01,
			.args_num = 1,
			.args_types_code = false,
			.args_types = {T_DIR, 0, 0},
			.modify_carry = false,
			.t_dir_size = 4,
			.cycles = 10,
			.func = &op_live
	},
	{
			.name = "ld",
			.code = 0x02,
			.args_num = 2,
			.args_types_code = true,
			.args_types = {T_DIR | T_IND, T_REG, 0},
			.modify_carry = true,
			.t_dir_size = 4,
			.cycles = 5,
			.func = &op_ld
	},
	{
			.name = "st",
			.code = 0x03,
			.args_num = 2,
			.args_types_code = true,
			.args_types = {T_REG, T_REG | T_IND, 0},
			.modify_carry = false,
			.t_dir_size = 4,
			.cycles = 5,
			.func = &op_st
	},
	{
			.name = "add",
			.code = 0x04,
			.args_num = 3,
			.args_types_code = true,
			.args_types = {T_REG, T_REG, T_REG},
			.modify_carry = true,
			.t_dir_size = 4,
			.cycles = 10,
			.func = &op_add
	},
	{
			.name = "sub",
			.code = 0x05,
			.args_num = 3,
			.args_types_code = true,
			.args_types = {T_REG, T_REG, T_REG},
			.modify_carry = true,
			.t_dir_size = 4,
			.cycles = 10,
			.func = &op_sub
	},
	{
			.name = "and",
			.code = 0x06,
			.args_num = 3,
			.args_types_code = true,
			.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
			.modify_carry = true,
			.t_dir_size = 4,
			.cycles = 6,
			.func = &op_and
	},
	{
			.name = "or",
			.code = 0x07,
			.args_num = 3,
			.args_types_code = true,
			.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
			.modify_carry = true,
			.t_dir_size = 4,
			.cycles = 6,
			.func = &op_or
	},
	{
			.name = "xor",
			.code = 0x08,
			.args_num = 3,
			.args_types_code = true,
			.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
			.modify_carry = true,
			.t_dir_size = 4,
			.cycles = 6,
			.func = &op_xor
	},
	{
			.name = "zjmp",
			.code = 0x09,
			.args_num = 1,
			.args_types_code = false,
			.args_types = {T_DIR, 0, 0},
			.modify_carry = false,
			.t_dir_size = 2,
			.cycles = 20,
			.func = &op_zjmp
	},
	{
			.name = "ldi",
			.code = 0x0A,
			.args_num = 3,
			.args_types_code = true,
			.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
			.modify_carry = false,
			.t_dir_size = 2,
			.cycles = 25,
			.func = &op_ldi
	},
	{
			.name = "sti",
			.code = 0x0B,
			.args_num = 3,
			.args_types_code = true,
			.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
			.modify_carry = false,
			.t_dir_size = 2,
			.cycles = 25,
			.func = &op_sti
	},
	{
			.name = "fork",
			.code = 0x0C,
			.args_num = 1,
			.args_types_code = false,
			.args_types = {T_DIR, 0, 0},
			.modify_carry = false,
			.t_dir_size = 2,
			.cycles = 800,
			.func = &op_fork
	},
	{
			.name = "lld",
			.code = 0x0D,
			.args_num = 2,
			.args_types_code = true,
			.args_types = {T_DIR | T_IND, T_REG, 0},
			.modify_carry = true,
			.t_dir_size = 4,
			.cycles = 10,
			.func = &op_lld
	},
	{
			.name = "lldi",
			.code = 0x0E,
			.args_num = 3,
			.args_types_code = true,
			.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
			.modify_carry = true,
			.t_dir_size = 2,
			.cycles = 50,
			.func = &op_lldi
	},
	{
			.name = "lfork",
			.code = 0x0F,
			.args_num = 1,
			.args_types_code = false,
			.args_types = {T_DIR, 0, 0},
			.modify_carry = false,
			.t_dir_size = 2,
			.cycles = 1000,
			.func = &op_lfork
	},
	{
			.name = "aff",
			.code = 0x10,
			.args_num = 1,
			.args_types_code = true,
			.args_types = {T_REG, 0, 0},
			.modify_carry = false,
			.t_dir_size = 4,
			.cycles = 2,
			.func = &op_aff
	}
};

#endif
