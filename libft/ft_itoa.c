/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:35:28 by enja              #+#    #+#             */
/*   Updated: 2021/11/30 17:09:33 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	l;

	l = 0;
	if (n < 0)
	{
		l++;
	}
	while (n != 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static char	*posetive(char *strp, int n)
{
	int		zix;
	int		b;

	zix = len(n);
	if (!strp)
		return (NULL);
	zix--;
	while (zix >= 0)
	{
		b = n % 10;
		n = n / 10;
		strp[zix] = b + 48;
		zix--;
	}
	return (strp);
}

char	*ft_itoa(int n)
{
	int		aix;
	char	*string;
	int		a;

	if (n == 0)
		return (string = ft_strdup("0"));
	aix = len(n);
	string = malloc((aix + 1) * sizeof(char));
	if (!string)
		return (NULL);
	string[aix--] = '\0';
	if (n < 0)
	{
		*string = '-';
		while (aix > 0)
		{
			a = n % 10;
			n = n / 10;
			string[aix--] = (a * -1) + 48;
		}
		return (string);
	}
	return (string = posetive(string, n));
}
