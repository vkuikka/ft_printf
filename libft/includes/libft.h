/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:44:12 by vkuikka           #+#    #+#             */
/*   Updated: 2020/02/12 18:28:01 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

long long			ft_pow(long long num, int pow);
void				ft_putnbr_base(unsigned long long num,
					int base, int lowercase);
int					ft_atoi_base(const char *nb, int base);
int					ft_atoi(const char *str);
char				*ft_itoa_base(unsigned long long num,
					int base, int lowercase);
int					*ft_strsplit_int(char *s, char c);
int					ft_abs(int num);
void				ft_swap(int *value1, int *value2);
int					**ft_permutations(int a[], int size, int n);
int					**ft_new_int_arr(unsigned str_len, unsigned arr_len);
char				**ft_new_char_arr(unsigned str_len, unsigned arr_len);
int					ft_factorial(int num);
void				ft_putnbr_arr(int **array,
					unsigned arr_len, unsigned str_len);
void				ft_putchar_arr(char **array,
					unsigned arr_len, unsigned str_len);
void				ft_fill_array(char const *s, char c, char **ar);
int					*ft_len_words(const char *s, const char c);
int					ft_word_count(const char *s, const char c);
int					ft_iscntrl(int c);
int					ft_islower(int c);
int					ft_isupper(int c);
int					ft_isspace(int c);
int					ft_sqrt(int nb);
int					ft_isalpha(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst,
					const void *src, size_t n);
void				*ft_memccpy(void *dst,
					const void *src, int c, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1,
					const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strdup(const char *s1);
void				ft_bzero(void *s, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isalnum(int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memalloc(size_t size);
char				*ft_strnew(size_t size);
void				*ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_itoa(int n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_memdel(void **ap);
void				ft_strdel(char **as);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
