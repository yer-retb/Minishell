/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/11/03 23:08:26 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	execute(t_data data)
{
	int	sig;
	
	// dup2(data.in, STDOUT_FILENO);
	// close(data.in);
	sig = execve(data.str[0], data.str, NULL);
	if (sig == -1)
	{
		printf("Minishell: %s: command not found\n", data.str[0]);
		exit(127);
	}

}

int	check_file2(char *str)
{
	int	fd;

	fd = access(str, F_OK);
	if (fd == -1)
		return(0);	
	return (1);
}

int	check_file3(char *str)
{
	int	fd;

	fd = access(str, F_OK);
	if (fd == -1)
	{
		printf("Minishell: %s: No such file or directory\n", str);
		exit_val = 1;
		return(0);	
	}
	return (1);
}


void	bash_builtin(t_data data, char **path)
{
	int		i;
	char	*cmd;
	t_red	*tmp;
	int fd;

	i = 0;
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
					dup2(data.in, STDOUT_FILENO);
					close(data.in);
				}
				else if (tmp->type == INF)
				{
					dup2(data.out, STDIN_FILENO);
					close(data.out);
				}
				tmp = tmp->next;
			}
		}
		
		if (data.str)
		{
			cmd = "/";
			cmd = ft_strjoin_no_free(cmd ,data.str[0]);
			while (path[i])
			{
				cmd = ft_strjoin_no_free(path[i], cmd);
				if (check_file2(cmd) == 1)
				{
					data.str[0] = cmd;
					execute(data);
					while (waitpid(-1, NULL, 0) == -1);
					return;
				}
				else
				{
					free(cmd);
					cmd = "/";
					cmd = ft_strjoin_no_free(cmd ,data.str[0]);
				}
				i++;
			}
			if (check_file3(data.str[0]) == 1)
				execute(data);
		}
		
	}
	else
		while (waitpid(-1, NULL, 0) == -1);

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
