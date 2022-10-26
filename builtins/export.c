/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 08:50:49 by enja              #+#    #+#             */
/*   Updated: 2022/10/26 12:55:59 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

// void	sort_env(t_env *env)
// {
// 	int		i;
// 	int		j;
// 	char	*tmp;

// 	tmp = env->name;
// 	{
		
// 	}
	
// }

void	built_export(t_env *envirement, char **str)
{
	int		i;
	t_env	*env;

	env = envirement;
	i = 0;
	if (!str[0])
	{
		// sort_env(env);
		while (env)
		{
			if (env->name && env->path)
				printf("declare -x %s=%s\n", env->name, env->path);
			env = env->next;
		}	
	}
}
