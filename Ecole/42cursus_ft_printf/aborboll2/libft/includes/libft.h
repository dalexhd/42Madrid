/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 20:45:27 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/21 17:21:02 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef unsigned char			t_uchar;
typedef unsigned short			t_ushsort;
typedef short					t_shsort;
typedef short int				t_shsortint;
typedef unsigned int			t_uint;
typedef long int				t_long;
typedef long long int			t_llong;
typedef unsigned long int		t_ulong;
typedef unsigned long long int	t_ullong;
typedef int						t_bool;
typedef long double				t_ldouble;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
t_bool			ft_isalnum(int c);
t_bool			ft_isalpha(int c);
t_bool			ft_isascii(int c);
t_bool			ft_isdigit(int c);
t_bool			ft_isspace(int c);
t_bool			ft_isprint(int c);
char			*ft_itoa(int n);
char			*ft_itoa_ullong(t_ullong n);
char			*ft_itoa_llong(t_llong n);
char			*ft_itoa_long(t_long n);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int n);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr(char *s);
int				ft_get_next_line(int fd, char **line, t_ullong buffer_size);
void			ft_strdel(char **str);
void			ft_putendl_fd(char *s, int fd);
void			ft_putendl(char *s);
void			*ft_calloc(size_t count, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strnew(size_t size);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_numlen(long nb);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack,
				const char *needle, size_t len);
char			*ft_strrev(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strchr(const char *s, int c);
int				ft_countwords(char const *str, char c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_free(char *s1, char *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlen(const char *s);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strhas(const char *s, int c);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_abs(int num);
char			*ft_strto(char *str, int (*f)(int));
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
char			*ft_utoabase(t_ullong n, t_ullong b);
#endif
