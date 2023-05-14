/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-kabb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:24:05 by mel-kabb          #+#    #+#             */
/*   Updated: 2023/05/10 21:53:41 by mel-kabb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

size_t	ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int arx);
int		ft_isalpha(int arg);
int		ft_isascii(int arx);
int		ft_isdigit(int arg);
int		ft_isprint(int arx);
char	*ft_strdup(const char *s1);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *str, int c);
int		ft_strncmp(char *first, char *second, size_t length);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int arx);
char	*ft_itoa(int n);
int		ft_strcmp(char *first, char *second);
int		ft_toupper(int k);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char *s1, char c);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strstr(char *str, char *to_find);
char	*ft_strjoin1(char *s1, char *s2);

#endif
