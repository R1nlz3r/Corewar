/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kda-silv <kda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:53:18 by kda-silv          #+#    #+#             */
/*   Updated: 2017/12/13 18:42:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** includes
*/

# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>
# include <limits.h>
# include <inttypes.h>

/*
** define
*/

# define BUFF_SIZE 50
# define HH 1
# define H 2
# define LL 3
# define L 4
# define J 5
# define Z 6

/*
** define color
*/

# define TCLN "\x1B[1;1H\x1B[2J"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

/*
** typedef
*/

typedef	struct		s_printf_data
{
	int				len;
	int				precision;
	int				hash;
	int				zero[3];
	int				length;
	char			plus;
	char			d_space;
	char			prec_exist;
	char			pad3;
	char			*flags;
	char			*str;
	va_list			ap;
	int				(*functions[22])(struct s_printf_data **);
}					t_printf_data;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_fd
{
	int				fd;
	int				pad;
	char			*buffer;
	struct s_fd		*next;
	struct s_fd		*prev;
}					t_fd;

/*
** libft
*/

int					ft_abs(int i);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_convert_bin_to_decimal(char *bin);
int					ft_error_close_int(int fd);
int					ft_error_close_str_int(char const *str, int fd);
void				*ft_error_close_str_void(char const *str, int fd);
void				*ft_error_close_void(int fd);
int					ft_error_str_int(char const *str);
void				*ft_error_str_void(char const *str);
int					ft_factorial(int nb);
void				ft_free_tab(char ***tab);
int					ft_intlen(int nbr);
int					ft_intlen_unsigned(unsigned int nbr);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_islower(int c);
int					ft_isnumber(char *str);
int					ft_isprint(int c);
int					ft_isupper(int c);
char				*ft_itoa(int n);
int					ft_longlonglen(long long nbr);
int					ft_longlonglen_unsigned(unsigned long long nbr);
char				*ft_longlong_to_binaire(unsigned long long nbr);
char				*ft_longlong_to_hexa(unsigned long long n, char *value);
char				*ft_longlong_to_octal(unsigned long long n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
int					ft_lst_size(t_list *lst);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
double				ft_pow(double x, double y);
int					ft_print_from_to(char *str, int from, int to);
int					ft_putchar(char c);
int					ft_putchar_fd(char c, int fd);
int					ft_putendl(char const *s);
int					ft_putendl_fd(char const *s, int fd);
int					ft_putnbr(int n);
int					ft_putnbr_fd(int n, int fd);
long long			ft_putnbr_longlong(long long n);
int					ft_putnbr_longlong_unsigned(unsigned long long nb);
int					ft_putnbr_unsigned(unsigned int n);
int					ft_putstr(char const *s);
int					ft_putstr_fd(char const *s, int fd);
int					ft_puttab(char **tab);
int					ft_puttab_fd(char **tab, int fd);
char				*ft_realloc_str(char *ptr, size_t size);
char				**ft_split(char *str, int count, int words, int size);
int					ft_sqrt(int nb);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(char *str);
size_t				ft_strlen_char(char *str, char c);
size_t				ft_strlen_words(char *str, char c);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *str, const char *to_find
						, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *to_find);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_wputchar(wchar_t c);
int					ft_wstrlen(wchar_t *s);
int					get_next_line(const int fd, char **line);
int					write_octet(char *mask);

/*
** ft_printf
*/

int					ft_printf(const char *str, ...);
t_printf_data		*init_functions(t_printf_data *data);
int					run_printf(t_printf_data **data);
int					do_flags(t_printf_data **data);
void				reinit_data(t_printf_data **data);
int					precision_char(t_printf_data **data, char *str);
int					precision_long(t_printf_data **data, long long nbr);
int					precision_unsigned_long(t_printf_data **data
						, unsigned long long nbr);
unsigned long long	take_unsignedlonglong(t_printf_data **data);
int					flag_zero(t_printf_data **data);
int					do_flag_zero(t_printf_data **data
						, int flag, int size, int len);
int					flag_length(t_printf_data **data);
long long			return_length(t_printf_data **data);
unsigned long long	return_length_unsigned(t_printf_data **data);
int					flag_c(t_printf_data **data);
int					flag_upc(t_printf_data **data);
int					flag_s(t_printf_data **data);
int					flag_ups(t_printf_data **data);
int					write_wchar(wchar_t *s, int len, int size
						, t_printf_data **data);
int					flag_d(t_printf_data **data);
int					flag_i(t_printf_data **data);
int					flag_long(t_printf_data **data);
int					flag_ulong(t_printf_data **data);
int					flag_u(t_printf_data **data);
int					flag_o(t_printf_data **data);
int					flag_x(t_printf_data **data);
int					flag_upx(t_printf_data **data);
int					flag_point(t_printf_data **data);
int					flag_hashtag(t_printf_data **data);
int					flag_p(t_printf_data **data);
int					flag_percent(t_printf_data **data);
int					flag_upd(t_printf_data **data);
int					flag_upu(t_printf_data **data);
int					flag_upo(t_printf_data **data);
int					flag_b(t_printf_data **data);

#endif
