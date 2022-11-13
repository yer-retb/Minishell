/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils_ll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:28:03 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/12 22:32:12 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	ft_excut_cmd(t_data data, char **path)
{
	int		i;
	char	*cmd;

	i = -1;
	if (data.str)
	{
		if (scan_path(data.str[0]) == 0)
		{
			cmd = ft_strjoin_no_free("/", data.str[0]);
			while (path[++i])
				path[i] = ft_strjoin_no_free(path[i], cmd);
			cmd = check_command(path, data.str[0]);
			if (cmd)
			{
				data.str[0] = cmd;
				execute(data);
			}
		}
		else if (check_path(data.str[0]))
			execute(data);
	}
	else
	{
		write (2, "ll\n", 3);
		if (data.in != 0)
			close(data.in);
	}
}

char	**get_binary_file(t_env *env)
{
	t_env	*save;
	char	**pathlist;

	save = env;
	while (save)
	{
		if (ft_strcmp(save->name, "PATH") == 0)
			pathlist = ft_split(save->path, ':');
		save = save->next;
	}
	return (pathlist);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
