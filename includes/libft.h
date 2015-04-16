/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:12:39 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/14 16:53:38 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# define S_CHAR		sizeof(char)
# define S_SHORT	sizeof(short)
# define S_INT		sizeof(int)
# define S_FOAT		sizeof(float)
# define S_LONG		sizeof(long)
# define S_LLONG	sizeof(long long)

# define BUFF_SIZE	8

typedef char	t_byte;
typedef char	t_type;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

/*
**       Memory manipulation function
**  - Manipulation
**  - Search
**  - Allocation
*/
void			ft_bzero(void *s, size_t n);
void			ft_swapb(t_byte *a, t_byte *b);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			*ft_memset(void *b, int c, size_t len);

/*
**       String managment
**  - Copy, comcatenation and clearing
**  - Research
**  - Compare and information extraction
**  - Allocation
**  - Iteration
**	- get_next_line
*/
int				ft_strerrase_c(char *str, char c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
void			ft_strclr(char *s);
size_t			ft_strlcat(char *s1, const char *src, size_t n);

char			*ft_strstr(const char *str1, const char *str2);
char			*ft_strnstr(const char *str1, const char *str2, size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strnchr(const char *str, const char c, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strtrim(char const *s);

int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlen_unt_c(char const *str, char c);
int				ft_strcount_c(const char *str, char c);
char			**ft_strsplit(char const *s, char c);

char			*ft_strdup(const char *str);
char			*ft_strcdup(const char *s1, char c);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin_join(char const **table, char const *patern);
char			*ft_strmerge(char *s1, char *s2);
char			*ft_strmerge_buff(char *s, char const *buffer);
char			**ft_strsplit(char const *s, char c);
t_list			*ft_strlsplit(char const *s, int c);
void			ft_strdel(char **str);
void			ft_freesplit(char **table);

void			ft_striter(char *s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int				get_next_line(int fd, char **line);

/*
**       Caracter manipulation
**  - Caracter categories
**  - Simple caracter transformation
*/
int				ft_isupper(int c);
int				ft_islower(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_isallow(int c);

int				ft_toupper(int c);
int				ft_tolower(int c);

/*
**       Conversion tools
*/
int				ft_atoi(const char *str);
char			*ft_itoa(int n);

/*
**		Mathematic tools (In progress. Think about a libmath ?)
**	- Get information
*/
int				ft_getpow(long n);
int				ft_getsigne(long *n);

/*
**       Print function
**  - Standard
**  - File Descriptor
*/
void			ft_putchar(char c);
void			ft_puthex(int c);
void			ft_putnbrhex(int c);
void			ft_putdou(double d);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);

void			ft_putchar_fd(char c, int fd);
void			ft_puthex_fd(int c, int fd);
void			ft_putnbrhex_fd(int c, int fd);
void			ft_putdou_fd(double d, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

/*
** 		List manipulation
**	- creation and allocation
**	- add ellement, del ellement
**	- iteration, map
*/
t_list			*ft_lstnew(void const *content, size_t content_size);

void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstaddend(t_list **lst, t_list *elem);

void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstchr(t_list *lst, int (*f)(void*, int));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
**		Table sorting
**	This part contain function and their associate macro
**	- Bubble
**	- Quicksort
**		Fuck quicksort.
**	Yes, this have some fucking ugly prototype thanks to the norme...
*/
void			ft_tabsort_bub\
					(int *tab, size_t i, size_t max, int (*f)(int, int));
# define SORT_BUB(tab, max, f)		ft_tabsort_bub(tab, 0, max, f)

#endif
