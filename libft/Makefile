# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 13:46:35 by mzhurba           #+#    #+#              #
#    Updated: 2019/08/17 19:40:45 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_wstrlen.c ft_strdup.c\
		ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c\
		ft_strchr.c ft_strchri.c ft_strrchr.c ft_strstr.c ft_strnstr.c\
		ft_strcmp.c ft_strncmp.c ft_strrev.c ft_atoi.c ft_isalpha.c\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c\
		ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c\
		ft_strclr.c ft_striteri.c ft_striteri.c ft_strmap.c ft_strmapi.c\
		ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
		ft_strsplit.c ft_itoa.c ft_ultoa.c ft_ftoa.c ft_ultoa_base.c\
		ft_ltoa_base.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
		ft_lstnew.c ft_ltoa.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c\
		ft_lstmap.c ft_islower.c ft_strlower.c ft_isupper.c ft_lstadd.c\
		ft_striteri.c ft_striter.c ft_putarr.c get_next_line.c ft_splitdel.c\
		ft_max.c ft_min.c ft_isspace.c ft_isdigit_base.c ft_has_prefix.c\
		ft_atoi_base.c ft_isnumber.c ft_abs.c ft_strsplit_len.c\
		ft_free_split_array.c ft_atoi32.c

SRC1 =	check_base_prec.c check_digit_prec.c check_digit_sign.c check_form.c\
		check_settings.c delete_zero.c ft_printf.c ft_str_prec.c\
		ftoa_prec_e.c ftoa_prec_eg.c ftoa_prec_f.c ftoa_prec_fg.c\
		get_exponent.c get_flag.c get_mod.c get_prec_num_e.c\
		get_prec_num_f.c get_precision.c get_spec.c get_tag.c\
		get_width.c init_char_arg.c init_flag.c init_int_arg.c\
		init_long_double.c init_prec_arg.c init_str_arg.c init_wchar_arg.c\
		init_wstr_arg.c nan_inf.c print_base_pre.c print_base_width.c\
		print_base.c print_char_width.c print_char.c parse_and_print.c\
		print_digit_sign.c print_digit_width.c print_digit.c\
		print_invalid_spec.c print_invalid_width.c print_null_char.c\
		print_prec_e.c print_prec_f.c print_prec_g.c print_prec_width.c\
		print_ptraddr_width.c print_ptraddr.c print_str_width.c print_str.c\
		print_wchar_minus.c print_wchar.c print_wstr_minus.c print_wstr.c\
		ptraddr_prec.c put_wc.c put_wchar.c put_wstr_c.c put_wstr.c\
		spec_base.c spec_char.c spec_int.c spec_non_printable.c\
		spec_percent.c spec_precision.c spec_ptraddr.c spec_return.c\
		spec_unsint.c spec_wchar.c

OBJ =	$(SRC:.c=.o)
OBJ +=	$(SRC1:.c=.o)

SRCDIR	= src
SRC1DIR	= ft_printf/src
OBJDIR	= obj

SRCS =	$(addprefix $(SRCDIR)/, $(SRC))
SRCS +=	$(addprefix $(SRC1DIR)/, $(SRC1))
OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
HEADER = -I includes -I ft_printf/includes

CC = clang
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

$(OBJDIR)/%.o: $(SRC1DIR)/%.c
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
