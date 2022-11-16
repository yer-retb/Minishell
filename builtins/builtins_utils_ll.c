/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils_ll.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:28:03 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/16 06:14:18 by yer-retb         ###   ########.fr       */
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
}

void	bash_builtin(t_data data, char **path, int *prosid)
{
	int	id;

	id = fork();
	*prosid = id;
	if (id == 0)
		ft_excut_cmd(data, path);
}

char	**get_binary_file(t_env *env)
{
	t_env	*save;
	t_env	*tmp;
	char	**pathlist;

	save = env;
	tmp = env;
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
