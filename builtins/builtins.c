/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/11/05 03:33:10 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	bash_builtin(t_data data, char **path)
{
	int		i;
	char	*cmd;
	t_red	*tmp;
	int		fd;

	i = -1;
	fd = -1;
	if (fork() == 0)
	{
		if (data.red && data.red->type == 5)
		{
			tmp = data.red;
			while (tmp)
			{
				if (tmp->type == 5)
					fd = herdoc(tmp->file);
				tmp = tmp->next;
			}
		}
		if (data.red)
		{
			tmp = data.red;
			while (tmp)
			{
				if (tmp->type == OUTF || tmp->type == APD)
				{
					if (data.str)
						dup2(data.in, STDOUT_FILENO);
					close(data.in);
				}
				else if (tmp->type == INF)
				{
					if (data.str)
					{
						dup2(data.out, STDIN_FILENO);
						close(data.out);
					}
					else
					{
						close(data.out);
						exit(exit_val);
					}
				}
				tmp = tmp->next;
			}
		}
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
	else
		while (waitpid(-1, NULL, 0) == -1)
			;
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

void	builtins(t_env **env, t_data *data)
{
	int		i;
	char	**path;

	path = get_binary_file(*env);
	i = 0;
	while (i < data[0].size && (data->flag == 0))
	{
		if (data[i].str && !ft_strncmp("cd", data[i].str[0], 2))
			built_cd(*env, data->str[i + 1]);
		else if (data[i].str && !ft_strcmp("pwd", data[i].str[0]))
			built_pwd(*env);
		else if (data[i].str && !ft_strcmp("env", data[i].str[0]))
			built_env(*env);
		else if (data[i].str && !ft_strcmp("echo", data[i].str[0]))
			built_echo(data->str + 1);
		else if (data[i].str && !ft_strcmp("exit", data[i].str[0]))
			built_exit(data->str + 1);
		else if (data[i].str && !ft_strcmp("export", data[i].str[0]))
			built_export(*env, data->str + 1);
		else if (data[i].str && !ft_strcmp("unset", data[i].str[0]))
			built_unset(env, data->str + 1);
		else
			bash_builtin(data[i], path);
		i++;
	}
}
