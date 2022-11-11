/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:29 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/10 23:34:20 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	herdoc(char *str)
{
	char	*cmd;
	int		fd[2];

	pipe(fd);
	cmd = NULL;
	cmd = readline(">");
	while (ft_strcmp(cmd, str) != 0)
	{
		write(fd[1], cmd, ft_strlen(cmd));
		write(fd[1], "\n", 1);
		free(cmd);
		cmd = readline(">");
	}
	close(fd[1]);
	return (fd[0]);
}

void	excut_herdoc(t_data data)
{
	t_red	*tmp;
	int		fd;

	fd = -1;
	if (data.red && data.red->type == 5)
	{
		tmp = data.red;
		while (tmp)
		{
			if (tmp->type == 5)
				fd = herdoc(tmp->file);
			tmp = tmp->next;
		}
		exit(g_b.exit_val);
	}
}
