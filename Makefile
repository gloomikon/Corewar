# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 19:17:27 by ozhadaie          #+#    #+#              #
#    Updated: 2019/09/24 20:59:26 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LFTD:=	libft
LFTA:=	$(LFTD)/libft.a
LFTI:=	$(LFTD)/inc

INCD:=	inc
SRCD:=	src
OBJD:=	obj

CMPL:=	gcc # $(addprefix -W, all extra error) 

#======================================VM======================================#

CRWB=	corewar
VMD=	vm
CRWH=	$(addprefix $(INCD)/,\
			common.h\
			corewar.h\
			corewar_instructions.h\
			op.h\
			terminate_errors.h)
CRWSD=	$(SRCD)/$(VMD)
CRWOD=	$(OBJD)/$(VMD)
CRWS=	auxiliary.c\
		battle.c\
		carriage_kill.c\
		common.c\
		counting.c\
		data_add_to_lst.c\
		data_creation.c\
		display.c\
		memory_free.c\
		inst_13_16.c\
		inst_1_4.c\
		inst_5_8.c\
		inst_9_12.c\
		parse_flags.c\
		parse_flags1.c\
		reading_bytecode.c\
		validation.c\
		verbose.c\
		visualize.c\
		visualize_auxiliary.c\
		visualize_prepare.c\
		visualize_proc.c\
		visualize_win.c\
		visualize_menu.c\
		visualize_info.c\
		vm.c
CRWO=	$(addprefix $(CRWOD)/, $(patsubst %.c, %.o, $(CRWS)))

#======================================ASM=====================================#

ASMB=	asm
ASMH=	$(addprefix $(INCD)/,\
			asm.h\
			asm_instructions.h\
			common.h\
			op.h\
			terminate_errors.h)
ASMSD=	$(SRCD)/$(ASMB)
ASMOD=	$(OBJD)/$(ASMB)
ASMS=	asm.c\
		common.c\
		data_creation.c\
		data_processing_arguments.c\
		terminates.c\
		asm_to_bytecode.c\
		auxiliary.c\
		auxiliary2.c\
		auxiliary3.c\
		data_add_to_lst.c\
		data_free.c\
		data_processing.c\
		data_processing_classes.c\
		pasring.c\
		terminates1.c\
		writing.c
ASMO=	$(addprefix $(ASMOD)/, $(patsubst %.c, %.o, $(ASMS)))

#==================================DEPENDENCIES================================#
all: $(LFTA) $(ASMB) $(CRWB)

$(ASMB): $(ASMO) $(LFTA)
	@$(CMPL) -o $@ $^ $(addprefix -I, $(INCD) $(LFTI))
	@printf "\r\33[2K$@\t   \033[32;1mcreated\033[0m\n"

$(CRWB): $(CRWO) $(LFTA)
	@$(CMPL) -o $@ $^ $(addprefix -I, $(INCD) $(LFTI)) -lncurses
	@printf "\r\33[2K$@\t   \033[32;1mcreated\033[0m\n"

$(ASMOD)/%.o: $(ASMSD)/%.c $(ASMH)
	@$(CMPL) -o $@ -c $< $(addprefix -I, $(INCD) $(LFTI))
	@printf "\r\33[2K$(ASMB)\t   \033[33;1mcompile \033[0m$@"

$(CRWOD)/%.o: $(CRWSD)/%.c $(CRWH)
	@$(CMPL) -o $@ -c $< $(addprefix -I, $(INCD) $(LFTI))
	@printf "\r\33[2K$(CRWB)\t   \033[33;1mcompile \033[0m$@"

$(ASMO): | $(ASMOD)

$(CRWO): | $(CRWOD)


#==================================PRERESQUISITES==============================#

#=====================================RULES====================================#

$(CRWOD):
	@mkdir -p $@

$(ASMOD):
	@mkdir -p $@

$(LFTA):
	@make -sC $(LFTD)

clean:
	@make -sC $(LFTD) $@
	@rm -rf $(OBJD)
	@printf "  $(OBJD)\t   \033[31;1mdeleted\033[0m\n"

fclean: clean
	@make -sC $(LFTD) $@
	@rm -f $(ASMB) $(CRWB)
	@printf "  $(ASMB)\t   \033[31;1mdeleted\033[0m\n"
	@printf "  $(CRWB) \033[31;1mdeleted\033[0m\n"

test: $(CRWO)
	@echo $^

re: fclean all

.PHONY: all clean fclean re
