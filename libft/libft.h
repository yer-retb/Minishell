/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:08:11 by zy0tsh1           #+#    #+#             */
/*   Updated: 2022/11/11 00:32:25 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int				ft_strlcat(char *dst, const char *src, int dstsize);
int				ft_strlcpy(char *dest, const char *src, int size);
int				ft_strcmp(char *s1, char *s2);
void			ft_bzero(void *s, int n);
void			*ft_memset(void *b, int c, int len);
void			*ft_memcpy(void *dst, const void *src, int n);
void			*ft_memmove(void *dst, const void *src, int len);
void			*ft_memchr(const void *s, int c, int n);
int				ft_atoi(char *str);
int				ft_memcmp(const void *s1, const void *s2, int n);
int				ft_isascii(int a);
int				ft_isprint(int a);
int				ft_isalpha(char a);
int				ft_isdigit(int a);
int				ft_isalnum(char a);
int				ft_tolower(int a);
int				ft_toupper(int a);
int				ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *str, const char *tofind, int len);
int				ft_strncmp(const char *s1, const char *s2, int n);
void			*ft_calloc(int count, int size);
char			*ft_substr(char const *s, int start, int len);
char			*ft_strjoin(char*s1, char *s2);
char			**ft_split(char const *s, char c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_itoa(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
char			*ft_strjoin_no_free(char *s1, char *s2);
char			*moded_strnstr(char *str, char *needle, int len);
void			print_exit_error(char *str, int ex);
void			*save_malloc(int size);
#endif