/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yer-retb <yer-retb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:52:48 by yer-retb          #+#    #+#             */
/*   Updated: 2022/11/06 17:28:22 by yer-retb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/include.h"

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
