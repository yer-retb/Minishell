/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:51:23 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/19 02:56:21 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

void	cd_utils(t_env *envirement)
{
	t_env	*env;
	char	*pwd;

	env = envirement;
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
	g_b.exit_val = 0;
}

void	cd_last_utils(t_env *envirement, char *old_pwd, char *pwd)
{
	t_env	*env;

	env = envirement;
	while (env)
	{
		if (ft_strncmp("OLDPWD", env->name, 6) == 0)
		{
			free(env->path);
			env->path = old_pwd;
		}
		if (ft_strncmp("PWD", env->name, 3) == 0)
		{
			free(env->path);
			env->path = pwd;
		}
		env = env->next;
	}
}

void	built_cd(t_env *envirement, char *str)
{
	char	*old_pwd;
	char	*buf;
	char	*pwd;
	t_env	*env;

	env = envirement;
	buf = NULL;
	old_pwd = getcwd(buf, 0);
	if (!str || (str[0] == '~'))
		cd_utils(env);
	else if (chdir(str) == 0)
	{
		pwd = getcwd(buf, 0);
		cd_last_utils(env, old_pwd, pwd);
		g_b.exit_val = 0;
	}
	else
	{
		printf("Minishell: cd: %s: No such file or directory\n", str);
		g_b.is = 0;
		g_b.exit_val = 1;
	}
}
