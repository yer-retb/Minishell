/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:51:23 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/03 18:51:39 by yer-retb         ###   ########.fr       */
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
