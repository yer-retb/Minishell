/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:52:23 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/18 00:27:06 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	ft_if_isalpha(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[0][j]))
				print_exit_error(str[0], 255);
			j++;
		}
		i++;
	}
	if (i == 1)
		i = 0;
	return (i);
}

void	print_exit_error(char *str, int ex)
{
	printf("exit\nMinishel: exit: %s: numeric argument required\n", str);
	exit(ex);
}

void	built_exit(char **str)
{
	int	i;
	int	num;

	i = 0;
	if (g_b.s_size != 1)
		return ;
	if (!str[0])
	{
		printf("exit\n");
		exit(g_b.exit_val);
	}
	else if (ft_if_isalpha(str) > 0)
	{
		printf("exit\nMinishell: exit: too many arguments\n");
		return ;
	}
	num = ft_atoi(str[0]);
	g_b.exit_val = num % 256;
	printf("exit\n");
	exit(g_b.exit_val);
}
