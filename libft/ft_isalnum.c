/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:59:08 by yer-retb          #+#    #+#             */
/*   Updated: 2021/11/26 18:14:14 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if ((i >= 'a' && i <= 'z')
		|| (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
		return (1);
	return (0);
}
