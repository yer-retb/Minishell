/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 08:30:51 by enja              #+#    #+#             */
/*   Updated: 2022/10/23 12:50:31 by enja             ###   ########.fr       */
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

void	builtins(char **env, t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		if (ft_strncmp("pwd", data->str[i], 3) == 0)
			built_pwd(env);
		if (ft_strncmp("cd", data->str[i], 2) == 0)
			built_cd(env, data->str[i + 1]);
		i++;
	}
}
