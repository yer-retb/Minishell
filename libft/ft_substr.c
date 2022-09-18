/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:25:08 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 22:27:18 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, int start, int len)
{
	char			*s;
	char			*p;
	int				i;
	int				j;
	int				s_len;

	s = (char *)str;
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	s_len = ft_strlen(str);
	if (start >= s_len)
		len = 0;
	if (len >= s_len)
		len = s_len - start;
	p = (char *) malloc (len * sizeof(char) + 1);
	if (!p)
		return (NULL);
	while (s[i] != '\0' && j < len)
	{
		p[j++] = s[start + i++];
	}
	p[j] = '\0';
	return (p);
}
