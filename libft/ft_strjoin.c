/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:53:42 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 23:24:20 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	zy_cpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a])
	{
		dest[a] = src[a];
		a++;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*predest;
	char	*finaldest;
	int		length;

	if ((!s1 && !s2))
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	length = ft_strlen(s1) + ft_strlen(s2);
	predest = malloc(length + 1 * sizeof(char));
	if (!predest)
		return (NULL);
	zy_cpy(predest, s1);
	finaldest = predest;
	ft_strlcpy(predest + ft_strlen(s1), s2, length + 1);
	free(s1);
	free(s2);
	return (finaldest);
}
