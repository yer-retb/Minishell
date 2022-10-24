/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/10/24 14:47:46 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	built_cd(t_env **envirement, char *str)
{
	char	*old_cwd;
	char	*buf;
	char	*pwd;
	t_env	*env;

	env = *envirement;
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
				env->path = ft_strdup(old_cwd);
			}
			if (ft_strncmp("PWD", env->name, 3) == 0)
			{
				free(env->path);
				env->path = ft_strdup(pwd);
			}
			env = env->next;
		}
	}
	else
		printf("Minishell: cd: %s: No such file or directory\n", str);
}

void	execute(t_data data)
{
	int	sig;

	if (fork() == 0)
	{
		sig = execve(data.str[0], data.str, NULL);
		if (sig == -1)
		{
			printf("command not found\n");
			exit(1);
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

void	built_pwd(t_env **envirement)
{
	char	*buf;
	t_env	*env;

	env = *envirement;
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
 
void	bash_builtin(t_data data)
{
	if (check_file2(data.str[0]) == 1)
		execute(data);
	
}

void	built_env(t_env **envirement)
{
	t_env	*env;

	env = *envirement;
	while (env)
	{
		if (env->path)
			printf("%s=%s\n", env->name, env->path);
		env = env->next;
	}
}

void	builtins(t_env **env, t_data *data)
{
	int	i;

//saat kayn wa7ed problem sghir mazal mafixito how f env wakha kanbedel f path dial PWD f env makaytbedelch 
//lprobem howa kanbedel f cpier dial env khassni nbedel f origine ms raah 3yi m3ah ila ma9aditihch kheliih tanji (Y)

	i = 0;
	while (i < 1)
	{
		if (!ft_strncmp("cd", data[i].str[0], 2))
			built_cd(env, data->str[i + 1]);
		if (!ft_strncmp("pwd", data[i].str[0], 3))
			built_pwd(env);
		if (!ft_strncmp("env", data[i].str[0], 3))
			built_env(env);
		else
			bash_builtin(data[i]);
		i++;
	}
}
