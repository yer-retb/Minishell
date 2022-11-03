/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:53:07 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/03 19:07:11 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	its_n(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	built_echo(char **str)
{
	int	i;

	i = 0;
	if (!str[0])
	{
		printf("\n");
		return ;
	}
	if (its_n(str[i]) && (!ft_strncmp("-n", str[0], 2)))
	{
		i = 1;
		while (str[i] && (ft_strncmp("-n", str[i], 2) == 0) && its_n(str[i]))
			i++;
		while (str && str[i])
		{
			if (!ft_strcmp("$?", str[i]))
				str[i] = ft_strdup(ft_itoa(exit_val));
			printf(" %s", str[i++]);
		}
	}
	else
	{
		while (str[i])
		{
			if (!ft_strcmp("$?", str[i]))
				str[i] = ft_strdup(ft_itoa(exit_val));
			printf("%s ", str[i++]);
		}
		printf("\n");
	}
}
