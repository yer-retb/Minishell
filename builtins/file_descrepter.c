/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_descrepter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:08:46 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/06 23:20:32 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	get_file_descr(t_data *data)
{
	int	i;
	int	fd[2];
	// int	tmp;

	i = 0;
	if (data[0].size == 1)
		return;
	else
	{
		pipe(fd);
		// printf("fd 0 {%d}, fd 1 {%d}\n", fd[0], fd[1]);
		if(fork() == 0)
		{
			close(fd[1]);
			dup2(fd[0], STDIN_FILENO);
			close(fd[0]);
		}
		else
		{
			close(fd[0]);
			dup2(fd[1], STDOUT_FILENO);
			close(fd[1]);
		}
		i++;
	}
}
