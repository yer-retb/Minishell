/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_no_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:05:33 by enja              #+#    #+#             */
/*   Updated: 2022/10/07 02:36:34 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_no_free(char *s1, char *s2)
{
	char	*final;
	int		len;
	int		n;
	int		i;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
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
	free(s1);
	final[i] = '\0';
	return (final);
}
