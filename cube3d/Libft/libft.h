/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: femoreno <femoreno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:23:53 by prosas-p          #+#    #+#             */
/*   Updated: 2024/11/25 17:01:07 by femoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char			*ft_itoa(int n);
char			*ft_strdup(const char *s1);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
void			ft_putnbr_fd(int n, int fd);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memset(void *str, int c, size_t n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			ft_lstadd_front(t_list **lst, t_list *new);
void			*ft_memchr(const void *str, int c, size_t n);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t			ft_strlen(const char *str);
size_t			ft_strlenc(const char *s, char c);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isdigit(int c);
int				ft_isnumeric(char *str);
int				ft_lstsize(t_list *lst);
int				ft_atoi(const char *str);
int				ft_isalpha(unsigned int c);
int				ft_isascii(unsigned int n);
int				ft_isalnum(unsigned int n);
int				ft_isprint(unsigned int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
char			*get_next_line(int fd);
char			*ft_substr_nextl(char *s, unsigned int start,
					unsigned int len);
char			*free_fail_nextl(char **s1, char **s2);
char			*ft_strjoin_nextl(char **s1, char **s2);
unsigned int	ft_strlen_nextl(const char *s, int boolxd);
char			*ft_strdup_nextl(char **s1);

#endif