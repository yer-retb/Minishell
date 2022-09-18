/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:52:48 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 22:25:51 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*string;

	length = ft_strlen(s1);
	string = malloc(length + 1 * sizeof(char));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s1, length + 1);
	return (string);
}
