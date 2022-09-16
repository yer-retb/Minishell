/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:58:55 by yer-retb          #+#    #+#             */
/*   Updated: 2021/11/26 18:21:27 by yer-retb         ###   ########.fr       */
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
	int			i;
	char		*rsl;
	int			count;
	long int	tmp;

	count = count_int(n);
	i = 0;
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
