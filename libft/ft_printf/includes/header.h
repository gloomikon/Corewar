/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:20:53 by mzhurba           #+#    #+#             */
/*   Updated: 2019/07/08 19:16:49 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>
# include "../../includes/libft.h"
# define FLAGS		"# +-0*.123456789Lhjltz"
# define HEX		"boxBOX"
# define PREC		"fgeFGE"

# define IS_NUM(x)		(x >= '0' && x <= '9')
# define IS_PNUM(x)		(x >= '1' && x <= '9')

# define IS_PER(x)		(x == '%')
# define IS_INT(x)		(x == 'd' || x == 'i')
# define IS_UINT(x)		(x == 'u' || x == 'D' || x == 'U')
# define IS_SCHR(x)		(x == 'c' || x == 's')
# define IS_BSCHR(x)	(x == 'C' || x == 'S')

/*
** This is used to save flags " #+-0" and either number is negative
*/

# define F_HASH		(1 << 0)
# define F_SPACE	(1 << 1)
# define F_PLUS		(1 << 2)
# define F_MINUS	(1 << 3)
# define F_ZERO		(1 << 4)
# define F_NEGATIVE (1 << 5)

/*
** This is used to save size modifiers
*/

# define SM_NO_MOD	(1 << 7)
# define SM_LL		(1 << 8)
# define SM_HH		(1 << 9)
# define SM_BIG_L	(1 << 10)
# define SM_H		(1 << 11)
# define SM_J		(1 << 12)
# define SM_L		(1 << 13)
# define SM_T		(1 << 14)
# define SM_Z		(1 << 15)

typedef struct		s_pf_flag
{
	uint16_t		f;
	int				prec;
	int				width;
}					t_pf_flag;

typedef struct		s_pf_env
{
	va_list			ap[2];
	char			*out;
	int				tag;
	t_pf_flag		flag;
	int				fd;
	int				i;
	int				ret;
}					t_pf_env;

int					ft_printf(const char *restrict format, ...);
int					ft_dprintf(int fd, const char *restrict format, ...);

void				check_settings(const char *restrict fmt, t_pf_env *e);

void				get_tag(const char *restrict format, t_pf_env *e);
void				get_flag(const char *restrict format, t_pf_env *e);
void				get_spec(const char *restrict format, t_pf_env *e);
void				get_mod(const char *restrict format, t_pf_env *e);
void				get_width(t_pf_env *e);
void				get_precision(const char *restrict format, t_pf_env *e);

void				init_flag(t_pf_flag *flag);
void				init_int_arg(t_pf_env *e, long *tmp);
void				init_str_arg(t_pf_env *e, char **tmp);
void				init_char_arg(t_pf_env *e, int *tmp);
void				init_wstr_arg(t_pf_env *e, wchar_t **tmp);
void				init_wchar_arg(t_pf_env *e, wchar_t *tmp);
void				init_long_double(t_pf_env *e, long double *tmp);
void				init_prec_arg(t_pf_env *e, double *tmp);

void				parse_and_print(const char *restrict format, t_pf_env *e);

void				print_digit(t_pf_env *e);
void				print_digit_sign(t_pf_env *e);
void				print_digit_width(t_pf_env *e);

void				print_str(t_pf_env *e);
void				print_str_width(t_pf_env *e);

void				print_char(t_pf_env *e, char c);
void				print_null_char(t_pf_env *e);
void				print_char_width(t_pf_env *e);

void				print_wstr(t_pf_env *e, wchar_t *wc);
void				print_wstr_minus(t_pf_env *e, wchar_t *wc, int len);
void				put_wstr(t_pf_env *e, wchar_t c);
void				put_wstr_c(t_pf_env *e, char c);

void				print_wchar(t_pf_env *e, wchar_t wc);
void				put_wc(t_pf_env *e, wchar_t c);
void				print_wchar_minus(t_pf_env *e, wchar_t wc);
void				put_wchar(t_pf_env *e, char c);

void				check_digit_sign(t_pf_env *e);
void				check_digit_prec(t_pf_env *e);

void				print_base(t_pf_env *e, char type, long val);
void				print_base_pre(t_pf_env *e, char type, long val);
void				print_base_width(t_pf_env *e, char type);
void				check_base_prec(t_pf_env *e, char type);

void				print_invalid_spec(t_pf_env *e, char c);
void				print_invalid_width(t_pf_env *e);

void				nan_inf(t_pf_env *e, char type, double var);

void				print_prec_e(t_pf_env *e, long double d, char type);
long				get_prec_num_e(long double d, int prec);
void				ftoa_prec_e(t_pf_env *e, long double d, char type);
void				ftoa_prec_e(t_pf_env *e, long double d, char type);
void				get_exponent(long double d, char type, char **expo);
char				*ft_str_prec(char *s1, int dot, int end, int hash);
void				print_prec_width(t_pf_env *e);

void				print_prec_f(t_pf_env *e, long double d);
void				ftoa_prec_f(t_pf_env *e, long double d);
long				get_prec_num_f(long double d, int prec);

void				print_prec_g(t_pf_env *e, long double d, char type);
void				check_form(t_pf_env *e, long double d, char type);
void				ftoa_prec_eg(t_pf_env *e, long double d,
					char type, int prec);
void				ftoa_prec_fg(t_pf_env *e, long double d, int end);
void				delete_zero(char *tmp);

void				print_ptraddr(t_pf_env *e, char type);
void				ptraddr_prec(t_pf_env *e);
void				print_ptraddr_width(t_pf_env *e);

void				print_zero_to_ten(t_pf_env *e, char c);
void				print_ten_to_twenty(t_pf_env *e, char c);
void				print_twenty_to_thirty(t_pf_env *e, char c);

/*
** Output functions
*/

void				spec_percent(t_pf_env *e);
void				spec_int(t_pf_env *e);
void				spec_unsint(t_pf_env *e, char t);
void				spec_char(t_pf_env *e, char type);
void				spec_wchar(t_pf_env *e, char type);
void				spec_base(t_pf_env *e, char tp);
void				spec_precision(t_pf_env *e, char type);
void				spec_ptraddr(t_pf_env *e, char type);
void				spec_non_printable(t_pf_env *e);
void				spec_return(t_pf_env *e);

#endif
