/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:29:49 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/17 01:25:40 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	int		tab [256];
	int		i;
	size_t	len;

	if (!s1)
		return (NULL);
	i = -1;
	len = ft_strlen(s1) - 1;
	ft_bzero(tab, 256);
	while (set[++i])
		tab[(int)set[i]] = 1;
	i = 0;
	while (tab[(int)s1[i]] == 1)
		i++;
	if (i == ft_strlen(s1))
		return (ft_calloc(1, sizeof(char)));
	while (tab[(int)s1[len]] == 1)
		--len;
	return (ft_substr(s1, i, len - i + 1));
}
