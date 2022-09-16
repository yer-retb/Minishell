/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:47:08 by yer-retb          #+#    #+#             */
/*   Updated: 2021/11/26 18:30:18 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*str;
	char			*d;

	i = 0;
	if (!dst && !src)
		return (0);
	str = (char *)src;
	d = (char *)dst;
	while (i < n)
	{
		d[i] = str[i];
		i++;
	}
	return (dst);
}
