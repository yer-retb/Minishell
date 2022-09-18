/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ky05h1n <ky05h1n@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:58:55 by yer-retb          #+#    #+#             */
/*   Updated: 2022/09/18 08:49:37 by ky05h1n          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_int(long int x)

{
	int			j;
	long int	n;

	n = x;
	j = 1;
	if (n < 0)
	{
		n = n * -1;
		j++;
	}
	while (n > 9)
	{
		n = n / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int n)

{
	char		*rsl;
	int			count;
	long int	tmp;

	count = count_int(n);
	rsl = (char *)malloc(sizeof (char) * (count + 1));
	if (!rsl)
		return (NULL);
	rsl[count] = '\0';
	count--;
	tmp = n;
	if (tmp < 0)
		tmp = tmp * -1;
	while (count >= 0)
	{
		rsl[count] = (tmp % 10) + 48;
		tmp = tmp / 10;
		count--;
	}
	if (n < 0)
		rsl[0] = '-';
	return (rsl);
}
