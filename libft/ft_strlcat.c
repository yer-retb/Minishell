/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:22:33 by enja              #+#    #+#             */
/*   Updated: 2022/09/18 22:25:19 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	idx;
	int	dlen;
	int	slen;
	int	allsize;
	int	cpy;

	if ((!dst && dstsize == 0) || dstsize == 0)
		return (ft_strlen(src) + dstsize);
	idx = 0;
	slen = ft_strlen(src);
	dlen = ft_strlen(dst);
	if (dstsize <= dlen)
		return (slen + dstsize);
	allsize = ft_strlen(src) + ft_strlen(dst);
	cpy = dstsize - dlen;
	while (src[idx] && idx < cpy - 1)
	{
		dst[dlen] = src[idx];
		dlen++;
		idx++;
	}
	dst[dlen] = '\0';
	return (allsize);
}
