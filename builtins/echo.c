/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:53:07 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/17 03:34:11 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	its_n(char *str)
{
	int	i;

	i = 1;
	while ((ft_strlen(str) != 0) && str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo_utils(char **str, int fd)
{
	int	i;

	i = 1;
	while (str[i] && (ft_strncmp("-n", str[i], 2) == 0) && its_n(str[i]))
		i++;
	while (str && str[i])
	{
		if (!ft_strcmp("$?", str[i]))
			str[i] = ft_strdup(ft_itoa(g_b.exit_val));
		ft_putchar_fd(' ', fd);
		ft_putstr_fd(str[i++], fd);
	}
}

void	built_echo(char **str, int fd)
{
	int	i;

	i = 0;
	if (!str[0])
	{
		ft_putchar_fd('\n', fd);
		return ;
	}
	if (its_n(str[i]) && (!ft_strncmp("-n", str[0], 2)))
		echo_utils(str, fd);
	else
	{
		while (str[i])
		{
			if (!ft_strcmp("$?", str[i]))
				str[i] = ft_strdup(ft_itoa(g_b.exit_val));
			ft_putstr_fd(str[i++], fd);
			if (str[i])
				ft_putchar_fd(' ', fd);
		}
		ft_putchar_fd('\n', fd);
	}
}
