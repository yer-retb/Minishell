/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_stat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 04:35:44 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/18 04:36:51 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	close_files(void)
{
	int	i;

	i = 0;
	while (++i < 2)
	{
		close(g_b.pipes[i][1]);
		close(g_b.pipes[i][0]);
	}
}

void	print_is_directory(char *cmd)
{
	printf("Minishell: %s: is a directory\n", cmd);
	g_b.exit_val = 126;
	exit(g_b.exit_val);
}

void	ft_is_directory(char *cmd)
{
	struct stat	path;

	lstat(cmd, &path);
	if ((path.st_mode & S_IFMT) == S_IFDIR)
		print_is_directory(cmd);
}
