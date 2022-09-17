/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:20:48 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/17 01:25:40 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)

{
	int		i;
	int		j;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	p = malloc (i + 1);
	if (!p)
		return (NULL);
	else
	{
		j = 0;
		while (j < i)
		{
			p[j] = s1[j];
			j++;
		}
	}
	p[j] = '\0';
	return (p);
}
