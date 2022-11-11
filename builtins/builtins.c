/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/11/11 04:54:46 by yer-retb         ###   ########.fr       */
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
	excut_herdoc(data);
	if (id == 0)
	{
		ft_excut_cmd(data, path);
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

void	ft_all_builtins(t_env **env, t_data data, char **path, int *prosid)
{
	if (data.str && !ft_strncmp("cd", data.str[0], 2))
		built_cd(*env, *(data.str + 1));
	else if (data.str && !ft_strcmp("pwd", data.str[0]))
		built_pwd(*env);
	else if (data.str && !ft_strcmp("env", data.str[0]))
		built_env(*env, data.out);
	else if (data.str && !ft_strcmp("echo", data.str[0]))
		built_echo(data.str + 1, data.out);
	else if (data.str && !ft_strcmp("exit", data.str[0]))
		built_exit(data.str + 1);
	else if (data.str && !ft_strcmp("export", data.str[0]))
		built_export(*env, data.str + 1, data.out);
	else if (data.str && !ft_strcmp("unset", data.str[0]))
		built_unset(env, data.str + 1);
	else
		bash_builtin(data, path, prosid);
}

void	builtins(t_env **env, t_data *data)
{
	int		i;
	char	**path;
	int		stat;
	int		*proid;

	proid = malloc(sizeof(int) * data[0].size);
	g_b.ft1 = 0;
	g_b.ft2 = 1;
	stat = 0;
	path = get_binary_file(*env);
	i = 0;
	g_b.pipes = malloc(sizeof(int *) * 2);
	while (i < 2)
	{
		g_b.pipes[i] = malloc(sizeof(int) * 2);
		pipe(g_b.pipes[i]);
		i++;
	}
	i = 0;
	if (data->out < 2 && data[0].size > 1)
		data->out = g_b.pipes[g_b.ft1][1];
	swap(&g_b.ft1, &g_b.ft2);
	while (i < data[0].size - 1 && (data->flag == 0))
	{
		ft_all_builtins(env, data[i], path, &proid[i]);
		i++;
		close(g_b.pipes[g_b.ft1][0]);
		close(g_b.pipes[g_b.ft1][1]);
		pipe(g_b.pipes[g_b.ft1]);
		if (data[i].in < 2)
			data[i].in = g_b.pipes[g_b.ft2][0];
		if (data[i].out < 2 && i < data[0].size - 1)
			data[i].out = g_b.pipes[g_b.ft1][1];
		swap(&g_b.ft1, &g_b.ft2);
	}
	ft_all_builtins(env, data[i], path, &proid[i]);
	i = 0;
	// closed opened files
	while (i < data->size)
	{
		if (data[i].in > 2)
			close(data[i].in);
		if (data[i].out > 2)
			close(data[i].out);
		i++;
	}
	//close pipes
	while (i < 2)
	{
		close(g_b.pipes[i][1]);
		close(g_b.pipes[i][0]);
		i++;
	}
	i = 0;
	while (i < data[0].size)
	{
		waitpid(proid[i], &stat, 0);
		if (WIFEXITED(stat))
			g_b.exit_val = (WEXITSTATUS(stat));
		i++;
	}
}
