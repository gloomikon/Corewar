# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/02 13:46:35 by mzhurba           #+#    #+#              #
#    Updated: 2019/09/20 17:43:18 by mzhurba          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FILE =	ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove\
		ft_memchr ft_memcmp ft_strlen ft_wstrlen ft_strdup\
		ft_strcpy ft_strncpy ft_strcat ft_strncat ft_strlcat\
		ft_strchr ft_strchri ft_strrchr ft_strstr ft_strnstr\
		ft_strcmp ft_strncmp ft_strrev ft_atoi ft_isalpha\
		ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper\
		ft_tolower ft_memalloc ft_memdel ft_strnew ft_strdel\
		ft_strclr ft_striteri ft_striteri ft_strmap ft_strmapi\
		ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim\
		ft_strsplit ft_itoa ft_ultoa ft_ftoa ft_ultoa_base\
		ft_ltoa_base ft_putchar ft_putstr ft_putendl ft_putnbr\
		ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
		ft_lstnew ft_ltoa ft_lstdelone ft_lstdel ft_lstiter\
		ft_lstmap ft_islower ft_strlower ft_isupper ft_lstadd\
		ft_striteri ft_striter ft_putarr get_next_line ft_splitdel\
		ft_max ft_min ft_isspace ft_isdigit_base ft_has_prefix\
		ft_atoi_base ft_isnumber ft_abs ft_strsplit_len\
		ft_free_split_array ft_atoi32 ft_str_tolower\
		check_base_prec check_digit_prec check_digit_sign check_form\
		check_settings delete_zero ft_printf ft_str_prec\
		ftoa_prec_e ftoa_prec_eg ftoa_prec_f ftoa_prec_fg\
		get_exponent get_flag get_mod get_prec_num_e\
		get_prec_num_f get_precision get_spec get_tag\
		get_width init_char_arg init_flag init_int_arg\
		init_long_double init_prec_arg init_str_arg init_wchar_arg\
		init_wstr_arg nan_inf print_base_pre print_base_width\
		print_base print_char_width print_char parse_and_print\
		print_digit_sign print_digit_width print_digit\
		print_invalid_spec print_invalid_width print_null_char\
		print_prec_e print_prec_f print_prec_g print_prec_width\
		print_ptraddr_width print_ptraddr print_str_width print_str\
		print_wchar_minus print_wchar print_wstr_minus print_wstr\
		ptraddr_prec put_wc put_wchar put_wstr_c put_wstr\
		spec_base spec_char spec_int spec_non_printable\
		spec_percent spec_precision spec_ptraddr spec_return\
		spec_unsint spec_wchar

SRCD	=	src
OBJD	=	obj
INCD	=	inc

SRCS	=	$(addprefix $(SRCD)/, $(addsuffix .c, $(FILE)))
OBJS	=	$(addprefix $(OBJD)/, $(addsuffix .o, $(FILE)))
INCS	=	$(addprefix $(INCD)/, $(addsuffix .h, header libft))

CMPL	=	gcc $(addprefix -W, all extra error)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@printf "\r\33[2K$@\t   \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS) | $(OBJD)
	@$(CMPL) -o $@ -c $< -I$(INCD)
	@printf "\r\33[2Klibft\t   \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%)"

$(OBJD):
	@mkdir -p $@

clean:
	@rm -rf $(OBJD)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
