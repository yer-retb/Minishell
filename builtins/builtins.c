/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/11/12 22:33:26 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	bash_builtin(t_data data, char **path, int *prosid)
{
	int	id;

	id = fork();
	*prosid = id;
	if (id == 0)
		ft_excut_cmd(data, path);
}

// void	ft_all_builtins(t_env **env, t_data *data, char **path, int *prosid)
// {
// 	if ((*data).str && !ft_strncmp("cd", (*data).str[0], 2))
// 		built_cd(*env, *((*data).str + 1));
// 	else if ((*data).str && !ft_strcmp("pwd", (*data).str[0]))
// 		built_pwd(*env);
// 	else if ((*data).str && !ft_strcmp("env", (*data).str[0]))
// 		built_env(*env, (*data).out);
// 	else if ((*data).str && !ft_strcmp("echo", (*data).str[0]))
// 		built_echo((*data).str + 1, (*data).out);
// 	else if ((*data).str && !ft_strcmp("exit", (*data).str[0]))
// 		built_exit((*data).str + 1);
// 	else if ((*data).str && !ft_strcmp("export", (*data).str[0]))
// 		built_export(*env, (*data).str + 1, (*data).out);
// 	else if ((*data).str && !ft_strcmp("unset", (*data).str[0]))
// 		built_unset(env, (*data).str + 1);
// 	else
// 		bash_builtin(data, path, prosid);
// }

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

void	built_pipe(t_data *data, int *proid)
{
	int	stat;
	int	i;

	i = -1;
	stat = 0;
	while (++i < data->size)
	{
		if (data[i].in > 2)
			close(data[i].in);
		if (data[i].out > 2)
			close(data[i].out);
	}
	i = -1;
	while (++i < 2)
	{
		close(g_b.pipes[i][1]);
		close(g_b.pipes[i][0]);
	}
	i = -1;
	while (++i < data[0].size)
	{
		waitpid(proid[i], &stat, 0);
		if (WIFEXITED(stat))
			g_b.exit_val = (WEXITSTATUS(stat));
	}
}

void	open_pipes(t_data *data)
{
	int	i;

	i = -1;
	g_b.ft1 = 0;
	g_b.ft2 = 1;
	while (++i < 2)
	{
		g_b.pipes[i] = malloc(sizeof(int) * 2);
		pipe(g_b.pipes[i]);
	}
	if (data->out < 2 && data[0].size > 1)
		data->out = g_b.pipes[g_b.ft1][1];
	swap(&g_b.ft1, &g_b.ft2);
}

void	builtins(t_env **env, t_data *data)
{
	int		i;
	char	**path;
	int		*proid;

	proid = malloc(sizeof(int) * data[0].size);
	path = get_binary_file(*env);
	i = 0;
	g_b.pipes = malloc(sizeof(int *) * 2);
	open_pipes(data);
	while (i < data[0].size - 1 && (data->flag == 0))
	{
		if (data->str)
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
	if (data->flag == 0 && data->str)
		ft_all_builtins(env, data[i], path, &proid[i]);
	built_pipe(data, proid);
}
