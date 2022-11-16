/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:23:13 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 05:52:47 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_isalpha(int i);
int		ft_isdigit(int i);
int		ft_isalnum(int i);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *b, int c, int len);
int		ft_strlen(char *str);
int		ft_strlcpy(char *dst, char *src, int dstsize);
int		ft_strlcat(char *dst, char *src, int n);
void	ft_bzero(void *s, int n);
void	*ft_memcpy(void *dst, const void *src, int n);
void	*ft_memmove(void *dst, const void *src, int n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(char *s, int c);
char	*ft_strrchr(char *s, int c);
int		ft_atoi(char *s);
char	*ft_strnstr(char *str, char *needle, int len);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, int n);
void	*ft_memchr(const void *str, int c, int n);
int		ft_memcmp(const void *s1, const void *s2, int n);
void	*ft_calloc(int count, int size);
char	*ft_strdup(char *s1);
char	*ft_substr(char *str, int start, int len);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(char *s1, char *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char *s, char (*f)(int, char));
void	ft_striteri(char *s, void (*f)(int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin_no_free(char *s1, char *s2);
char	*moded_strnstr(char *str, char *needle, int len);
void	print_exit_error(char *str, int ex);
void	*ft_malloc(int size);
#endif
