/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/11/08 03:48:55 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	excut_herdoc(t_data data)
{
	t_red	*tmp;
	int fd;

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
	}
}

void	ft_excut_built(t_data data)
{
	t_red	*tmp;	

	if (data.red)
	{
		tmp = data.red;
		while (tmp)
		{
			if (tmp->type == OUTF || tmp->type == APD)
			{
				printf("in %d\n", data.out);
				if (data.str)
					dup2(data.out, STDOUT_FILENO);
				close(data.out);
			}
			else if (tmp->type == INF)
			{
				printf("out %d\n", data.in);
				if (data.str)
					dup2(data.in, STDIN_FILENO);
			}
			tmp = tmp->next;
		}
	}
}

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

void	bash_builtin(t_data data, char **path)
{
	int id;

	id = fork();
	if (id == 0)
	{
		excut_herdoc(data);
		// ft_excut_built(data);
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

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_all_builtins(t_env **env, t_data data, char **path)
{
	if (data.str && !ft_strncmp("cd", data.str[0], 2))
		built_cd(*env, *(data.str + 1));
	else if (data.str && !ft_strcmp("pwd", data.str[0]))
		built_pwd(*env);
	else if (data.str && !ft_strcmp("env", data.str[0]))
		built_env(*env);
	else if (data.str && !ft_strcmp("echo", data.str[0]))
		built_echo(data.str + 1);
	else if (data.str && !ft_strcmp("exit", data.str[0]))
		built_exit(data.str + 1);
	else if (data.str && !ft_strcmp("export", data.str[0]))
		built_export(*env, data.str + 1);
	else if (data.str && !ft_strcmp("unset", data.str[0]))
		built_unset(env, data.str + 1);
	else
		bash_builtin(data, path);
}

void	builtins(t_env **env, t_data *data)
{
	int		i;
	char	**path;

	
	gb.ft1 = 0;
	gb.ft2 = 1;
	path = get_binary_file(*env);
	i = 0;
	gb.pipes = malloc(sizeof(int *) * 2);
	while(i < 2)
	{
		gb.pipes[i] = malloc(sizeof(int) * 2);
		pipe(gb.pipes[i]);
		i++;
	}
	i = 0;
	if (data->out < 2 && data[0].size > 1)
		data->out = gb.pipes[gb.ft1][1];
	swap(&gb.ft1, &gb.ft2);
	while (i < data[0].size - 1 && (data->flag == 0))
	{
		ft_all_builtins(env, data[i], path);
		i++;
		close(gb.pipes[gb.ft1][0]);
		close(gb.pipes[gb.ft1][1]);
		pipe(gb.pipes[gb.ft1]);
		if (data[i].in < 2)
			data[i].in = gb.pipes[gb.ft2][0];
		if (data[i].out < 2 && i < data[0].size - 1)
			data[i].out = gb.pipes[gb.ft1][1];
		swap(&gb.ft1, &gb.ft2);
	}
	ft_all_builtins(env, data[i], path);
	i = 0;

	// closed opened files
	for(int i = 0; i < data->size; i++)
	{
		if (data[i].in > 2)
			close(data[i].in);
		if (data[i].out > 2)
			close(data[i].out);
	}

	//close pipes
	while (i < 2)
	{
		close(gb.pipes[i][1]);
		close(gb.pipes[i][0]);
		i++;
	}
	i = 0;
	while(i < data[0].size)
	{
		waitpid(-1, 0, 0);
		i++;
	}
}
