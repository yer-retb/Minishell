/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:08:48 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/17 01:25:40 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)

{
	size_t	a;
	size_t	len_s;

	a = 0;
	len_s = 0;
	while (src[len_s] != '\0')
		len_s++;
	if (dstsize != 0)
	{
		while (src[a] && (a < dstsize - 1))
		{	
			dst[a] = src[a];
			a++;
		}
		dst[a] = '\0';
	}
	return (len_s);
}
