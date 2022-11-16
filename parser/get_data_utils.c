/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:33:29 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:34:39 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"
#include <fcntl.h>

int	number_of_arg(t_psr *head)
{
	int		i;
	t_psr	*save;

	i = 0;
	save = head;
	while (save)
	{
		save = save->nx_tkn;
		i++;
	}
	return (i);
}

int	check_file(char *str)
{
	int	fd;
	int	fd2;

	fd = access(str, F_OK);
	fd2 = access(str, R_OK);
	if (fd == -1)
	{
		printf("Minishell: %s: no such file or directory\n", str);
		g_b.exit_val = 1;
		return (0);
	}
	if (fd2 == -1)
	{
		printf("Minishell: %s: Permission denied\n", str);
		g_b.exit_val = 1;
		return (0);
	}
	return (1);
}

void	ambiguous_redirect(void)
{
	g_b.exit_val = 1;
	print_fd(1, 2, "Minishell: ambiguous redirect\n");
}

void	put_red(t_red **red, char *str, int type)
{
	(*red)->type = type;
	(*red)->file = str;
}
