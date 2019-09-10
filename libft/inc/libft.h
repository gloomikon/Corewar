/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhurba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:46:12 by mzhurba           #+#    #+#             */
/*   Updated: 2019/08/01 11:18:51 by mzhurba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <stdbool.h>

# define BUFF_SIZE 1

int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_abs(int x);
void				ft_putmem(void *s, int a);
char				*ft_strrev(char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *str);
void				ft_putnbr(int nbr);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putarr(char **arr);
char				*ft_itoa(int n);
char				*ft_ltoa(long n);
char				*ft_ftoa(long double d);
char				*ft_ultoa(unsigned long n);
char				*ft_ultoa_base(unsigned long n, int base);
char				*ft_ltoa_base(long n, int base);
long long			ft_atoi(const char *str);
int32_t				ft_atoi32(const char *str);
int					ft_atoi_base(const char *str, int base);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isspace(int c);
int					ft_isdigit(int c);
int					ft_isnumber(char *str, int base);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_has_prefix(const char *str, int base);
int					ft_isdigit_base(char c, int base);
void				ft_strlower(char *s);
char				*ft_str_tolower(char *str);
char				*ft_strsub(char const *s, int start, int len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst,
	const void *restrict src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strlen(const char *str);
int					ft_wstrlen(wchar_t *wc);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				ft_splitdel(char **split);
char				*ft_strstr(const char *big,
	const char *little);
char				*ft_strnstr(const char *big,
	const char *little, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strsplit_len(char **split);
void				ft_free_split_array(char **split);

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_gnl
{
	char	*rests[256];
	char	**curr;
	char	*buf;
}					t_gnl;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *nw);
void				ft_lstiter(t_list *lst, void (*f)(t_list	*elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list	*elem));
void				ft_putarr(char **s);
int					get_next_line(int fd, char **line);

#endif
