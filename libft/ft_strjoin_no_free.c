/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_no_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:50:24 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 05:49:18 by yer-retb         ###   ########.fr       */
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
	final = ft_malloc(len + 1);
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
	return (final);
}
