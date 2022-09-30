/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:53:42 by enja              #+#    #+#             */
/*   Updated: 2022/09/19 00:11:56 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	int		len;
	int		n;
	int		i;

	if (!s1)
	{
		final = ft_strdup(s2);
		free (s2);
		return (final);
	}
	i = 0;
	n = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	final = malloc(len + 1);
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	while (s2[n])
	{
		final[i++] = s2[n++];
	}
	final[i] = '\0';
	free(s1);
	free(s2);
	return (final);
}
