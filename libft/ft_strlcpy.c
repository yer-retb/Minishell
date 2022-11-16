/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:08:48 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/15 04:12:32 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcpy(char *dst, char *src, int dstsize)

{
	int	a;
	int	len_s;

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
