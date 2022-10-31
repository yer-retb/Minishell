/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/10/26 12:56:59 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	built_cd(t_env *envirement, char *str)
{
	char	*old_cwd;
	char	*buf;
	char	*pwd;
	t_env	*env;

	env = envirement;
	buf = NULL;
	old_cwd = getcwd(buf, 0);
	if (!str || (str[0] == '~'))
	{
		while (env)
		{
			if (!ft_strncmp("HOME", env->name, 5))
			{
				pwd = env->path;
				chdir(pwd);
				return ;
			}
			env = env->next;
		}
	}
	if (chdir(str) == 0)
	{
		pwd = getcwd(buf, 0);
		while (env)
		{
			if (ft_strncmp("OLDPWD", env->name, 6) == 0)
			{
				free(env->path);
				env->path = old_cwd;
			}
			if (ft_strncmp("PWD", env->name, 3) == 0)
			{
				free(env->path);
				env->path = pwd;
			}
			env = env->next;
		}
	}
	else
	{
		printf("Minishell: cd: %s: No such file or directory\n", str);
		exit_val = 1;
	}
}

void	execute(t_data data)
{
	int	sig;

	if (fork() == 0)
	{
		sig = execve(data.str[0], data.str, NULL);
		if (sig == -1)
		{
			printf("Minishell: %s: command not found\n", data.str[0]);
			exit(127);
		}
	}
	while (waitpid(-1, NULL, 0) == -1);
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

void	built_pwd(t_env *envirement)
{
	char	*buf;
	t_env	*env;

	env = envirement;
	buf = NULL;
	while (env)
	{
		if (ft_strncmp("PWD", env->name, 3) == 0)
		{
			env->path = getcwd(buf, 0);
			printf("%s\n", env->path);
		}
		env = env->next;
	}
}
 
void	bash_builtin(t_data data, char **path)
{
	int		i;
	char	*cmd;

	i = 0;
	cmd = "/";
	(void)path;
	cmd = ft_strjoin_no_free(cmd ,data.str[0]);
	while (path[i])
	{
		cmd = ft_strjoin_no_free(path[i], cmd);
		if (check_file2(cmd) == 1)
		{
			data.str[0] = cmd;
			execute(data);
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

void	built_env(t_env *envirement)
{
	t_env	*env;

	env = envirement;
	while (env)
	{
		if (env->name && env->path)
			printf("%s=%s\n", env->name, env->path);
		env = env->next;
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

int	its_n(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	built_echo(char **str)
{
	int	i;

	i = 0;
	if (!str[0])
	{
		printf("\n");
		return ;
	}
	if (its_n(str[i]) && (!ft_strncmp("-n", str[0], 2)))
	{
		i = 1;
		while (str[i] && (ft_strncmp("-n", str[i], 2) == 0) && its_n(str[i]))
			i++;
		while (str && str[i])
		{
			if (!ft_strcmp("$?", str[i]))
				str[i] = ft_strdup(ft_itoa(exit_val));
			printf(" %s", str[i++]);
		}
	}
	else
	{
		while (str[i])
		{
			if (!ft_strcmp("$?", str[i]))
				str[i] = ft_strdup(ft_itoa(exit_val));
			printf("%s ", str[i++]);
		}
		printf("\n");
	}
}

//echo $HOME"$HOME"'$"HOME"'

void	print_exit_error(char *str, int ex)
{
	
	printf("exit\nMinishel: exit: %s: numeric argument required\n", str);
	exit(ex);
}

int	ft_if_isalpha(char **str)
{
	int	i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[0][j]))
				print_exit_error(str[0], 255);
			j++;
		}
		i++;
	}
	if (i == 1)
		i = 0;
	return (i);
}

void	built_exit(char **str)
{
	int	i;
	int	num;

	i = 0;
	if (!str[0])
		exit(exit_val);
	if (ft_if_isalpha(str) > 0)
	{
		printf("exit\nMinishell: exit: too many arguments\n");
		return ;
	}
	num = ft_atoi(str[0]);
	exit_val = num % 256;
	printf("exit\n");
	exit(exit_val);
}

void	builtins(t_env **env, t_data *data)
{
	int		i;
	char	**path;

	path = get_binary_file(*env);
	i = 0;
	while (i < 1 && data[0].str)
	{
		if (!ft_strncmp("cd", data[i].str[0], 2))
			built_cd(*env, data->str[i + 1]);
		else if (!ft_strcmp("pwd", data[i].str[0]))
			built_pwd(*env);
		else if (!ft_strcmp("env", data[i].str[0]))
			built_env(*env);
		else if (!ft_strcmp("echo", data[i].str[0]))
			built_echo(data->str + 1);
		else if (!ft_strcmp("exit", data[i].str[0]))
			built_exit(data->str + 1);
		else if (!ft_strcmp("export", data[i].str[0]))
			built_export(*env, data->str + 1);
		else if (!ft_strcmp("unset", data[i].str[0]))
			built_unset(env, data->str + 1);
		else
			bash_builtin(data[i], path);
		i++;
	}
}

// salit ga3 builtins
