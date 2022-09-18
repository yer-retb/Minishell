/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:59:54 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/18 05:28:41 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)

{
	int		i;
	int		len_1;
	int		len_2;
	char	*p;

	i = -1;
	// if (!s1)
	// 	s1 = ft_strdup("");
	if (s1 && s2)
	{
		len_1 = ft_strlen(s1);
		len_2 = ft_strlen(s2);
		p = (char *)malloc ((len_1 + len_2) * sizeof(char) + 1);
		if (!p)
			return (NULL);
		while (s1[++i] != '\0')
			p[i] = s1[i];
		i = -1;
		while (s2[++i] != '\0')
			p[len_1 + i] = s2[i];
		p[len_1 + i] = '\0';
		free(s1);
		free(s2);
		return (p);
	}
	return (NULL);
}
