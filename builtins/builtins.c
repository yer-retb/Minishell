/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/10/24 00:05:37 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	built_cd(char **env, char *str)
{
	int		i;
	char	*old_cwd;
	char	*buf;
	char	*pwd;
	char	*tmp;

	i = 0;
	buf = NULL;
	old_cwd = getcwd(buf, 0);
	if (chdir(str) == 0)
	{
		pwd = getcwd(buf, 0);
		while (env && env[i])
		{
			if (ft_strncmp("OLDPWD", env[i], 6) == 0)
			{
				tmp = ft_strjoin_no_free("OLDPWD=", old_cwd);
				env[i] = tmp;
			}
			if (ft_strncmp("PWD", env[i], 3) == 0)
			{
				tmp = ft_strjoin_no_free("PWD=", pwd);
				env[i] = tmp;
			}
			i++;
		}
	}
	else
		printf("Minishell: cd: %s: No such file or directory\n", str);
}

void    execute(t_data data)
{
	int sig;
    if (fork() == 0)
	{
        sig = execve(data.str[0], data.str, NULL);
		if(sig == -1)
		{
			printf("command not found\n");
			exit(1);
		}
	}
    while (waitpid(-1,NULL,0) == -1);
}

int	check_file2(char *str)
{
	int	fd;

	fd = access(str, F_OK);
	if (fd == -1)
		return(0);
	return (1);
}

void	built_pwd(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return ;
	while (env && env[i])
	{
		if (ft_strncmp("PWD", env[i], 3) == 0)
			printf("%s\n", env[i] + 4);
		i++;
	}
}

void	bash_builtin(t_data data)
{
	if (check_file2(data.str[0]) == 1)
		execute(data);
	
}

void	builtins(char **env, t_data *data)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (ft_strncmp("pwd", data[i].str[0], 3) == 0)
			built_pwd(env);
		if (ft_strncmp("cd", data[i].str[0], 2) == 0)
			built_cd(env, data->str[i + 1]);
		else
			bash_builtin(data[i]);
		i++;
	}
}
