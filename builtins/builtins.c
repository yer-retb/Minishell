/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 06:57:11 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 02:56:14 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

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
	close_files();
	i = -1;
	while (++i < data[0].size)
	{
		waitpid(proid[i], &stat, 0);
		if (g_b.is && WIFEXITED(stat))
			g_b.exit_val = (WEXITSTATUS(stat));
	}
	ft_signal();
	if (g_b.exit_val == 0)
		g_b.cnf = 0;
	g_b.is = 1;
}

void	open_pipes(t_data *data)
{
	int	i;

	i = -1;
	g_b.ft1 = 0;
	g_b.ft2 = 1;
	while (++i < 2)
	{
		g_b.pipes[i] = ft_malloc(sizeof(int) * 2);
		pipe(g_b.pipes[i]);
	}
	if (data->out < 2 && data[0].size > 1)
		data->out = g_b.pipes[g_b.ft1][1];
	swap(&g_b.ft1, &g_b.ft2);
}

void	close_pip(void)
{
	close(g_b.pipes[g_b.ft1][0]);
	close(g_b.pipes[g_b.ft1][1]);
}

void	builtins(t_env **env, t_data *data)
{
	int		i;
	char	**path;
	int		*proid;

	proid = ft_malloc(sizeof(int) * data[0].size);
	path = get_binary_file(*env);
	i = 0;
	g_b.pipes = ft_malloc(sizeof(int *) * 2);
	open_pipes(data);
	while (i < data[0].size - 1)
	{
		if (data->str)
			ft_all_builtins(env, data[i], path, &proid[i]);
		i++;
		close_pip();
		pipe(g_b.pipes[g_b.ft1]);
		if (data[i].in < 2)
			data[i].in = g_b.pipes[g_b.ft2][0];
		if (data[i].out < 2 && i < data[0].size - 1)
			data[i].out = g_b.pipes[g_b.ft1][1];
		swap(&g_b.ft1, &g_b.ft2);
	}
	if (data->str)
		ft_all_builtins(env, data[i], path, &proid[i]);
	built_pipe(data, proid);
}
