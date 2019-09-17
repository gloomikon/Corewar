# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 19:17:27 by ozhadaie          #+#    #+#              #
#    Updated: 2019/09/16 17:53:57 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LFTD:=	libft
LFTA:=	$(LFTD)/libft.a
LFTI:=	$(LFTD)/inc

INCD:=	inc
SRCD:=	src
OBJD:=	obj

CMPL:=	gcc #$(addprefix -W, all extra error)

#====================================COMMON====================================#

CMNH:=	$(addprefix $(INCD)/, common.h)
CMNS:=	common.c
CMNO:=	$(addprefix $(OBJD)/, $(patsubst %.c, %.o, $(CMNS)))


#======================================VM======================================#

CRWB:=	corewar
CRWH:=	$(addprefix $(INCD)/, op.h corewar.h)
CRWSD:=	$(SRCD)/vm
CRWOD:=	$(OBJD)/vm
CRWS:=	data_creation.c vm.c auxiliary.c data_add_to_lst.c parse_flags.c\
        reading_bytecode.c
CRWO:=	$(addprefix $(CRWOD)/, $(patsubst %.c, %.o, $(CRWS))) $(CMNO)

#======================================ASM=====================================#

ASMB:=	asm
ASMH:=	$(addprefix $(INCD)/, asm.h asm_instructions.h\
							common.h op.h terminate_errors.h)
ASMSD:=	$(SRCD)/$(ASMB)
ASMOD:=	$(OBJD)/$(ASMB)
ASMS:=	asm.c asm_to_bytecode.c auxiliary.c auxiliary2.c auxiliary3.c\
		data_creation.c data_add_to_lst.c data_processing.c\
		data_processing_arguments.c data_processing_classes.c pasring.c\
		terminates.c terminates1.c writing.c data_free.c
ASMO:=	$(addprefix $(ASMOD)/, $(patsubst %.c, %.o, $(ASMS))) $(CMNO)

#==================================DEPENDENCIES================================#

all: $(LFTA) $(ASMB) $(CRWB)

$(ASMB): $(ASMO) $(LFTA)
	@$(CMPL) -o $@ $^ $(addprefix -I, $(INCD) $(LFTI))
	@printf "\r\33[2K$@\t   \033[32;1mcreated\033[0m\n"

prettya:
	@printf "$(ASMB)\t\033[33;1mcreating\033[0m "

$(CRWB): $(CRWO) $(LFTA)
	@$(CMPL) -o $@ $^ $(addprefix -I, $(INCD) $(LFTI))
	@printf "\r\33[2K$@\t   \033[32;1mcreated\033[0m\n"

prettyc:
	@printf "$(CRWB)\t\033[33;1mcreating\033[0m "

$(ASMOD)/%.o: $(ASMSD)/%.c $(ASMH) | $(ASMOD)# prettya
	@$(CMPL) -o $@ -c $< $(addprefix -I, $(INCD) $(LFTI))
	@printf "."

$(CRWOD)/%.o: $(CRWSD)/%.c $(CRWH) | $(CRWOD)# prettyc
	@$(CMPL) -o $@ -c $< $(addprefix -I, $(INCD) $(LFTI))
	@printf "."

$(OBJD)/%.o: $(SRCD)/%.c $(CMNH) | $(OBJD)
	@$(CMPL) -o $@ -c $< $(addprefix -I, $(INCD) $(LFTI))

#=====================================RULES====================================#

$(OBJD):
	@mkdir -p $@

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

re: fclean all

.PHONY: all clean fclean re prettya prettyc
