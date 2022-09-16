/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:58:05 by yer-retb          #+#    #+#             */
/*   Updated: 2021/11/26 19:25:38 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char				*s;
	char				*p;
	unsigned int		i;
	unsigned int		j;
	size_t				s_len;

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
