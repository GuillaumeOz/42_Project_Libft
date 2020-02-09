/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 11:30:46 by gozsertt          #+#    #+#             */
/*   Updated: 2020/02/03 13:18:16 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_FUNCTIONS_H
# define BASIC_FUNCTIONS_H

# define BINARY_BASE "01"
# define OCTAL_BASE "01234567"
# define DECIMAL_BASE "0123456789"
# define HEX_LOWER_BASE "0123456789abcdef"
# define HEX_UPPER_BASE "0123456789ABCDEF"

# define STDIN  0
# define STDOUT 1
# define STDERR 2

# define SENTINAL 1
# define CHARACTER 1
# define NONE -1

# define FAILURE -1
# define SUCCESS 1

# define BUFFER_SIZE 20

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isprint(int c);
int				ft_isascii(int c);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strncat(char *dest, const char *src, size_t n);
size_t			ft_strlcat(char *dest, const char *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strnew(size_t size);
char			*ft_strchr(const char *src, int c);
char			*ft_strrchr(const char *src, int c);
char			*ft_strstr(const char *src, const char *word);
char			*ft_strnstr(const char *src, const char *word, size_t n);
int				ft_atoi(const char *str);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **p);
void			ft_strdel(char **p);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoinfre(const char *s1, const char *s2,
				int free_s1, int free_s2);
char			*ft_strappend(const char *s1, const char *s2,
				int free_s1, int free_s2);
char			*ft_strprepend(const char *s1, const char *s2,
				int free_s1, int free_s2);

char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);

int				ft_valid_base(char *base_str);
size_t			ft_uintmaxlen_base(uintmax_t n, unsigned int base);
char			*ft_itoa(int n);
char			*ft_utoa_base(uintmax_t n, char *base, int precision);

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstadd_front(t_list **alst, t_list *lnew);
void			ft_lstadd_back(t_list **alst, t_list *lnew);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));

size_t			ft_intlen(intmax_t nb);
size_t			ft_seglen(const char *s, size_t start, int c);

size_t			ft_count_elems(char const *s, int c);
int				ft_is_white_space(char c);
char			*ft_strrev(char *str);
char			*ft_strpbrk (const char *s, const char *accept);
size_t			ft_strcspn(const char *s, const char *reject);

int				ft_ischar(const char *format, int c);
int				ft_isonlycharset(const char *format, const char *charset);
int 			ft_isnotonlycharset(const char *format, const char *charset);

char			*ft_strndupfree(const char *src, size_t n, int free_src);
char			*ft_strndup(const char *src, size_t n);
char			*ft_strdupfree(char *src, int free_src);
char			*ft_strdup(const char *src);

size_t			ft_strnlen(const char *s, size_t maxlen);

char			*ft_padding(int size, char c);

#endif
