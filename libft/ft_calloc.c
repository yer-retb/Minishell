/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:51:02 by yer-retb          #+#    #+#             */
/*   Updated: 2021/11/26 18:11:10 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	void	*str;

	str = malloc (count * size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, count * size);
	return (str);
}
