/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:50:49 by enja              #+#    #+#             */
/*   Updated: 2022/11/03 18:54:40 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

int	ft_isalnum2(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9')
		|| (c == '_') || (c == '='))
		return (1);
	else
		return (0);
}

int	check_string(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(ft_isdigit(str[0]) || str[0] == '=')
			return (1);
		if (!ft_isalnum2(str[i]))
			return (1);
		i++;
	}
	return(0);
}

void	built_export(t_env *envirement, char **str)
{
	int		i;
	t_env	*env;
	char	**tmp;

	env = envirement;
	i = 0;
	if (!str[0])
	{
		while (env)
		{
			if (env->name && env->path)
				printf("declare -x %s=\"%s\"\n", env->name, env->path);
			else if(env->name)
				printf("declare -x %s\n", env->name);
			env = env->next;
		}
	}
	else 
	{
		while (str && str[i])
		{
			if (str[i][0] == '=')
			{
				printf("Minishell: export: not a valid identifier\n");
				exit_val = 1;
				i++;
				continue ;
			}
			tmp = ft_split(str[i], '=');
			if (check_string(tmp[0]))
			{
				printf("Minishell: export: not a valid identifier\n");
				exit_val = 1;
			}
			if (!tmp[1])
				tmp[1] = ft_strdup("");
			if (check_duplicate(env, tmp) && (!check_string(tmp[0])))
				list_at_back4(&env, init_env1(tmp));
			i++;
		}
	}
}

