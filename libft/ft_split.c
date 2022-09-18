/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:02:34 by enja              #+#    #+#             */
/*   Updated: 2021/12/02 18:07:50 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*zy_extstr(char const *s, int start, int len)
{
	char	*dst;
	int		a;

	a = 0;
	dst = malloc(len + 1 * sizeof(char));
	if (!dst)
		return (NULL);
	while (a < len)
	{
		dst[a++] = s[start++];
	}
		dst[a] = '\0';
	return (dst);
}

static int	zymm_len(const char *s, char c, int a)
{
	int	b;

	b = 0;
	while (s[a] != c && s[a])
	{
		a++;
		b++;
	}
	return (b);
}

static int	sepsign(const char *s, char sep)
{
	int		sepsign;
	int		a;

	sepsign = 0;
	a = 0;
	while (*s == sep)
	s++;
	while (s[a] != '\0')
	{
		if (s[a] == sep && s[a + 1] != sep)
			sepsign++;
		a++;
		if (s[a] == '\0' && s[a - 1] != sep)
			sepsign++;
	}
	return (sepsign);
}

char	**ft_split(const char *s, char c)
{
	int		a;
	int		aix;
	char	**finaldest;
	char	*predest;

	if (!s)
		return (NULL);
	a = 0;
	aix = 0;
	finaldest = malloc((sepsign(s, c) + 1) * sizeof(char *));
	if (!finaldest)
		return (NULL);
	while (s[a] != '\0')
	{
		while (s[a] == c)
			a++;
		if (s[a] != c && s[a] != '\0')
		{
			predest = zy_extstr(s, a, zymm_len(s, c, a));
			a += zymm_len(s, c, a);
			finaldest[aix++] = predest;
		}
	}
	finaldest[aix] = NULL;
	return (finaldest);
}
