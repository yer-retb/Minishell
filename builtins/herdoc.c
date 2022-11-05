/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:50:29 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/05 01:43:40 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	herdoc(char *str)
{
	char	*cmd;
	int		fd[2];

	pipe(fd);
	cmd = NULL;
	cmd = readline("heredoc>");
	while (ft_strcmp(cmd, str) != 0)
	{
		write(fd[1], cmd, ft_strlen(cmd));
		write(fd[1], "\n", 1);
		cmd = readline(">");
	}
	close(fd[1]);
	return (fd[0]);
}
