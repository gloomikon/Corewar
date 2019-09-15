# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/09 19:17:27 by ozhadaie          #+#    #+#              #
#    Updated: 2019/09/15 17:10:53 by ozhadaie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LFTD:=	libft
LFTA:=	$(LFTD)/libft.a
LFTI:=	$(LFTD)/inc

INCD:=	inc
SRCD:=	src
OBJD:=	obj

CRWB:=	corewar
CRWH:=	$(addprefix $(INCD)/, op.h)
CRWD:=	$(SRCD)/corewar

ASMB:=	asm
ASMH:=	$(addprefix $(INCD)/, asm.h asm_instructions.h\
							common.h op.h terminate_errors.h)
ASMSD:=	$(SRCD)/$(ASMB)
ASMOD:=	$(OBJD)/$(ASMB)
ASMS:=	asm.c asm_to_bytecode.c auxiliary.c auxiliary2.c auxiliary3.c\
		data_creation.c data_add_to_lst.c data_processing.c\
		data_processing_arguments.c data_processing_classes.c pasring.c\
		terminates.c terminates1.c writing.c data_free.c
ASMO:=	$(addprefix $(ASMOD)/, $(patsubst %.c, %.o, $(ASMS))) $(SRCD)/common.c

CMPL:=	gcc #$(addprefix -W, all extra error)

all: $(ASMB)

$(ASMB): $(ASMO) $(LFTA)
	@$(CMPL) -o $@ $^ $(addprefix -I, $(INCD) $(LFTI))
	@printf "\rCreating $@\n"

$(LFTA):
	@make -sC $(LFTD)

$(ASMOD)/%.o: $(ASMSD)/%.c $(ASMH) | $(ASMOD)
	@$(CMPL) -o $@ -c $< $(addprefix -I, $(INCD) $(LFTI))
	@printf "."
	@sleep 0.1

$(ASMOD):
	@mkdir -p $@

clean:
	@make -sC $(LFTD) $@
	@rm -rf $(OBJD)
	@printf "\r$@ complete\n"

fclean: clean
	@make -sC $(LFTD) $@
	@rm -f $(ASMB)
	@printf "\r$@ complete\n"

re: fclean all

.PHONY: all clean fclean re
