/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:19:51 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 22:26:07 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *needle, int len)
{
	int	i;
	int	j;

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
				return ((char *)&str[i + j]);
		}
		i++;
	}
	return (0);
}
