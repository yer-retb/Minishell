/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moded_strnstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:49:28 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/15 03:49:29 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*moded_strnstr(char *str, char *needle, int len)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (needle[i] == '\0')
		return ((char *)str);
	while ((str[i]) && (i < len))
	{
		j = 0;
		while (str[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
			{
				s = ft_strdup((char *)&str[i + j]);
				free(needle);
				return (s);
			}
		}
		i++;
	}
	free(needle);
	return (0);
}
